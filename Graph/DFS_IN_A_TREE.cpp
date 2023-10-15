#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
vector<int>depth(N,0);
vector<int>height(N,0);
void dfs(int vertex,int par=0)
{
    // Take acion on the vertex after entering the vertex
    cout<<vertex<<endl;
    for (int child : g[vertex])
    {
        // Take action on child before  entering the child
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
        // Take action on the child after exixting child node
    }
    // Take action on the vertex before existing the vertex
}

int main(){
    int n;
    cin>>n;//no. of nodes
 for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
   dfs(1);
   for(int i=1;i<=n;i++){
    cout<<depth[i]<<" "<<height[i]<<endl;
   }
   return 0;
}

