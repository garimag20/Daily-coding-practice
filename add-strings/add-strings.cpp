class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        
        int carry = 0;
        string res;
        while(i >= 0 || j >= 0){
            int a = (i >= 0) ? num1[i]-'0' : 0;
            int b = (j >= 0) ? num2[j]-'0' : 0;
            
            int sum = a+b+carry;
            carry = sum/10;
            sum %= 10;
            
            res.push_back('0'+sum);
            i--;
            j--;
        }
        
        if(carry){
            res.push_back('0'+carry);
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};