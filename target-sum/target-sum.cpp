class Solution {
public:
    int subsetsum(vector<int>& nums, int sum){
        int n = nums.size();
        int dp[n+1][sum+1];
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                    dp[i][j] = 0;
                
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                
                    if(nums[i-1] <= j)
                        dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
            }
        }
        return dp[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum = 0;
        
        for(auto num : nums)
            tsum += num;
        
        int s1 = (tsum+target)/2;
        if((target+tsum)%2 != 0)
            return 0;
        else
            return subsetsum(nums, s1);
    }
};