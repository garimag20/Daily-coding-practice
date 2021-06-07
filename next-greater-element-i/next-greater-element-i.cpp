class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        vector<int> ans(n1,0);
        unordered_map<int, int> mp;
        stack<int> s;
        
        s.push(nums2[n2-1]);
        mp[nums2[n2-1]] = -1;
        
        for(int i = n2-2; i >= 0; i--){
            //pop
            while(!s.empty() && nums2[i] > s.top())
                s.pop();
            //ans
            if(s.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = s.top();
            }
            //push
            s.push(nums2[i]);
        }
        
        for(int i = 0; i < n1; i++){
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};