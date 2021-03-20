class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int i){
        vis[i] = true;
        for(auto room : rooms[i]){
            if(!vis[room])
                dfs(rooms, vis, room);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(rooms, vis, 0);//O(k)
        for(auto x : vis){//O(n)
            if(!x)
                return false;
        }
        return true;
            
    }//O(n+k)
};