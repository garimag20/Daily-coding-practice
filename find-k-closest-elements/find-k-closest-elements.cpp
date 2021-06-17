class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-1-k;
        
        while(left <= right){
            //find mid
            int mid = left + (right - left)/2;
            
            if(x-arr[mid] > arr[mid+k] - x)
                left++;
            else
                right--;
        }
        vector<int>res(arr.begin() + left, arr.begin() + left+k);
        return res;
    }
};