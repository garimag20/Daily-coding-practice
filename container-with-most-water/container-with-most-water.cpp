class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxwater = 0;
        
        while(start < end){
            if(height[start] <= height[end]){
                maxwater = max(maxwater, height[start]*(end-start));
                start++;
            }
            else{
                maxwater = max(maxwater, height[end]*(end-start));
                end--;
            }
        }
        return maxwater;
    }
};