class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        if(r == 1 && c == 1)//if one element is present
            return grid[0][0];
        
        vector<vector<int>> dp(r, vector<int>(c,0));
        dp[0][0] = grid[0][0];
        
        for(int i = 1; i < c; i++)// for first row
            dp[0][i] = dp[0][i-1] + grid[0][i];
        
        for(int j = 1; j < r; j++)//for first column
            dp[j][0] = dp[j-1][0]+ grid[j][0];
        
        for(int i = 1; i < r; i++){
            for(int j = 1; j < c; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[r-1][c-1];
    }
};