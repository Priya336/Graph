#include<bits/stdc++.h>
using namespace std;
const int INF=1e7+10;
const int N=510;
int dis[N][N];


void print(int v){
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            if(dis[i][j]==INF){
                cout<<"I"<<" ";
            }
            else{
            cout<<dis[i][j]<<" ";
            }
        }
    }
}
void Warshall(int V){
    for(int k=1;k<=V;k++){
    for(int i=1;i<=V;i++){
        for(int j=1;j<=V;j++){
            if(dis[i][k]!=INF && dis[k][j] !=INF){
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
        }
    }
    }
}

int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                dis[i][j]=0;
            }
            else{
                dis[i][j]=INF;
            }
        }

    }
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,z;//vertex,vertex,wt
        cin>>x>>y>>z;
        dis[x][y]=z;
    }
    
    Warshall(n);
    print(n);
    return 0;
}