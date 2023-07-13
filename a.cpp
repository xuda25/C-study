#include <iostream>
#include <vector>
using namespace std;

void test_2_wei_bag_problem()
{
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    int bagsize = 4;

    vector<vector<int>> dp(weight.size(), vector<int>(bagsize+1, 0));
    // 初始化
    for (int i = weight[0]; i <= bagsize; ++i)
        dp[0][i] = value[0];

    for (int i = 1; i < weight.size(); ++i)
        for (int j = 1; j <= bagsize; ++j)
            if (weight[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i]);

    
    cout << dp[weight.size()-1][bagsize];
}

void test_1_wei_bag_problem()
{
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    int bagsize = 4;
    
    vector<int> dp(bagsize+1, 0);
    for (int i = 0; i < weight.size(); ++i)
        for (int j = bagsize; j >= weight[i]; --j)
            dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
    
    cout << dp[bagsize];
}

void test_CompletePack()
{
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    int bagsize = 4;

    vector<int> dp(bagsize+1, 0);

    for (int i = 0; i < weight.size(); ++i)
        for (int j = weight[i]; j <= bagsize; ++j)
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    
    cout << dp[bagsize];
}

void test_CompletePack2()
{
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    int bagsize = 4;

    vector<int> dp(bagsize+1, 0);

    for (int j = 0; j <= bagsize; ++j)
        for (int i = 0; i < weight.size(); ++i)
            if (j - weight[i] >= 0)
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    
    cout << dp[bagsize];
}

int main()
{
    test_CompletePack2();
    return 0;
}