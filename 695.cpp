class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;

        for (int i{0}; i < grid.size(); ++i) {
            for (int j{0}; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid,i,j);
                    // then it updates the local island size, we compare it to
                    // the max
                    if (local_island_size > max_island_size)
                        max_island_size = local_island_size;
                    local_island_size = 0; // reset it for the next island
                }
            }
        }
        return max_island_size;
    }

    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] != 1)
            return;

        // mark current as seen and expand out with dfs
        grid[i][j] = -1;
        ++local_island_size;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

private:
    int local_island_size{0};
    int max_island_size{0};
};
