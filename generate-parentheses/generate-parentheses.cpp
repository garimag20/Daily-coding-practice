class Solution {
    vector<string> ans;
public:
    
    void helper(int n, string res, int open, int close, int i){
        if (i == 2*n){
            ans.push_back(res);
            return;
        }
        
        if(open < n){
            helper(n, res+'(', open+1, close, i+1);
        }
        
        if(close < open){
            helper(n, res+')', open, close+1, i+1);
        }
        return;
    }
    
        
    vector<string> generateParenthesis(int n) {
        string res = "";
        helper(n , res, 0, 0, 0);
        return ans;
    }
};