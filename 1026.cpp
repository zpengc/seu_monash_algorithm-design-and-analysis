#include<iostream>
using namespace std;


long long func(int arr[],int n, int k) {
    // dp[i][j]表示在第1到第i个数里面插入j个乘号得到的最大值
    long long dp[n+1][n+1];
    long long sum[n+1];
    sum[0]=0;
    // 存储累加和
    for(int i=1; i<=n;i++) 
    {
        sum[i] = sum[i-1] + arr[i];
    }
    for(int i=1; i<=n;i++) {
        dp[i][0] = sum[i];
    }
    for(int i=2;i<=n;++i)
        for(int j=1;j<i;++j)
            dp[i][j]=-1;
    
    // j表示乘法符号个数
    for(int j=1;j<=k;++j)
    {
        // 乘号可以放入的范围，[1,i]
        for(int i=j+1;i<=n;++i)
        {
            // 乘号放入k位置，k之前的位置已经被测试过了
            for(int k=j+1;k<=i;++k)
            {
                // dp[k-1][j-1]表示乘法插入后的左部分，sum[i] = sum[k-1]表示右部分
                dp[i][j]=max(dp[i][j],dp[k-1][j-1]*(sum[i]-sum[k-1]));
            }
        }
    }
    return dp[n][k];
}
    


int main() {
    int n_test;
    cin >> n_test;
    for(int i=0; i<n_test; i++){
        int n;
        int k;
        cin>>n;
        cin>>k;
        int arr[n+1];
        for(int j=1;j<=n;j++){
            cin >> arr[j];
        }
        cout<<func(arr,n,k)<<endl;
    }   
    return 0;
}