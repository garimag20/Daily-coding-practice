class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        
        for(int num : nums){
            if(int(log10(num)) % 2){
                ans++;
            }
        }
        
        return ans;
    }
};