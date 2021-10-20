#include <iostream>
using namespace std;

int res[1000];

int partition(int a[], int low, int high)
{
    int pivot=a[low];
    int idx=low+1;
    for(int i=low+1;i<=high;i++)
    {
        if(a[i]<pivot)
        {
            swap(a[idx], a[i]);
            idx++;
        }
    }
    swap(a[low], a[idx-1]);
    return idx-1;
}

void quick_sort(int a[], int low, int high, int level)
{
    if(low<high)
    {
        int pivot = partition(a, low, high);
        if(level==1)
        {
            res[pivot] = a[pivot];
        }
        if(level==2)
        {
            for(int i=low;i<=high;i++)
            {
                res[i] = a[i];
            }
        }
        quick_sort(a, low, pivot-1, level+1);
        quick_sort(a, pivot+1, high, level+1);
    }
}

void print(int a[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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
        for(int i=0;i<size;i++)
        {
            cin>>a[i];
        }
        quick_sort(a, 0, size-1, 1);
        print(res, size);
    }
    return 0;
}
