#include <iostream>
#include<limits.h>
using namespace std;

int f(int a[], int size)
{
    int first, second;
    if (size < 2)
    {
        return 0;
    }
    first = second = INT_MAX;
    for(int i=0;i<size;i++)
    {
        if(a[i]<first)
        {
            second = first;
            first = a[i];
        }
        else if(a[i]<second && a[i]!=first)
        {
            second = a[i];
        }
    }
    return second;
}


int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int size;
        cin>>size;
        int a[size];
        for(int j=0; j<size; j++)
            cin >> a[j];
        cout<<f(a, size)<<endl;
    }
    return 0;
}