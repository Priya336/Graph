#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
vector<int>depth(N,0);
vector<int>height(N,0);
void dfs(int vertex,int par=0)
{
    // Take acion on the vertex after entering the vertex
    for (int child : g[vertex])
    {
        // Take action on child before  entering the child
        if(child==par) continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
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
   int max_depth=-1;
   int max_depth_node;
   for(int i=1;i<=n;i++){
    if(depth[i]>max_depth){
        max_depth=depth[i];
        max_depth_node=i;
    }
    depth[i]=0;
   }
   dfs(max_depth_node);
   max_depth=-1;
    for(int i=1;i<=n;i++){
    if(depth[i]>max_depth){
        max_depth=depth[i];
    }
   }
      cout<<max_depth<<endl;
   return 0;
}

