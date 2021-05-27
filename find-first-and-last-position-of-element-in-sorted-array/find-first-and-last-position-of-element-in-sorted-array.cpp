class Solution {
public:
    int lfind(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(nums[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid] > target)
                e = mid-1;
            else
                s = mid+1;
        }
        return ans;
    }
    
    int rfind(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(nums[mid] == target){
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid] > target)
                e = mid-1;
            else
                s = mid+1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return {-1,-1};
        
        vector<int> ans;
        int lans = lfind(nums, target);
        int rans = rfind(nums, target);
        
        ans.push_back(lans);
        ans.push_back(rans);
        return ans;
    }
};