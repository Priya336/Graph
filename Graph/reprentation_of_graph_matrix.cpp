#include<bits/stdc++.h>
using namespace std;
const int  N=1e+3;
int graph1[N][N];
int main(){
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
int a,b;
cin>>a>>b;
graph1[a][b]=1;
graph1[b][a]=1;
}
return 0;
}

//space Complixety=O(N^2)
//searching time=O(1)