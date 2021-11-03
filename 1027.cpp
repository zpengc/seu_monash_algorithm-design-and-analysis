#include<iostream>
#include<algorithm>
using namespace std;

struct activity
{
  int start_time;
  int finish_time;
  int weight;  
};

bool compare(activity a1, activity a2)
{
    return (a1.finish_time != a2.finish_time) ? (a1.finish_time < a2.finish_time) : (a1.start_time < a2.start_time);
}


int get_last_activity(activity arr[], int idx)
{
    // arr为根据结束时间排序后的数组
    // 从后往前找
    for(int i=idx-1;i>=0;i--)
    {
        if(arr[i].finish_time <= arr[idx].start_time)
        {
            return i;
        }
    }
    return -1;
}

int choose(activity arr[], int n)
{
    int dp[n+1];
    dp[1] = arr[0].weight;
    for(int i=2;i<=n;i++)
    {
        int sum = arr[i-1].weight;
        int idx = get_last_activity(arr, i-1);
        if(idx!=-1)
        {
            sum += dp[idx+1];
        }
        dp[i] = max(sum, dp[i-1]);
    }
    return dp[n];
}

int main() {
    // 测试次数
    int n_test;
    cin>>n_test;
    for(int i=0;i<n_test;i++)
    {
        // 活动个数
        int n_activity;
        cin>>n_activity;
        activity arr[n_activity];
        for(int j=0;j<n_activity;j++)
        {
            activity temp;
            cin>>temp.start_time;
            cin>>temp.finish_time;
            cin>>temp.weight;
            arr[j] = temp;
        }
        sort(arr, arr+n_activity, compare);
        cout<<choose(arr, n_activity)<<endl;
    }
   return 0;
}