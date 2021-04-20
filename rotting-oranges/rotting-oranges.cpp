class Solution {
public:
    bool isvalid(int x, int y, int R, int C){
        if(x >= 0 && x < R && y >= 0 && y < C)
            return true;
        return false;
    }
    int bfs(vector<vector<int>>& grid, int R, int C){
        queue<pair<pair<int, int>, int>> q;
        int fresh = 0;
        
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(grid[i][j] == 1)
                    fresh++;
                if(grid[i][j] == 2)
                    q.push({{i,j},0});
            }
        }
        int m[] = {0, 0, 1, -1};
        int n[] = {1, -1, 0, 0};
        
        int time = 0;
        while(!q.empty()){
            auto it = q.front();
            int i = it.first.first;
            int j = it.first.second;
            time = it.second;
            
            q.pop();
            
            for(int p = 0; p < 4; p++){
                int x = i + m[p];
                int y = j + n[p];
                
                if(isvalid(x,y,R,C) && grid[x][y] == 1){
                    fresh--;
                    grid[x][y] = 2;
                    q.push({{x,y},time+1});
                }
            }
        }
        if(fresh)
            return -1;
        return time;      
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        return bfs(grid, R, C);
    }
};