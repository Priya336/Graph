#include<bits/stdc++.h>
using namespace std;
const int N=1e+3;
vector<int>graph[N];
vector<pair<int,int>>v[N];//for storing weighted garph

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    //finding the vertiex connected to particular edge 
    int a;
    cin>>a;
    for(int c:graph[a]){
        cout<<c<<endl;
    }
    //printing weight of a graph
    for(pair<int,int> c:v[a]){
       cout<<c.first<<" "<<c.second<<endl;
    }
    return 0;
}

//advantage -Space complexity=O(M+N)
//disadvatage - searching time=O(N)