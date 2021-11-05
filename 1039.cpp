#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main()
{
    int n_test;
    cin>>n_test;
    for(int i=0;i<n_test;i++)
    {
        int n_vertex;
        int n_edge;
        cin>>n_vertex;
        cin>>n_edge;
        int in_degree[n_vertex+1] = {0,};
        vector<vector<int>> adj(n_vertex+1, vector<int>(n_vertex+1, 0));
        vector<int> ans;
        queue<int> zero_degree;
        for(int j=0;j<n_edge;j++)
        {
            //u->v
            int u;
            int v;
            cin>>u;
            cin>>v;
            adj[u].push_back(v);
            in_degree[v]++;
        }
        for(int k=1;k<=n_vertex;k++)
        {
            if(in_degree[k]==0)
            {
                zero_degree.push(k);
            }
        }
        int num = 0;
        while(!zero_degree.empty())
        {
            int vertice = zero_degree.front();
            zero_degree.pop();
            ans.push_back(vertice);
            for(int i=0;i<adj[vertice].size();i++)
            {
                if(adj[vertice][i]!=0 &&--in_degree[adj[vertice][i]]==0)
                {
                    zero_degree.push(adj[vertice][i]);
                }
            }
            num++;
        }
        if(num!=n_vertex)
        {
            cout<<"0";
        }
        else
        {
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<" ";
            }
        }
        cout<<endl;
    }
}