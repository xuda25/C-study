/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */


// 莫名其妙写成了暴力搜索   5555  想用单调栈的

// @lc code=start
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans(nums1.size(), -1);

//         for (int i = 0; i < nums1.size(); ++i)
//         {   
//             int index = getIndex(nums1[i], nums2);  // 获取1在nums2的位置
//             for (int j = index+1; j < nums2.size(); ++j)
//             {   
//                 if (nums2[j] > nums1[i])
//                 {   
//                     ans[i] = nums2[j];
//                     break;
//                 }
//             }
//         }

//         return ans;
//     }

//     int getIndex(int num, vector<int>nums2)
//     {
//         int index = 0;
//         for (int i = 0; i < nums2.size(); ++i)
//             if (nums2[i] == num)
//             {
//                 index = i;
//                 break;
//             }

//         return index;
//     }
// };


// 单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        if (nums1.size() == 0)
            return res;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); ++i)
            umap[nums1[i]] = i;
        
        stack<int> st;
        st.push(0);

        for (int i = 1; i < nums2.size(); ++i)
        {   
            if (nums2[i] <= nums2[st.top()])
                st.push(i);
            else
            {
                while (!st.empty() && nums2[i] > nums2[st.top()])
                {
                    if (umap.count(nums2[st.top()]))
                    {
                        int index = umap[nums2[st.top()]];
                        res[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

