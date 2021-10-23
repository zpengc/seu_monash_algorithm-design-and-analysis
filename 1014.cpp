#include<iostream>
#include<climits>
using namespace std;

int func(int a[], int size)
{
    int res = INT_MIN;
    int max_end_here = 0;
    for(int i=0;i<size;i++)
    {
        max_end_here += a[i];
        if(max_end_here > res)
        {
            res = max_end_here;
        }
        if(max_end_here < 0)
        {
            max_end_here = 0;
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int size;
        cin>>size;
        int arr[size];
        for(int j=0;j<size;j++)
        {
            cin>>arr[j];
        }
        cout<<func(arr, size)<<endl;
    }
    return 0;
}