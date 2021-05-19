class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        unordered_set<int> st;
        for(auto x : nums)
            st.insert(x);
        int larlen = 1;
        for(auto ele : nums){
            int parent = ele-1;
            if(st.find(parent) == st.end()){
                int cnt = 1;
                int next = ele+1;
                
                while(st.find(next) != st.end()){
                    next++;
                    cnt++;
                }
                
                larlen = max(larlen, cnt);
            }
        }
        return larlen;
    }
};