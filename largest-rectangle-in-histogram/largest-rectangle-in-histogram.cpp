class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int hsize = heights.size();
        stack<int> s;
        int i = 0, maxa = 0;
        while(i < hsize){
            if(s.empty() || heights[i] >= heights[s.top()]){
                s.push(i);
                i++;
            }
            else{
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                int area = h * width;
                maxa = max(area, maxa);
            }
        }
        return maxa;
    }
};