class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0)
            return 0;
        
        unordered_map<int, int> hash;
        int sum = 0, count = 0;      
        hash[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            
            if(hash.find(sum-k) != hash.end())
                count += hash[sum-k];
            hash[sum]++;
        }
        return count;
    }
};