/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// 三个哈希表 写的一坨
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> s1, s2, s3;
        string st1 = "qwertyuiop";
        string st2 = "asdfghjkl";
        string st3 = "zxcvbnm";
        for (char& c : st1)
            s1.insert(c);
        for (char& c : st2)
            s2.insert(c);
        for (char& c : st3)
            s3.insert(c);
        vector<string> res;
        bool next = false;

        for (int i = 0; i < words.size(); ++i)
        {   
            int size = words[i].size();
            next = false;
            
            if (!next)
            {
                for (int j = 0; j < size; ++j)
                {
                    if (s1.find(tolower(words[i][j])) == s1.end())
                        break;
                    else
                    {
                        if (j == size - 1)
                        {
                            res.push_back(words[i]);
                            next = true;
                        }
                    }
                }
            }

            if (!next)
            {
                for (int j = 0; j < size; ++j)
                {
                    if (s2.find(tolower(words[i][j])) == s2.end())
                        break;
                    else
                    {
                        if (j == size - 1)
                        {
                            res.push_back(words[i]);
                            next = true;
                        }
                    }
                }
            }

            if (!next)
            {
                for (int j = 0; j < size; ++j)
                {
                    if (s3.find(tolower(words[i][j])) == s3.end())
                        break;
                    else
                    {
                        if (j == size - 1)
                        {
                            res.push_back(words[i]);
                            next = true;
                        }
                    }
                }
            }
        }

        return res;
    }
};

// 转换
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        string rowIdx = "12210111011122000010020202";

        for (auto& word : words)
        {
            bool valid = true;
            int id = rowIdx[tolower(word[0]) - 'a'];

            for (int i = 1; i < word.size(); ++i)
            {
                if (rowIdx[tolower(word[i]) - 'a'] != id)
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
                res.emplace_back(word);
        }
        return res;
    }
};
// @lc code=end

