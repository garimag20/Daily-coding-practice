class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;
        
        unordered_map<int,int> mp;
        int sum = 0; 
        int len = 0;
        
        mp[0] = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                sum += -1;
            else
                sum += 1;
            
            if(mp.find(sum) != mp.end()){
                len = max(len, i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return len;
    }
};