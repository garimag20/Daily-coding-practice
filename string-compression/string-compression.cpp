class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1)
            return 1;
        
        int count = 1;
        string ans = "";
        for(int i = 0; i < chars.size()-1; i++){
            if(chars[i] == chars[i+1]){
                count++;
            }
            else
            {
                ans += chars[i];
                if(count > 1){
                    ans += to_string(count);
                }
                count = 1;
            }
        }
        
        ans += chars[chars.size()-1];
        if(count > 1)
            ans += to_string(count);
        
        chars.clear();
        for(auto x : ans)
            chars.push_back(x);
        
        return chars.size();
    }
};