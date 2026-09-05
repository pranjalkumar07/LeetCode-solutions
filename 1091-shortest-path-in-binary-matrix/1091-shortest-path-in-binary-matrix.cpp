class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Source or destination blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<pair<int,int>, int>> q;

        // {row, col}, distance
        q.push({{0, 0}, 1});

        // Mark source visited
        grid[0][0] = 1;

        // 8 directions
        int dr[] = {-1,-1,-1,0,0,1,1,1};
        int dc[] = {-1,0,1,-1,1,-1,0,1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int r = it.first.first;
            int c = it.first.second;
            int dis = it.second;

            // Destination reached
            if (r == n-1 && c == n-1)
                return dis;

            // Explore 8 neighbours
            for (int i = 0; i < 8; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 0) {

                    grid[nr][nc] = 1;

                    q.push({{nr, nc}, dis + 1});
                }
            }
        }

        return -1;
    }
};