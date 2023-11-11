/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */


//  超时了
// @lc code=start
// class Solution {
// public:
//     bool IsHeterotopic(string s1, string s2)
//     {
//         vector<int> nums(26, 0);

//         for (int i = 0; i < s1.size(); ++i)
//             ++nums[s1[i]-'a'];
        
//         for (int i = 0; i < s2.size(); ++i)
//             --nums[s2[i]-'a'];

//         for (int i = 0; i < 26; ++i)
//             if (nums[i] != 0)
//                 return false;

//         return true;
//     }

//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<bool> visited(strs.size(), false);
//         vector<vector<string>> res;
//         for (int i = 0; i < strs.size(); ++i)
//         {
//             if (visited[i])
//                 continue;

//             string tmp = strs[i];
//             vector<string> path;
//             path.push_back(tmp);

//             for (int j = i + 1; j < strs.size(); ++j)
//             {   
//                 if (!visited[j] && IsHeterotopic(tmp, strs[j]))
//                 {
//                     visited[j] = true;
//                     path.push_back(strs[j]);
//                 }
//             }

//             res.push_back(path);
//         }

//         return res;
//     }
// };

// O(n^3) O(n)

// 字母异位词排序后  一样  用排序后的词作为键

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto str : strs)
        {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            mp[tmp].emplace_back(str);
        }

        vector<vector<string>> res;

        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            res.push_back(it->second);
        }

        return res;
    }
};
// O(NKlogK)  O(Nk)
// @lc code=end

