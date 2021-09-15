class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        
        for(int row = 0; row < accounts.size(); row++){
            int wealth = 0;
            for(int col = 0; col < accounts[0].size(); col++){
                wealth += accounts[row][col];
            }
            ans = max(ans, wealth);
        }
        return ans;
    }
};