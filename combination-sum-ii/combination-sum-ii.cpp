class Solution {
public:
    vector<vector<int>> res;
    
    void helper(vector<int>& candidates, int target, int idx, vector<int> temp){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        for(int i = idx; i < candidates.size(); i++){
            if(i > idx and candidates[i] == candidates[i-1]) continue;
            if(target - candidates[i] >= 0){
                temp.push_back(candidates[i]);
                helper(candidates, target-candidates[i], i+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, temp);
        return res;
    }
};