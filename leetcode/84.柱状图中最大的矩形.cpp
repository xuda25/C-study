/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */


// 双指针法

// 两个数组 一个存左边第一个小于的柱子下标  一个存右边第一个小于柱子的下标

// @lc code=start
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         vector<int> leftMin(heights.size());
//         vector<int> rightMin(heights.size());
//         leftMin[0] = -1;
//         rightMin[heights.size()-1] = heights.size();
//         int area = 0;

//         // 找左边第一个小于的柱子下标
//         for (int i = 1; i < heights.size(); ++i)
//         {   
//             int t = i - 1;
//             while (t >= 0 && heights[i] <= heights[t])
//             {
//                 t = leftMin[t];  // 这句精髓
//             }
//             leftMin[i] = t;
//         }

//         // 找右边第一个小于
//         for (int i = heights.size()-2; i >= 0; --i)
//         {
//             int t = i + 1;
//             while (t <= heights.size()-1 && heights[t] >= heights[i])
//             {
//                 t = rightMin[t];
//             }
//             rightMin[i] = t;
//         }

//         for (int i = 0; i < heights.size(); ++i)
//         {
//             int sum = heights[i] * (rightMin[i] - leftMin[i] - 1);
//             if (sum > area)
//                 area = sum;
//         }

//         return area;
//     }
// };

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        stack<int> st;
        st.push(0);
        // 防止单调数组
        heights.insert(heights.begin(), 0); // 防止递减
        heights.push_back(0);  // 防止递增
        
        for (int i = 0; i < heights.size(); ++i)
        {
            if (heights[i] > heights[st.top()])
                st.push(i);
            if (heights[i] == heights[st.top()])
            {   
                st.pop();
                st.push(i);
            }
            if (heights[i] < heights[st.top()])
            {   
                while (!st.empty() && heights[i] < heights[st.top()])
                {
                    int mid = st.top();
                    st.pop();

                    if (!st.empty())
                    {
                        int h = heights[mid];
                        int l = i - st.top() - 1;
                        area = max(area, h * l);
                    }
                }
            }
            st.push(i);
        }

        return area;
    }
};
// @lc code=end

