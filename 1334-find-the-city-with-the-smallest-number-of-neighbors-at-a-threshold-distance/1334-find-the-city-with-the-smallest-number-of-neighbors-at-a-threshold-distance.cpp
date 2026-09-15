class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // self distance = 0
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // edges
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Floyd Warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {

                    if(dist[i][k] != 1e9 && dist[k][j] != 1e9) {
                        dist[i][j] = min(
                            dist[i][j],
                            dist[i][k] + dist[k][j]
                        );
                    }
                }
            }
        }

        int ans = -1;
        int minCount = 1e9;

        // count reachable cities
        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {
                if(dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            // <= because equal count me greater index chahiye
            if(count <= minCount) {
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};