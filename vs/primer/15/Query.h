#ifndef QUERY_H
#define QUERY_H
#include <string>
#include <memory>
#include <ostream>
#include <algorithm>
#include "QueryResult.h"
#include "TextQuery.h"

using namespace std;

// 这是一个抽象基类， 具体的查询类型 从中派生， 所有成员为private
class Query_base
{
    friend class Query;

protected:  
    using line_no = TextQuery::line_no;  //用于eval
    virtual ~Query_base() = default;

private:
    // eval返回当前Query的QueryResult
    virtual QueryResult eval(const TextQuery&) const = 0;
    // rep 表示查询的string
    virtual string rep() const = 0;
};

// 管理Query_base继承体系的接口
class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);

public:
    Query(const string&); // 构建新的WordQuery
    QueryResult eval(const TextQuery& t) const {return q->eval(t);}
    string rep() const {return q->rep();}

private:
    shared_ptr<Query_base> q;
    Query(shared_ptr<Query_base> query) : q(query) {} // 构造函数 不希望被乱用  设为private

};

// 输出运算符
ostream& operator<<(ofstream& os, const Query& query)
{
    return os << query.rep();
}

class WordQuery : public Query_base
{
    friend class Query;
    WordQuery(const string& s) : query_word(s) {}
    // 覆盖虚函数
    QueryResult eval(const TextQuery& t) const {return t.query(query_word);}
    string rep() const {return query_word;}
    string query_word; // 要查找的单词
};

inline Query::Query(const string& s) : q(new WordQuery(s)) {}

class NotQuery : public Query_base
{
    friend Query operator~(const Query&);
    NotQuery(const Query& q) : query(q) {}
    string rep() const {return "~(" + query.rep() + ")";}
    QueryResult eval(const TextQuery&) const; 
    Query query;
};

inline Query operator~(const Query& operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query& l, const Query& r, string s) : lhs(l), rhs(r), opSym(s) {}
    string rep() const {return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";}
    Query lhs, rhs; // 运算对象
    string opSym;  //运算符
};


class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&") {}
    QueryResult eval(const TextQuery&) const;
};

inline Query operator&(const Query& lhs, const Query& rhs)
{
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "|") {}
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query& lhs, const Query& rhs)
{
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& text) const
{
    // 进行虚调用
    // 调用eval 返回每个QueryResult
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery& text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}


QueryResult NotQuery::eval(const TextQuery& text) const
{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
};
#endif