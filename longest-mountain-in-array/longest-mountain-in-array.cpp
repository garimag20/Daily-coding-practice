class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)
            return 0;
        int large = 0;
        
        for(int i = 1; i < n-1; i++){
            if(arr[i] > arr[i-1] and arr[i] > arr[i+1]){
                int start = i;
                int end = i;
                //move left
                while(start >= 1 and arr[start] > arr[start-1]){
                    start--;
                }
                //move right
                while(end <= n-2 and arr[end] > arr[end+1]){
                    end++;
                }
                large = max(large, (end-start+1));
                i = end;
            }
        }
        return large;
    }
};