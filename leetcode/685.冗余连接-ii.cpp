/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
public:
    int n = 1001;
    vector<int> father = vector<int>(n, 0);

    void init()
    {
        for (int i = 0; i < n; ++i)
            father[i] = i;
    }

    int find(int u)
    {
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    bool same(int u, int v)
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

    bool isTreeAfterRemoveEdge(vector<vector<int>>& edges, int deleteEdge)
    {
        for (int i = 0; i < edges.size(); ++i)
        {
            if (i == deleteEdge)
                continue;
            if (same(edges[i][0], edges[i][1]))
                return false;
            join (edges[i][0], edges[i][1]);
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 寻找入度为2的节点的边
        int n = edges.size();
        int inDegree[n] = {0};

        for (int i = 0; i < n; ++i)
            inDegree[edges[i][1]]++;

        vector<int> vec;
        for (int i = n-1; i >= 0; i--)
            if (inDegree[i] == 2)
                vec.push_back(i);

        // 此时只有两种可能
        // 1. 有入度为2的  删掉一条
        // 2. 没有入度为2  必有有向环

        if (vec.size() > 0)
        {

        }

    }
};
// @lc code=end

