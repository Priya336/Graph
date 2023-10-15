#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int subtree_sum[N];
int sum=0;
int v[N];
int M=1e+7l;
void dfs(int vertex,int par=0)
{
   subtree_sum[vertex]+=v[vertex];
    // Take acion on the vertex after entering the vertex
    for (int child : g[vertex])
    {
        // Take action on child before  entering the child
        if(child==par) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
        // Take action on the child after exixting child node
    }
    // Take action on the vertex before existing the vertex

   
}

int main(){
    int n;
    cin>>n;//no. of nodes
 for(int i=0;i<n-1;i++){
    int a,b,c;
    cin>>a>>b>>c;
    g[a].push_back(b);
    g[b].push_back(a);
   
   }
   dfs(1);
   long long ans=0;
for(int i=2;i<N;i++){
    int part1=subtree_sum[i];
     int part2=subtree_sum[1]-subtree_sum[i];
     ans=max(ans,(part1*1ll*part2)%M);
}
cout<<ans<<endl;
   return 0;
}

