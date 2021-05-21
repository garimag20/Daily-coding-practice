class Solution {
public:
    bool outoforder(vector<int>& nums, int i){
        int x = nums[i];
        //border case
        if(i == 0)
            return x > nums[1];
        
        if(i == nums.size()-1)
            return x < nums[i-1];
        
        return x > nums[i+1] || x < nums[i-1];
    }
    
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return 0;
        
        int small = INT_MAX;
        int large = INT_MIN;
        
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(outoforder(nums,i)){
                small = min(small, x);
                large = max(large, x);
            }
        }
        //nums was already sorted ; no change in small or large
        if(small == INT_MAX)
            return 0;
        int left = 0;
        
        while(small >= nums[left]){
            left++;
        }
        
        int right = n-1;
        while(large <= nums[right]){
            right--;
        }
        
        return (right-left+1);
    }
};