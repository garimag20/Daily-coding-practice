class Solution {
public:
    string fractionToDecimal(int num, int den) {
        if(num == 0)
            return "0";
        bool positive = ((num > 0 && den > 0) || (num < 0 && den < 0));
        num = abs(num);
        den = abs(den);
        
        string ans = "";
        
        int quo = num/den;
        long rem = num%den;
        ans += to_string(quo);
        if(positive == true && ans[0]=='-')ans = ans.substr(1);
        if(rem == 0)
            return ans;
        else{
            ans += '.';
            unordered_map<int, int> mp;
            while(rem != 0){
                if(mp.find(rem) != mp.end()){
                    int len = mp[rem];
                    ans = ans.substr(0, len) + '(' + ans.substr(len) + ')';
                    break;
                }
                else{
                    mp[rem] = ans.length();
                    rem *= 10;
                    quo = rem/den;
                    rem = rem % den;
                    ans += to_string(quo);
                }
            }
            
        }
        if(!positive)
            ans = '-'+ans;
        return ans;
    }
};