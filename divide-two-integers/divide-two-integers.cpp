class Solution {
public:
    int divide(int div, int divi) {
        bool sign=(div<0)^(divi<0);
        
        long dividend=abs(div),divisor=abs(divi);
        long quotient=0;
        while(dividend>=divisor){
            long temp=divisor,i=1;
            while(dividend>=temp){
                dividend-=temp;
                quotient+=i;
                i<<=1;
                temp<<=1;
            }
        }
        if(sign)quotient=-quotient;
        
        if(quotient > INT_MAX || quotient < INT_MIN)
            return INT_MAX;
        return quotient;
    }
};