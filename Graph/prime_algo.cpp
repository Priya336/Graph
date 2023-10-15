#include <bits/stdc++.h>
using namespace std;
int mini(vector<int>key){
    int a=INT_MAX;
    int b;
 for(int i=0;i<key.size();i++){
    if(a>key[i]){
        a=key[i];
        b=i;
    }
    return b;
 }
}
void primes(vector<vector><int,int>>v,int n){
  vector<int>key(n+1,INT_MAX);
   vector<bool>mst(n+1,0);
   vector<int>parent(n+1,-1);
   key[0]=0;
  for(int i=1;i<n;i++){
   int u=mini(key);
   mst[u]=1;
   for(int j=0;j<n;j++){
    if(v[u][j] && mst[j]!=1 && v[u][j]<key[j]){
        key[j]=v[u][j];
        parent[j]=u;
    }
   }
  }

}

int main(){
int n; //vertex,edges
cin>>n;
vector<vector<int,int>>v;
for(int i=0;i<n;i++){
    for (int j=0;j<n;j++){
        cin>>v[i][j];
    }
}
primes(v,n);
return 0;
}