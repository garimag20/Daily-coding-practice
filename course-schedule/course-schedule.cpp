class Solution {
    
    bool dfs_cycle(vector<vector<int>>& v, vector<int>&color,int k){
        
        color[k]=1;
        for(auto x:v[k]){
            if(color[x]==1)return true;
            if(color[x]==0 && dfs_cycle(v,color,x))return true;
        }
        color[k]=2;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>>v(n+1);

        for(auto x:prerequisites)
            v[x[1]].push_back(x[0]);
        
        vector<int>color(n+1,0);
        for(int i=1;i<=n;i++){
            if(color[i]==0)
            {
                if(dfs_cycle(v, color,i)){
                   return false;
                }
            }
    }
        return true;
    }
};