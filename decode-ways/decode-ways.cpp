class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if(s[0] == '0')
            return 0;
        
        if(n == 1)
            return 1;
        
        int dp[n];
        dp[0] = 1;
        
        for(int i = 1; i < n; i++){
            //cases for i-1 and i
            //case 1 : both zero
            //no solution
            if(s[i] == '0' and s[i-1] == '0'){
                dp[i] = 0;
            }
            
            //case 2 : first zero , second non zero ; eg -> 02
            else if(s[i-1] == '0' and s[i] != '0'){
                dp[i] = dp[i-1];
            }
            //case 3 : first is non zero and second is zero
            else if(s[i-1] != '0' and s[i] == '0'){
                if(s[i-1] == '1' || s[i-1] == '2'){
                    dp[i] = (i >= 2) ? dp[i-2] : 1;
                }
                else{
                    dp[i] = 0;
                }
            }
            //case 4: both are non zero
            else{
                if(stoi(s.substr(i-1, 2)) <= 26){
                    dp[i] = dp[i-1] + ((i >= 2) ? dp[i-2] : 1);
                }
                else{
                    dp[i] = dp[i-1];
                }
            }
        }
            
            return dp[n-1];
            
        }
    
};