#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "QueryResult.h"
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <sstream>
#include <set>

using namespace std;


class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &);  //构造函数接受一个文件

    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> file; // vector 存放每一行的数据
    map<string, shared_ptr<set<line_no>>> wm; // map 将每个词 与 set关联  其中 set存放该单词出现的行号
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;

    while (getline(is, text))
    {   
        // 存入一行
        file->push_back(text);
        int n = file->size() - 1;
        // 获取一行中的每个词
        istringstream line(text);
        string word;
        // 该词是否出现过  如果没有新建个set 将行号存入
        // 如果出现过 直接存入
        while (line >> word)
        {
            auto &lines = wm[word];  
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    // 如果找不到 返回这个空的
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    //进行查找  并返回
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

#endif