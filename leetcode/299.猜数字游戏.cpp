/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> mp;
        vector<bool> visited(guess.size(), false);


        for (auto c : secret)
            ++mp[c];

        for (int i = 0; i < guess.size(); ++i)
        {
            if (guess[i] == secret[i])
            {
                ++bulls;
                --mp[guess[i]];
                visited[i] = true;
            }
        }

        for (int i = 0; i < guess.size(); ++i)
        {
            if (!visited[i] && guess[i] != secret[i] && mp.find(guess[i]) != mp.end() && mp[guess[i]] != 0)
            {
                ++cows;
                --mp[guess[i]];
            }
        }

        string res;
        res += to_string(bulls);
        res += "A";
        res += to_string(cows);
        res += "B";

        return res;
    }
};
// @lc code=end

