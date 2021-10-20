#include<iostream>
using namespace std;

// Longest Decreasing Subsequence problem
int LDS(int a[], int num)
{
    int lds[num];
    int max = 0;
    for (int i = 0; i < num; i++)
    {
        lds[i] = 1;
    }
    for (int i = 1; i < num; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] < a[j] && lds[i] < lds[j] + 1)
            {
                lds[i] = lds[j] + 1;
            }
        }
    }
    for (int i = 0; i < num; i++)
    {
        if (max < lds[i])
        {
            max = lds[i];
        }
    }
    return max;
}


int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        int a[num];
        for(int j=0;j<num;j++)
        {
            cin>>a[j];
        }
        cout<<LDS(a, num)<<endl;
    }   
    return 0;
}