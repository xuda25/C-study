#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <memory>
#include <ostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iterator>

using namespace std;


class QueryResult
{
public:
    using line_no = vector<string>::size_type;
    friend ostream &print(ostream &os, const QueryResult &qr);
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}
    set<line_no>::iterator begin(shared_ptr<set<line_no>> p)    {return p->begin();}
    set<line_no>::iterator end(shared_ptr<set<line_no>> p) {return p->end();}
    shared_ptr<vector<string>> get_file(QueryResult q) {return q.file;}
private:
    string sought; //≤È—Øµ•¥ 
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " time(s) " << endl;
    for (auto num : *qr.lines)
         os << "line " << num + 1 << "\n" << endl;
}
#endif