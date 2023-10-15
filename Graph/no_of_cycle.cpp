#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
bool isloopexist=false;
bool dfs(int vertex,int par)
{
    // Take acion on the vertex after entering the vertex
     
    vis[vertex]=true;
   
    for (int child : g[vertex])
    {
        // Take action on child before  entering the child
        if(vis[child]==true && child==par)continue;
        if(vis[child]==true ) return true;
        isloopexist|=dfs(child,vertex);
        // Take action on the child after exixting child node
    }
    // Take action on the vertex before existing the vertex
    return isloopexist;
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
  bool isloopexist=false;
   for(int i=1;i<=n;i++){
   if( vis[i]==true) continue;
     if(dfs(i,0)){
        isloopexist=true;
        break;
     }
    }
 cout<<isloopexist<<endl;
   return 0;
}

