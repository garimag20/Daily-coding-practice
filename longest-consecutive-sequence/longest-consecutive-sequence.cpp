class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        map<int,int> m;
        
        for(int i = 0; i < n; i++)
            m[nums[i]]++;
        
        int count = 1,ans = 0;
        
        auto prev = m.begin();
        
        for(auto it = m.begin(); it != m.end(); it++){
            if(prev->first+1 == it->first){
                count++;
            }
            else{
                ans = max(ans,count);
                count = 1;
            }
            prev = it;
        }
        return max(ans,count);
    }
};