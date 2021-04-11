class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0 || nums[n-1] < target)
            return {-1,-1};
        
        vector<int>result;
        auto start = lower_bound(nums.begin(), nums.end(), target);
        auto end = upper_bound(nums.begin(), nums.end(), target);
        
        if(nums[start-nums.begin()] != target)
            return {-1,-1};
        
        else{
            result.push_back(start-nums.begin());
            result.push_back(end-nums.begin()-1);
        }
        return result;
    }
};