#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

// leetcode 4.
// https://leetcode.com/problems/median-of-two-sorted-arrays/

float func(int arr1[], int arr2[], int len_1, int len_2)
{
    int arr[len_1+len_2];
    int p = 0;
    int q = 0;
    int idx = 0;
    while(p<len_1 && q<len_2)
    {
        if(arr1[p] <= arr2[q])
        {
            arr[idx++] = arr1[p++]; 
        }
        else
        {
            arr[idx++] = arr2[q++];
        }
    }
    while(p<len_1)
    {
        arr[idx++] = arr1[p++];
    }
    while(q<len_2)
    {
        arr[idx++] = arr2[q++];
    }
    if( (len_1+len_2)%2!=0 )
    {
        return arr[(len_1+len_2)/2];
    }
    else
    {
        return ( arr[(len_1+len_2)/2] + arr[(len_1+len_2)/2-1] ) / 2.0;
    }
}

int main()
{
    int n_test;
    cin>>n_test;
    for(int i=0;i<n_test;i++)
    {
        int len_1;
        int len_2;
        cin>>len_1;
        cin>>len_2;
        int arr_1[len_1];
        int arr_2[len_2];
        for(int j=0;j<len_1;j++)
        {
            cin>>arr_1[j];
        }
        for(int j=0;j<len_2;j++)
        {
            cin>>arr_2[j];
        }
        // 输入的数据已经是有序了，不需要再排序
        // sort(arr_1, arr_1+len_1);
        // sort(arr_2, arr_2+len_2);
        // 题目bug，不需要保留小数
        cout<<func(arr_1, arr_2, len_1, len_2)<<endl;
    }
}