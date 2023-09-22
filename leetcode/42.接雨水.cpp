/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start

// 暴力  超时
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int sum = 0;

//         for (int i = 0; i < height.size(); ++i)
//         {
//             if (i == 0 || i == height.size() - 1)
//                 continue;
            
//             int lHeight = height[i];  // i左边最高
//             int rHeight = height[i];  // i右边最高

//             for (int j = 0; j < i; ++j)
//             {
//                 if (height[j] > lHeight)
//                     lHeight = height[j];
//             }

//             for (int r = i + 1; r < height.size(); ++r)
//             {
//                 if (height[r] > rHeight)
//                     rHeight = height[r];
//             }

//             int h = min(lHeight, rHeight) - height[i];
            
//             if (h > 0)
//                 sum += h;
//         }
//         return sum;
//     }
// };


// 改进

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         vector<int> maxLeft(height.size(), 0);
//         vector<int> maxRight(height.size(), 0);

//         maxLeft[0] = height[0];
//         maxRight[height.size()-1] = height[height.size()-1];

//         for (int i = 1; i < height.size(); ++i)
//             maxLeft[i] = max(height[i], maxLeft[i-1]);
        
//         for (int i = height.size()-2; i >=0; --i)
//             maxRight[i] = max(height[i], maxRight[i+1]);

//         int sum = 0;

//         for (int i = 0; i < height.size(); ++i)
//         {
//             int h = min(maxLeft[i], maxRight[i]) - height[i];
//             if (h > 0)
//                 sum += h;
//         }

//         return sum;
//     }
// };

// 单调栈

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<int> st;
        st.push(0);

        for (int i = 1; i < height.size(); ++i)
        {
            if (height[i] < height[st.top()])
                st.push(i);
            if (height[i] == height[st.top()])
            {
                st.pop();
                st.push(i);
            }
            if (height[i] > height[st.top()])
            {
                while (!st.empty() && height[i] > height[st.top()])
                {
                    int mid = st.top();
                    st.pop();

                    if (!st.empty())
                    {
                        int w = i - st.top() - 1;
                        int h = min(height[st.top()], height[i]) - height[mid];

                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};
// @lc code=end

