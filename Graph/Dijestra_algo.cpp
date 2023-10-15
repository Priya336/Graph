#include <bits/stdc++.h>
using namespace std;
const int INF =1e9+10;
const int N=1e7+10;
vector<pair<int,int>>v[N]; //vertex,weight
void dijestra(int source){
    vector<int>dis(N,INF);
     vector<int>vis(N,0);
     set<pair<int,int>>st; // it move the edge with smallest weight in front so thet it can be processed first
    st.insert({0,source});
    dis[source]=0;
    while(st.size()>0){
        auto node=*st.begin();
        int wt=node.first;
        int vertex=node.second;
        if(vis[vertex]==1)continue;
        vis[vertex]=1;
        st.erase(st.begin());
        for(auto child:v[vertex]){
            int child_v=child.first;
            int child_wt=child.second;
            if(dis[vertex]+child_wt<dis[child_v]){
                dis[child_v]=dis[vertex]+child_wt;
                st.insert({dis[child_v],child_v});
            }
            
        }
    }
}
int main(){
int n,m; //vertex,edges
cin>>n>>m;
for(int i=0;i<m;i++){
int x,y,wt;
v[x].push_back({y,wt});
}

dijestra(1);
return 0;
}

//complexity O(V+ElogV)