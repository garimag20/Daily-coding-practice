class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal = 0;
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
           bal += ( s[i] == '(' ? 1 : -1);
           if(bal == -1){
               ans += 1;
               bal += 1;
           }
    }
        return bal+ans;
    }
};