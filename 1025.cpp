#include<iostream>
#include<climits>
using namespace std;

int func(int arr[], int n)
{
    int dp[n] = {1,};
    for(int i=0;i<n;i++)
    {
        dp[i] = 1;
    }
 
 
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++)
            if (arr[i] >= arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }
 
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(dp[i] > ans)
        {
            ans = dp[i];
        }
    }
    return ans;
}

int main() {
    // 测试次数
    int n_test;
    cin>>n_test;
    for(int i=0;i<n_test;i++)
    {
        int num;
        cin>>num;
        int arr[num];
        for(int j=0;j<num;j++)
        {
            cin>>arr[j];
        }
        cout<<func(arr, num)<<endl;
    }
   return 0;
}