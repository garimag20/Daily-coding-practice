class Solution {
public:
    bool ispal(string temp){
        int s = 0, e = temp.length()-1;
        
        while(s <= e){
            if(temp[s] != temp[e])
                return false;
            s++;
            e--;
        }
        return true;
    }
    void helper(string& s, int idx, vector<string>& curr, vector<vector<string>>& ans){
        if(idx == s.length()){
            ans.push_back(curr);
            return;
        }
        string temp = "";
        for(int i = idx; i < s.length(); i++){
            temp.push_back(s[i]);
            if(ispal(temp)){
                curr.push_back(temp);
                helper(s, i+1, curr, ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(s, 0, curr, ans);
        return ans;
    }
};