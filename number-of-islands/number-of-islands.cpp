class Solution {
public:
    
    void dfs(int n, int m, int i, int j, vector<vector<char>>& grid){
        if(i<0 || j < 0 || i >= n || j >= m || grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';
        dfs(n, m, i+1, j, grid);
        dfs(n, m, i, j+1, grid);
        dfs(n, m, i-1, j, grid);
        dfs(n, m, i, j-1, grid);
            
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)
            return 0;
        int m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(n,m,i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};