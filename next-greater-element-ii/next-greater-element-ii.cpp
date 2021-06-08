class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--)
            st.push(nums[i]);
        
        for(int i = n-1; i >= 0; i--){
            //pop
            while(!st.empty() && nums[i] >= st.top())
                st.pop();
            //ans
            if(st.empty())
                res.push_back(-1);
            else
                res.push_back(st.top());
            //push
            st.push(nums[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};