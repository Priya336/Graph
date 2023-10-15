#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];

int sum=0;
int dfs(int d,int vertex,int par=0)
{
    sum+=vertex;
    // Take acion on the vertex after entering the vertex
    for (int child : g[vertex])
    {
        // Take action on child before  entering the child
        if(child==par ||child==d ) continue;
        dfs(d,child,vertex);
        // Take action on the child after exixting child node
    }
    // Take action on the vertex before existing the vertex

    return sum;
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
   map<int,pair<int,int>>m;
  for(int i=1;i<=n;i++){
    for(int child:g[i]){
        if(child!=i){
      int a= dfs(child,i);
      sum=0;
      int b= dfs(i,child);
      sum=0;
     int c=a*b;
      m[c]={i,child};
     
    }
   
    }
  }

for(auto i:m){
    cout<<i.first<<"  "<<i.second.first<<" "<< i.second.second<<endl;
}
   return 0;
}

