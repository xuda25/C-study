/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start

// 方法1
// 1.找到每个字母最远出现位置
// 2.遍历数组， 找到当前已经遍历字母的的最远距离， 当遍历到的下标等于该最远距离时，说明达到要求
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 1.
        int hash[27] = {0};
        for (int i = 0; i < s.size(); ++i)
            hash[s[i] - 'a'] = i;

        // 2.
        vector<int> result;
        int left = 0;
        int right = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            right = max(right, hash[s[i] - 'a']);
            if (right == i)
            {
                result.push_back(right - left + 1);
                left = right + 1;
            }
        }

        return result;
    }
};

//方法2
// class Solution {
// public:
//     static bool cmp(vector<int> &a, vector<int> &b) {
//         return a[0] < b[0];
//     }
//     // 记录每个字母出现的区间
//     vector<vector<int>> countLabels(string s) {
//         vector<vector<int>> hash(26, vector<int>(2, INT_MIN));
//         vector<vector<int>> hash_filter;
//         for (int i = 0; i < s.size(); ++i) {
//             if (hash[s[i] - 'a'][0] == INT_MIN) {
//                 hash[s[i] - 'a'][0] = i;
//             }
//             hash[s[i] - 'a'][1] = i;
//         }
//         // 去除字符串中未出现的字母所占用区间
//         for (int i = 0; i < hash.size(); ++i) {
//             if (hash[i][0] != INT_MIN) {
//                 hash_filter.push_back(hash[i]);
//             }
//         }
//         return hash_filter;
//     }
//     vector<int> partitionLabels(string s) {
//         vector<int> res;
//         // 这一步得到的 hash 即为无重叠区间题意中的输入样例格式：区间列表
//         // 只不过现在我们要求的是区间分割点
//         vector<vector<int>> hash = countLabels(s);
//         // 按照左边界从小到大排序
//         sort(hash.begin(), hash.end(), cmp);
//         // 记录最大右边界
//         int rightBoard = hash[0][1];
//         int leftBoard = 0;
//         for (int i = 1; i < hash.size(); ++i) {
//             // 由于字符串一定能分割，因此,
//             // 一旦下一区间左边界大于当前右边界，即可认为出现分割点
//             if (hash[i][0] > rightBoard) {
//                 res.push_back(rightBoard - leftBoard + 1);
//                 leftBoard = hash[i][0];
//             }
//             rightBoard = max(rightBoard, hash[i][1]);
//         }
//         // 最右端
//         res.push_back(rightBoard - leftBoard + 1);
//         return res;
//     }
// };
// @lc code=end

