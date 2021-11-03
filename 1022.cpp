#include<iostream>
#include<string>
using namespace std;

//最长公共序列和最长公共子串不是一个问题

// longest common sequence
int lcs(string s, string t, int m, int n)
{
    // dp[i][j]表示长度为i的字符串和长度为j的字符串的lcs
    int dp[m+1][n+1] = {0,};
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            // 任何一个字符串长度为0，lcs结果为0
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
            }
            // 两个字符串最后一个字符相同
            else if(s[i-1] == t[j-1])
            {
                // 状态转移方程1
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                // 状态转移方程2
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
    }
    return dp[m][n];
}


int main() {
    // 测试次数
    int n_test;
    cin>>n_test;
    for(int i=0;i<n_test;i++)
    {
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        cout<<lcs(s1, s2, s1.size(), s2.size())<<endl;
    }
   return 0;
}