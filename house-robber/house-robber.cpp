class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int inc = nums[0];
        int exc = 0;
        
        for(int i = 1; i < n; i++){
            int ninc = exc + nums[i];
            int nexc = max(exc, inc);
            
            inc = ninc;
            exc = nexc;
        }
        return max(inc, exc);
    }
};