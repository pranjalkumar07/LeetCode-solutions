class Solution {
private:
    void dfs(vector<vector<int>>& rooms, vector<int>&vis,int node){
        vis[node]=1;
        for(int key : rooms[node]){
            if(!vis[key]){
                dfs(rooms,vis,key);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        // initially only room 0 can be accessed
        dfs(rooms,vis,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};