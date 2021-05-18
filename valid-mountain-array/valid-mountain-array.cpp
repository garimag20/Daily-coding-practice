class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3)
            return false;
        
        int i = 0, j = n-1;
        
        while(i<n-1){
            if(arr[i] < arr[i+1])
                i++;
            else
                break;
        }
        
        while(j > 0){
            if(arr[j] < arr[j-1])
                j--;
            else
                break;
        }
        
        return (i == j && i != 0 && j != n-1);
    }
};