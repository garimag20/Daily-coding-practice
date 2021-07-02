class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1)
            return 1;
        vector<int> res(n, 1);
        //case 1: whether a ratig is greater tha left rating
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                res[i] = res[i-1]+1;
            }
        }
        int tcandies = res[n-1];
        //check for right part
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i+1]){
                res[i] = max(res[i], res[i+1]+1);
            }
            tcandies += res[i];
        }
        return tcandies;
    }
};