//https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/?envType=study-plan-v2&envId=graph-theory
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        dist[entrance[0]][entrance[1]] = 0;
        q.push({entrance[0], entrance[1});
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;
            if ((x == 0 || x == n - 1 || y == 0 || y == m - 1) && (x != entrance[0] || y != entrance[1])) {
                return -1;
            }
            for (auto dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] == '.' && dist[newX][newY] == INT_MAX) {
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                    if ((newX == 0 || newX == n - 1 || newY == 0 || newY == m - 1) && (newX != entrance[0] || newY != entrance[1])) {
                        return dist[newX][newY];
                    }
                }
            }
        }
        return -1;
    }
};
