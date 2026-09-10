class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        // adjacency list
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int price = it[2];

            adj[u].push_back({v, price});
        }

        // distance array
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        // {stops, {node, price}}
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // We can take at most k stops
            if (stops > k)
                continue;

            for (auto edge : adj[node]) {

                int nextNode = edge.first;
                int price = edge.second;

                // Relaxation
                if (cost + price < dist[nextNode]) {

                    dist[nextNode] = cost + price;

                    q.push({
                        stops + 1,
                        {nextNode, dist[nextNode]}
                    });
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;

        return dist[dst];
    }
};