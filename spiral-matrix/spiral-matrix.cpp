class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
    vector<int> ans;
    int maxr = matrix.size();
    if(maxr == 0)
        return {};
    int maxc = matrix[0].size();
    int minr = 0, minc = 0;
    while(minr< maxr && minc < maxc){
        for(int i = minc; i < maxc; i++){
            ans.push_back(matrix[minr][i]);
        }
        minr++;
        for(int i = minr; i < maxr; i++)
            ans.push_back(matrix[i][maxc-1]);
        maxc--;
        if(minr < maxr){
            for(int i = maxc-1; i >= minc; i--)
                ans.push_back(matrix[maxr-1][i]);
            maxr--;
        }
        if(minc < maxc){
            for(int i = maxr-1; i >= minr; i--)
                ans.push_back(matrix[i][minc]);
            minc++;
        }
    }
    return ans;
}

};