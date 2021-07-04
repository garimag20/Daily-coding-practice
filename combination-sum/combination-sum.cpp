class Solution {
public:
    vector<vector<int>> res;
    
    void helper(vector<int>& candidates, int target, int idx, vector<int> temp){
        
        if(idx == candidates.size()){
            if(target == 0){
            res.push_back(temp);
        }
            return;
        }
        
        //if we pick element
        if(candidates[idx] <= target){
            temp.push_back(candidates[idx]);
            helper(candidates, target-candidates[idx], idx, temp);
            temp.pop_back();
        }
        helper(candidates, target, idx+1, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates, target, 0, temp);
        return res;
    }
};