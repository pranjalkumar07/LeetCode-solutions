class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];// coz node is from 1 to4 in the example nodes are starting from 1 not from 0 
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,1e9);// here also same logic apply coz node is starting from 1 so we have to take n+1;
        queue<pair<int,int>>q;
        q.push({0,k});
        dist[k]=0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node=it.second;
            int time=it.first;
            for(auto iter : adj[node]){
                int adjNode=iter.first;
                int tw=iter.second;
                if(time+tw<dist[adjNode]){
                    dist[adjNode]=time+tw;
                    q.push({time+tw,adjNode});
                }

            }
        }
        for(int i=1;i<dist.size();i++){
            if(dist[i]==1e9){
                return -1;
            }
        }
        return *max_element(dist.begin()+1,dist.end());// here also the same logic 
    }
};