class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0)
            return 0;
        
        int left[n], right[n];
        
        //fill left array
        left[0] = height[0];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i-1], height[i]);
        }
        //fill right array
        right[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            right[i] = max(right[i+1], height[i]);
        }
        int water = 0;
        //calculate the amount of water stored
        for(int i = 0; i < n; i++){
            //min(left[i], right[i])-height[i]
            water += min(left[i], right[i]) - height[i];
        }
        
        return water;
    }
};