#include<iostream>
#include<climits>
using namespace std;

// 数组长度为n，矩阵个数为n-1
int min_cost(int p[], int n)
{
    // m[i,j]表示矩阵matrix[i] matrix[i+1] ... matrix[j-1] matrix[j]的最小乘法代价
    int m[n][n];
    int i, j, k, L, q;
 
    // 一个矩阵，不存在最小乘法代价，为0
    // 索引从1到n-1，表示矩阵1-矩阵n-1
    for (i=1; i<n; i++)
        m[i][i] = 0;    
 
    //L表示连乘的矩阵个数，从2到n-1
    for (L=2; L<n; L++)
    {
        // n-gram的思想，以L为单位进行分割，最少分成1个，最多分成n-L+1个
        for (i=1; i<n-L+1; i++)
        {
            // j表示同一个连乘长度内的最后一个元素的下标
            j = i+L-1;
            m[i][j] = INT_MAX; 
 
            for (k=i; k<=j-1; k++)
            {
                // m[i][k]连乘后的结果矩阵：p[i-1]行，p[k]列
                // m[k+1][j]连乘后的结果矩阵：p[k]行，p[j]列
                // 两个结果矩阵连乘代价：p[i-1]*p[k]*p[j]
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;    
                }
            }
        }
    }
 
    return m[1][n-1];  
}

int main() {
    // 测试次数
    int n_test;
    cin>>n_test;
    for(int i=0;i<n_test;i++)
    {
        // 矩阵个数
        int n_matrix;
        cin>>n_matrix;
        // 存储每个矩阵的行数和列数，前一个矩阵的列数和后一个矩阵的行数重复，只存储1个，因此大小为2*n_matrix-(n_matrix-1)
        int chain[n_matrix+1];
        for(int i=0;i<n_matrix;i++)
        {
            // 行和列
            int row;
            cin>>row;
            int col;
            cin>>col;
            if(i==0)
            {
                chain[i] = row;
                chain[i+1] = col;
            }
            else
            {
                chain[i+1] = col;
            }
        }
        cout<<min_cost(chain, n_matrix+1)<<endl;
    }
   return 0;
}