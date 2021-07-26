class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board[0].size();
        unordered_map<int,int> g;
        
        int dir = 1, cell = 1;
        
        for(int i = n-1; i >= 0; i--){
            if(dir == 1){
                for(int j = 0; j <n; j++){
                    if(board[i][j] != -1)
                        g[cell] = board[i][j];
                    cell++;
                }
            }
            else{
                for(int j = n-1; j >= 0; j--){
                    if(board[i][j] != -1)
                        g[cell] = board[i][j];
                    cell++;
                }
            }
            dir = -dir;
        }
        
        vector<int>dist(n*n+1, -1);
        queue<int> q;
        q.push(1);
        dist[1] = 0;
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            if(v == n*n) return dist[n*n];
            for(int dice = 1; dice <= 6; dice++){
                int a = v + dice;
                if(a > n*n) continue;
                if(g.find(a) != g.end()) a = g[a];
                if(dist[a] == -1){
                    dist[a] = dist[v]+1;
                    q.push(a);
                }
            }
        }
        return -1;
    }
};