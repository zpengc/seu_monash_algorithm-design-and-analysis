#include<iostream>
#include<cstring>
#include<string>

using namespace std;

//返回v[start]~v[end]这些数字所表示的数值
long nums(int v[],int start,int end){
    long num=v[start];
    for(int k=start+1;k<=end;k++){
        num = num*10+v[k];
    }
    return num;
}

long MaxMult(int v[], int bits,int k){
    // 原数字0~bits-1位中加入k个乘号所得表达式的最大值
    long dp[bits][k+1];
	memset(dp,0,sizeof(dp));
    for(int i=0; i<bits; i++)
        dp[i][0] = nums(v,0,i); //不划分就是前i个一起构成一个数

    //在v[0]~v[i]之间插入j个乘号
    for(int i=0; i<bits; i++)
    {
        //显然j的个数不能超过i
        for(int j=1; j<=k&&j<i+1; j++)
        //插入乘号的位置为k
            for(int k=0;k<i;k++)
                dp[i][j] = max(dp[i][j],dp[k][j-1]*nums(v,k+1,i));
    }
    return dp[bits-1][k];

}


int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int bits;
        int k;
        cin>>bits>>k;
        string s;
        cin >> s;
        int v[bits];
        for(int j=0;j<bits;j++)
            v[j] = s[j]-'0';
        cout << MaxMult(v,bits,k) << endl;
    }   
    return 0;
}