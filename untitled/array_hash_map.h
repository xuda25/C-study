//
// Created by xuda25 on 2023/2/25.
//

#ifndef UNTITLED_ARRAY_HASH_MAP_H
#define UNTITLED_ARRAY_HASH_MAP_H

#include <vector>
#include <string>
#include <iostream>


using namespace std;

class Entry
{
public:
    Entry(int key, string val) { this->key = key; this->val = val;}
    int key;
    string val;
};

class Hash_map
{
public:
    Hash_map() {bucket = vector<Entry*>(100);}
    // 哈希函数
    int hashFunction(int key)
    {
        int index = key % 100;
        return index;
    }
    // 查询操作
    string get(int key)
    {
        int index = hashFunction(key);
        Entry *pair = bucket[index];
        if (pair == nullptr)
            return nullptr;
        else
            return pair->val;
    }
    //添加操作
    void add(int key, string val)
    {
        Entry *pair = new Entry(key, val);
        int index = hashFunction(key);
        bucket[index] = pair;
    }
    // 删除操作
    void remove(int key)
    {
        int index = hashFunction(key);
        if (bucket[index] == nullptr)
            return;
        else
            bucket[index] = nullptr;
    }
    // 获取所有键值对
    vector<Entry*> entrySet()
    {
        vector<Entry*> ans;
        for (auto a : bucket)
        {
            if (a != nullptr)
                ans.push_back(a);
        }
        return ans;
    }
    // 获取所有键
    vector<int> getKey()
    {
        vector<int> key;
        for (auto a : bucket)
        {
            if (a != nullptr)
                key.push_back(a->key);
        }
        return key;
    }
    // 获取所有值
    vector<string> getVal()
    {
        vector<string> val;
        for (auto a : bucket)
        {
            if (a != nullptr)
                val.push_back(a->val);
        }
        return val;
    }
    // 打印哈希表
    void print()
    {
        for (auto a : bucket)
        {
            if (a != nullptr)
            {
                cout << a->key << " " << a->val << endl;
            }
        }
    }

private:
    vector<Entry*> bucket;
};


#endif //UNTITLED_ARRAY_HASH_MAP_H
