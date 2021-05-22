class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int csum = nums[0];
        int bsum = nums[0];
        
        for(int i = 1; i < n; i++){
            csum = max(csum+nums[i], nums[i]);
            bsum = max(bsum, csum);
        }
        return bsum;
    }
};