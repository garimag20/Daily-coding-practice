class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26);
        for(auto ch : s){
            freq[ch-'a']++;
        }
        
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        int f = freq[0];
        
        for(auto a : freq){
            if(a > f){
                if(f > 0) ans += (a-f);
                else
                    ans += a;
            }
            f = min(f-1, a-1);
        }
        return ans;
    }
};