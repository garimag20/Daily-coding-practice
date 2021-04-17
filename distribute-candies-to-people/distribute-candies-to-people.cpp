class Solution {
public:
    vector<int> distributeCandies(int candies, int num) {
        vector<int> candy(num,0);
        int idx = 0;
        int count = 1;
        while(candies > 0){
            candy[idx % num] += min(count, candies);
            candies -= count;
            count++;
            idx++;
        }
        return candy;
    }
};