/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        
        unordered_map<string, int> visitedMap;
        visitedMap.insert(pair<string, int>(beginWord, 1));

        queue<string> que;
        que.push(beginWord);

        while (!que.empty())
        {
            string word = que.front();
            que.pop();

            for (int i = 0; i < word.size(); ++i)
            {
                string newWord = word;
                int step = visitedMap[newWord];
                for (int j = 0; j < 26; ++j)
                {
                    newWord[i] = j + 'a';

                    if (newWord == endWord)
                        return step+1;
                    if (wordSet.find(newWord) != wordSet.end() && visitedMap.find(newWord) == visitedMap.end())
                    {
                        visitedMap.insert(pair<string, int>(newWord, step+1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};
// @lc code=end

