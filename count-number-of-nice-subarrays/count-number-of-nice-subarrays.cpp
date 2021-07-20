class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int curr_sum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]%2==0) nums[i] = 0;
            else nums[i] = 1;
        }
        
        for(int i = 0; i < nums.size(); i++){
            curr_sum += nums[i];
            if(curr_sum == k) count++;
            if(mp.find(curr_sum-k) != mp.end()) 
                count += mp[curr_sum - k];
            mp[curr_sum]++;
        }
        return count;
    }
};