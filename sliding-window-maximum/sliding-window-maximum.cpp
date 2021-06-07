class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i;
        deque<int> dq;
        //check for first window
        for(i = 0; i < k; i++){
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        //check for rest of windows
        for( ; i < nums.size(); i++){
            ans.push_back(nums[dq.front()]);
            //remove from left- it lies outside window 
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            //remove from right- element in queue is less than the current element
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};