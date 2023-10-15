#include<bits/stdc++.h>
using namespace std;
const int  N=1e+7;
vector<pair<int,int>>g[N];
vector<int>level(N,INFINITY);
int n,m;
int bfs(int vertex){
deque<int>q;
q.push_back(vertex);
level[vertex]=1;
while(!q.empty()){
    int curr_v=q.front();
    q.pop_front();
    for(auto i: g[curr_v]){
        int child_v=i.first;
        int wt=i.second;
        if(level[curr_v]+wt<level[child_v]){
            level[child_v]=level[curr_v]+wt;
        }
        if(wt==1){
            q.push_back(child_v);
        }
        else{
            q.push_front(child_v);
        }
    }
    return (level[n]==INFINITY)? -1: level[n];
}


}
 int main(){

cin>>n>>m;
for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back({b,0});
    g[b].push_back({a,1});
}
  int a=bfs(1);
  cout<<a;
 
 }

 //BFS can be used to find the shotest path  when weight of all edges is equal