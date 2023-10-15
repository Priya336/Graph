#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

void dfs(int vertex)
{
    // Take acion on the vertex after entering the vertex
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
    int k;
    cin>>k;
   while(k--){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
   }
   dfs(1);
   return 0;
}

