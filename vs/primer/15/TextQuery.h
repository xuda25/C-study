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
    TextQuery(ifstream &);  //���캯������һ���ļ�

    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> file; // vector ���ÿһ�е�����
    map<string, shared_ptr<set<line_no>>> wm; // map ��ÿ���� �� set����  ���� set��Ÿõ��ʳ��ֵ��к�
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;

    while (getline(is, text))
    {   
        // ����һ��
        file->push_back(text);
        int n = file->size() - 1;
        // ��ȡһ���е�ÿ����
        istringstream line(text);
        string word;
        // �ô��Ƿ���ֹ�  ���û���½���set ���кŴ���
        // ������ֹ� ֱ�Ӵ���
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
    // ����Ҳ��� ��������յ�
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    //���в���  ������
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

#endif