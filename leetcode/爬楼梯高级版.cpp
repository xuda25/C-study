//改为：一步一个台阶，两个台阶，三个台阶，.......，直到 m个台阶。问有多少种不同的方法可以爬到楼顶呢？
// 动态规划四部曲
// 1. dp[i] 表示爬上i级台阶有dp[i]种方法
// 2. 初值 dp[0] = 1
// 3. 方程 dp[i] += dp[i-j]
// 4. 先背包 再方法

int climb(int n)
{
    vector<int> dp(n+1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <=m; ++j)
            if (i >= j)
                dp[i] += dp[i-j];

    return dp[n];
}