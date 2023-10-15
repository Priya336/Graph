#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
vector<int>current_cc;
vector<vector<int>>cc;
void dfs(int vertex)
{
    // Take acion on the vertex after entering the vertex
     current_cc.push_back(vertex);
    vis[vertex]=true;
    cout<<vertex<<endl;
   
    for (int child : g[vertex])
    {
        // Take action on child before  entering the child
        if(vis[child]==true) continue;
        dfs(child);
        // Take action on the child after exixting child node
    }
    // Take action on the vertex before existing the vertex
}

int main(){
    int n,e;
    cin>>n>>e;
   while(e--){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
   int count=0;
  
   for(int i=1;i<=n;i++){
   if( vis[i]==true) continue;
   current_cc.clear();
     dfs(i);
     cc.push_back(current_cc);
   
   }
   cout<<cc.size()<<endl;
   for(auto i:cc){
    for(auto j:i){
        cout<<j<<" ";
    }
    cout<<endl;
   }
   return 0;
}

