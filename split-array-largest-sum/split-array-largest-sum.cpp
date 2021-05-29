class Solution {
public:
    
    bool ispossible(vector<int>& nums, int m, int min_sum){
        int part = 1;
        int curr_sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(curr_sum + nums[i] > min_sum){
                part++;
                curr_sum = nums[i];
                
                if(part > m)
                    return false;
            }
            else
                curr_sum += nums[i];
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int s = 0;
        int e = 0;
        
        for(auto x : nums){
            e += x;
            s = max(s, x);
        }
        
        int ans = 0;
        
        while(s <= e){
            int mid = s + (e-s)/2;
            
            if(ispossible(nums, m, mid)){
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
};