class Solution {
    vector<vector<int>> ans;
public:
    void permutate(vector<int>& nums, int curr){
        if(curr == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = curr; i < nums.size(); i++){
            swap(nums[curr], nums[i]);
            permutate(nums, curr+1);
            swap(nums[curr], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permutate(nums, 0);
        return ans;
    }
};