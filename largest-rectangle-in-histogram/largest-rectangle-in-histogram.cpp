class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        
        int size_h = heights.size();
        stack<int> s;
        int i = 0, maxa = 0;
        
        while(i < size_h){
            //push
            if(s.empty() || heights[i] >= heights[s.top()]){
                s.push(i);
                i++;
            }
            else{
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i: i-s.top()-1;
                maxa = max(maxa, h * width);
            }
        }
        return maxa;
    }
};