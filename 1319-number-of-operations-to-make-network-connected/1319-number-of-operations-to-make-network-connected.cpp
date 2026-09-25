class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        // Already connected
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        // Minimum n-1 cables are required
        if (connections.size() < n - 1)
            return -1;

        DisjointSet ds(n);

        int extraEdges = 0;
        for (auto it : connections) {

            int u = it[0];
            int v = it[1];

            // If both are already connected,
            // this cable is extra
            if (ds.findUPar(u) == ds.findUPar(v)) {
                extraEdges++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }

        // Counting connected components
        int components = 0;

        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) {
                components++;
            }
        }

        // Need components - 1 cables
        int requiredEdges = components - 1;

        if (extraEdges >= requiredEdges)
            return requiredEdges;

        return -1;
    }
};