// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

// Return the modified image after performing the flood fill.

class Solution {

void dfs(int i,int j,vector<vector<int>> &image ,int color,int initial){
    int n=image.size();
    int m=image[0].size();
if(i<0 || j<0)return;
if(i>=n || j>=m) return;
if(image[i][j]!=initial)return;
image[i][j]=color;
dfs(i-1,j,image,color,initial);
dfs(i+1,j,image,color,initial);
dfs(i,j-1,image,color,initial);
dfs(i,j+1,image,color,initial);
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int i=image[sr][sc];
        if(i!=color){
        dfs(sr,sc,image,color,i);
    }
    return image;
    }
};


//visited matrix is not used in this cas as the colour is changed so the function is return if the function is run for parent
//element again but in all other case the visited matrix should be used
