#include<iostream>
#include<climits>
using namespace std;

// 无限背包问题，钢材相当于背包，每个售卖的小段钢材相当于物品，假设每种售卖的小段钢材是没有数量限制的
// dp数组申请为1维数组，2维数组显示内存不足错误
int cut_rod(int prices[], int sizes[], int capacity, int n)
{
    // 局部变量赋值为0，否则系统赋随机值
    int dp[capacity+1] = {0,};
    // 背包容量为0
    dp[0] = 0;
    // 从小到大遍历所有背包容量
    for(int i=1;i<=capacity;i++)
    {
        // 遍历所有物品
        for(int j=0;j<n;j++)
        {
            // 容量允许的情况下
            if(sizes[j]<=i)
            {
                dp[i] = max(dp[i], dp[i-sizes[j]] + prices[j]);
            }
        }
    }
    return dp[capacity];
}

int main() {
    // 测试次数
    int n_test;
    cin>>n_test;
    for(int i=0;i<n_test;i++)
    {
        // 钢条长度
        int capacity;
        cin>>capacity;
        // 价目表价格种类数
        int n_types;
        cin>>n_types;
        int prices[n_types];
        int sizes[n_types];
        for(int j=0;j<n_types;j++)
        {
            cin>>sizes[j];
            cin>>prices[j];
        }
        cout<<cut_rod(prices, sizes, capacity, n_types)<<endl;
    }
   return 0;
}