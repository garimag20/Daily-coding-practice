class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n = v.size();
        if(n == 1)
            return 0;
        sort(v.begin(), v.end());
        int count = 0;
        int left = 0; 
        int right = 1;
        
        while(right < n){
            //case 1 : when left n right are not overlapping->left.end <= right.start
            if(v[left][1] <= v[right][0]){
                left = right;
                right++;
            }
            //case 2 : overlapping case 1; remove right one
            else if(v[left][1] <= v[right][1]){
                count++;
                right++;
            }
            //case 3 : overlapping case 2; remove left one
            else if(v[left][1] > v[right][1]){
                count++;
                left = right;
                right++;
            }
        }
        return count;
    }
};