#include<bits/stdc++.h>
using namespace std;
const int  N=1e+7;
vector<int>g[N];
int level[N];
vector<int>vis(N,0);
 int main(){
int n;
cin>>n;
for(int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}
   queue<int>q;
   q.push(1);
   level[1]=0;
   while(!q.empty()){
    int a=q.front();
    cout<<a<<" ";
    q.pop();
    vis[a]=1;
    for(int child:g[a]){
       if(vis[child]==0){
       q.push(child);
       level[child]=level[a]+1;
       }
    }
   } 
   for(int i=0;i<=n;i++){
    cout<<i<<" "<<level[i]<<endl;//shotest path of a node from a given node
   }
   return 0;
 }

 //BFS can be used to find the shotest path  when weight of all edges is equal