/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
    vector<int> father = vector<int>(1001, 0);

    void init()
    {
        for (int i = 0; i < 1001; ++i)
            father[i] = i;
    }

    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    bool isSame(int u, int v)
    {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        father[v] = u;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        vector<int> res;
        
        for (int i = 0; i < edges.size(); ++i)
        {
            if (!isSame(edges[i][0], edges[i][1]))
            {   
                join(edges[i][0], edges[i][1]);
            }
            else
            {
                res.clear();
                res.push_back(edges[i][0]);
                res.push_back(edges[i][1]);
            }
        }
        return res;
    }
};
// @lc code=end

