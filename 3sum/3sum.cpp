class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            if(i > 0 and nums[i] == nums[i-1])
                continue;
            int sum = 0 - nums[i];
            int low = i+1;
            int high = n-1;
            while(low<high){
                if(nums[low] + nums[high] < sum){
                    low++;
                }
                else if(nums[low] + nums[high] > sum){
                    high--;
                }
                else{
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                    while(low < high and nums[low] == nums[low-1]) low++;
                    while(low < high and nums[high] == nums[high+1]) high--;
                }
            }
        }
        return ans;
    }
};