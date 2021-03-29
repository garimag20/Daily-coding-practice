class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int> dp(amount+1);
        dp[0] = 0;
        
        for(int rupee = 1; rupee <= amount; rupee++){
            dp[rupee] = INT_MAX;
            for(auto coin : coins){
                if(coin <= rupee){
                    int sans = dp[rupee-coin];
                    if(sans != INT_MAX){
                        dp[rupee] = min(dp[rupee], sans+1);
                    }
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};