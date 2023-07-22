#include <iostream>
#include <vector>
using namespace std;

void test_multi_pack()

{
    vector<int> weight{1, 3, 4};
    vector<int> value{15, 20, 30};
    vector<int> nums{2, 3, 2};
    int bagsize = 10;

    for (int i = 0; i < nums.size(); ++i)
        while (nums[i] > 1)
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
    return 0;
}