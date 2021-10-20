#include <iostream>
using namespace std;

void heapify(int a[], int size, int idx)
{
    int smallest = idx;
    int left = idx*2+1;
    int right = idx*2+2;
    // 优先向左子树调整
    if(left<size && a[left]<a[smallest])
    {
        smallest = left;
    }
    if(right<size && a[right]<a[smallest])
    {
        smallest = right;
    }
    if(smallest!=idx)
    {
        swap(a[idx], a[smallest]);
        // 继续调整以孩子为根节点的子树
        heapify(a, size, smallest);
    }
    
}

void heap_sort(int a[], int size)
{
    // 建堆
    for(int i=size/2-1;i>=0;i--)
    {
        heapify(a, size, i);     
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
        heap_sort(a, size);
        print(a, size);
    }
    return 0;
}
