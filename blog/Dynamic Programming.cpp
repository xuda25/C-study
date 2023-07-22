#include <vector>
#include <iostream>
using namespace std;
// 1. 回溯
void backTracking(vector<int> choices, int state, int n, vector<int>res)
{   
    // 正好到n阶  方法+1
    if (state == n)
        res[0]++;

    for (int choice : choices)
    {
        if (state + choice > n)
            break;
        // 选择
        backTracking(choices, state + choice, n, res);
        // 回退
    }
}


int climbingStairsBacktrack(int n)
{
    vector<int> choices{1, 2}; // 上1阶或2阶
    int state = 0; // 从0阶开始
    vector<int> res{0}; //答案

    backTracking(choices, state, n, res);

    return res[0];
}

// 2. 分治

int dfs(int i)
{
    if (i == 1 || i == 2)
        return i;
    //dp[i] = dp[i-1] + dp[i-2]
    int count = dfs(i-1) + dfs(i-2);
    return count;
}

//搜索
int climbingStairsDfs(int n)
{
    return dfs(n);
}

// 3. 记忆化搜索

int dfs2(int i, vector<int>& mem)
{
    if (i == 1 || i == 2)
        return i;
    if (mem[i] != -1)
        return mem[i];
    int count = dfs2(i-1, mem) + dfs2(i-2, mem);
    mem[i] = count;
    return count;
}

int climbingStairDfs2(int n)
{   
    // mem记录子问题答案 避免重复计算
    vector<int> mem(n+1, -1);
    return dfs2(n, mem);
}

//4. 动态规划

int climbingStairDp(int n)
{
    if (n == 1 || n == 2)
        return n;

    vector<int> dp(n+1);

    for (int i = 3; i <= n; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    
    return dp[n];
}
//状态压缩
int climbingStairDp2(int n)
{
    if (n == 1 || n == 2)
        return n;

    int a = 1, b = 2;

    for (int i = 3; i <= n; ++i)
    {
        int tem = b;
        b = a + b;
        a = tem;
    }
    
    return b;
}

// 最优

int minCostClimbingStairDp(vector<int>& cost)
{
    //获取台阶数
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];
    
    vector<int> dp(n + 1);

    for (int i = 3; i <= n; ++i)
    {
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }
    
    return dp[n];
}

//状态压缩
int minCostClimbingStairDp2(vector<int>& cost)
{
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];

    int a = cost[1], b = cost[2];
    for (int i = 3; i <= n; ++i)
    {
        int tem = b;
        b = min(a, b) + cost[i];
        a = tem;
    }
    return b;
}


// 多重背包

void test_multi_pack()
{
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    vector<int> nums{2, 3, 2};
    int bagsize = 10;

    for (int i = 0; i < weight.size(); ++i)
        while (nums[i] != 1)
        {
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            --nums[i];
        }

    vector<int> dp(bagsize+1, 0);

    for (int i = 0; i < weight.size(); ++i)
        for (int j = bagsize; j >= weight[i]; --j)
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);

    cout << dp[bagsize] << endl;
}


int main()
{
    test_multi_pack();

}