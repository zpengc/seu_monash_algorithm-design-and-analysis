#include<iostream>
using namespace std;

void binary_search(int a[], int low, int high, int target)
{
    int temp = a[(low+high)/2];
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(a[mid]==target)
        {
            cout<<"success, father is "<<temp<<endl;
            return;
        }
        else if(a[mid]>target)
        {
            high = mid-1;
            temp = a[mid];
        }
        else
        {
            low = mid+1;
            temp = a[mid];
        }
    }
    cout<<"not found, father is "<<temp<<endl;
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int size;
        cin>>size;
        int target;
        cin>>target;
        int a[size];
        for(int j=0;j<size;j++)
        {
            cin>>a[j];
        }
        binary_search(a, 0, size-1, target);
    }   
    return 0;
}