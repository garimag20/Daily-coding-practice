class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int>& nums, int idx, vector<int> cur){
        if(idx == nums.size()){
            ans.push_back(cur);
            return;
        }
        vector<int> newcur = cur;
        newcur.push_back(nums[idx]);
        helper(nums, idx+1, newcur);
        helper(nums, idx+1, cur);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        helper(nums, 0, temp);
        return ans;
    }
};