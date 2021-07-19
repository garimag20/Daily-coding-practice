class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2)
            return n;
        unordered_map<double, int> mp;
        int max_points = 0;
        
        for(int i = 0; i < n; i++){
            mp.clear();
            for(int j = i+1; j < n ; j++){
                double slope;
                if(points[i][0] == points[j][0])
                    slope = 1e9;
                else{
                    slope = ((double(points[j][1] - points[i][1]))/(double(points[j][0] - points[i][0])));
                }
                mp[slope]++;
                max_points = max(max_points, mp[slope]);
            }
        }
        return max_points+1;
    }
};