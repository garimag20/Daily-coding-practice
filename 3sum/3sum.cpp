class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        for(int i = 0; i < n-2; i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int target = 0-nums[i];
            int low = i+1, high = n-1;
            while(low < high){
                int summ = nums[low]+nums[high];
                if(summ < target)
                    low++;
                else if(summ > target)
                    high--;
                else{
                    ans.push_back({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                    while(low<high && nums[low] == nums[low-1]) low++;
                    while(low<high && nums[high] == nums[high+1]) high--;
                }
            }
        }
        return ans;
    }
};