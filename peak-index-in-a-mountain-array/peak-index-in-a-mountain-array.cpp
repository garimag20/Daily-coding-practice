class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 1;
        for(; i < n-1; i++){
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1])
                break;
            else 
                continue;
        }
        return i;
    }
};