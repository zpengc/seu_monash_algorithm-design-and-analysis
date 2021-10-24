#include<iostream>
#include<unordered_set>
using namespace std;



bool func(int arr[], int size, int target)
{
    unordered_set<int> s;
    for(int i=0;i<size;i++)
    {
        int remain = target - arr[i];
        if(s.find(remain)!=s.end())
        {
            return true;
        }
        else
        {
            s.insert(arr[i]);
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int size, target;
        cin>>size;
        cin>>target;
        int arr[size];
        for(int j=0;j<size;j++)
        {
            cin>>arr[j];
        }
        if(func(arr, size, target))
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}