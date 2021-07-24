class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n]; // store longest inc subsequence ending at the element at that index
        dp[0] = 1;
        int omax = 1;
        for(int i = 1; i < n; i++){
            int max_ = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    max_ = max( dp[j], max_);
            }
            dp[i] = max_+1;
            omax = max(omax, dp[i]);
         }
        return omax;

    }
};