#include<iostream>
#include<vector>
using namespace std;

int func(int weight[], int profit[], int capacity, int n_gem)
{
    vector<vector<int>> dp(n_gem+1, vector<int>(capacity+1, -1));
    for(int i=0;i<=n_gem;i++)
    {
        dp[i][0] = 0;
    }
    
    for (int i=1;i<=n_gem;i++)
    {
        for (int j=capacity;j>=1;j--)
        {
            // weight, profit数组下标从0开始，所以i-1
            int curr_weight = weight[i - 1];
            int curr_profit = profit[i - 1];
            if (j >= curr_weight && dp[i - 1][j - curr_weight] != -1)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - curr_weight] + curr_profit);
            }
            else 
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if(dp[n_gem][capacity] == -1)
    {
        return 0;
    }
    return dp[n_gem][capacity];    
}

int main() {
    // 测试次数
    int n_test;
    cin>>n_test;
    for(int i=0;i<n_test;i++)
    {
        // 宝石个数
        int n_gem;
        cin>>n_gem;
        // 背包容量
        int bag_capacity;
        cin>>bag_capacity;
        int weight[n_gem];
        int profit[n_gem];
        for(int i=0;i<n_gem;i++)
        {
            // 宝石大小
            int weight_gem;
            cin>>weight_gem;
            // 宝石价值
            int profit_gem;
            cin>>profit_gem;
            weight[i] = weight_gem;
            profit[i] = profit_gem;
        }
        cout<<func(weight, profit, bag_capacity, n_gem)<<endl;
    }
   return 0;
}