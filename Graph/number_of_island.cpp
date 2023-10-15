// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
class Solution {

   void dfs(int i,int j,vector<vector<char>>&grid,vector<vector<int>>&vis  ){
        int n=grid.size();
        int m=grid[0].size();
     if(i<0 ||j<0) return ;
     if(i>=n ||j>=m) return ;
     if(vis[i][j]==1)return ;
     vis[i][j]=1;
     if(grid[i][j]=='0') return ;
     dfs(i+1,j,grid,vis);
     dfs(i-1,j,grid,vis);
     dfs(i,j+1,grid,vis);
     dfs(i,j-1,grid,vis);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
       
        int count=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&& vis[i][j]==0){
             dfs(i,j,grid,vis);
             count++;
                } 
            }
        }
       return count;
    }
};