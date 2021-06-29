class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n1 = -1, n2 = -1, c1 = 0, c2 = 0;
        
        int n = nums.size()/3;
        for(int x : nums){
            if(n1 == x){
                c1++;
            }
            else if(n2 == x){
                c2++;
            }
            else if(c1 == 0){
                n1 = x;
                c1++;
            }
            else if(c2 == 0){
                n2 = x;
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1 = 0; c2 = 0;
        
        for(int x : nums){
            if(n1 == x)
                c1++;
            else if(n2 == x)
                c2++;
        }
        
        if(c1 > n)
            ans.push_back(n1);
        if(c2 > n)
            ans.push_back(n2);
        
        return ans;
    }
};