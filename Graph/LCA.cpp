#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
vector<int>p(N);
void dfs(int vertex,int par=-1)
{
    // Take acion on the vertex after entering the vertex
     p[vertex]=par;
       
    for (int child : g[vertex])
    {
        // Take action on child before  entering the child
        if(child==par) continue;
        dfs(child,vertex);
    // Take action on the child after exixting child node
    }
    // Take action on the vertex before existing the vertex
}
vector<int>path(int v){
    vector<int>ans;
    while(v!=-1){
        ans.push_back(v);
        v=p[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
     cout<<p[i]<<endl;
   }
// int x,y;
// cin>>x>>y;
// vector<int>p1=path(x);
// vector<int>p2=path(y);
// int min_l=min(p1.size(),p2.size());
// int lca=-1;
// for(int i=0;i<min_l;i++){
//     if(p1[i]==p2[i]){
//         lca=p1[i];
//     }
//     else{
//         break;
//     }
// }
// cout<<lca<<endl;
   return 0;
}

