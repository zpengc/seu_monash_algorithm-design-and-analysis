#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int func(int n_egg, int n_floor)
{
    vector<vector<int>> dp(n_floor+1, vector<int>(n_egg+1, 0));
        int m = 0;
        while (dp[m][n_egg] < n_floor) {
            m++;
            for (int k = 1; k <= n_egg; ++k)
                dp[m][k] = dp[m - 1][k - 1] + dp[m - 1][k] + 1;
        }
        return m;
}

int main()
{
    int n_test;
    cin>>n_test;
    for(int i=0;i<n_test;i++)
    {
        int n_egg;
        int n_floor;
        cin>>n_egg;
        cin>>n_floor;
        cout<<func(n_egg, n_floor)<<endl;
    }
}