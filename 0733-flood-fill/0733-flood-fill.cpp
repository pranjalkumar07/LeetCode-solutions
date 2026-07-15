class Solution {
public:
    void trav(vector<vector<int>>& image,int i,int j,int newColor,int oldColor){
        if(i>=image.size()|| j>=image[0].size() || i<0 || j<0 || image[i][j]==newColor || image[i][j]!=oldColor){
            return;
        }
        image[i][j]=newColor;

        trav(image,i-1,j,newColor,oldColor);
        trav(image,i,j+1,newColor,oldColor);
        trav(image,i+1,j,newColor,oldColor);
        trav(image,i,j-1,newColor,oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        trav(image,sr,sc,color,image[sr][sc]);
        return image;
    }
};