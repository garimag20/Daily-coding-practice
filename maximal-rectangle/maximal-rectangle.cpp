class Solution {
public:
    int maxArea(vector<int>& heights){
        heights.push_back(0);
        int area = 0;
        stack<int> s;
        int i = 0;
        while(i < heights.size()){
            if(s.empty() || heights[i] >= heights[s.top()]) s.push(i++);
            else{
                int h = s.top();
                s.pop();
                area = max(area, heights[h] * (s.empty() ? i : i-s.top()-1));
            }
        }
        return area;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) 
           return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<int> heights(n,0);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            res = max(res, maxArea(heights));
        }
        return res;
    }
};