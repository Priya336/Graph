//Given  Q queries Q<=10e5
// in each queries  given v
// print subtree sum of V & number of even number in a subtree
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
int sum[N];
int even[N];
int val[N];
void dfs(int vertex,int par=0)
{
    // Take acion on the vertex after entering the vertex
   sum[vertex]+=val[vertex-1];
   if(val[vertex]%2==0){
    even[vertex]++;
   }
    for (int child : g[vertex])
    {
        // Take action on child before  entering the child
        if(child==par) continue;
        dfs(child,vertex);
        sum[vertex]+=sum[child];   
        even[vertex]+=even[child];     // Take action on the child after exixting child node
    }
    // Take action on the vertex before existing the vertex
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
  
   for(int i=0;i<n;i++){
    cin>>val[i];
   }
    dfs(1);
    int q;
    cin>>q;
    while(q--){
        int v;
        cin>>v;
      cout<<sum[v]<<endl;
       cout<<even[v]<<endl;
    }

   return 0;
}

