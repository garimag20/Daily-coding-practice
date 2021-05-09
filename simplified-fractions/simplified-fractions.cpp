class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        unordered_set<float> set;
        
        for(int i = 1; i < n; i++){
            for(int j = i+1; j <= n; j++){
                float frac = float(i)/j;
                if(set.find(frac) == set.end()){
                    res.push_back(to_string(i)+"/"+to_string(j));
                    set.insert(frac);
                }
            }
        }
        return res;
    }
};