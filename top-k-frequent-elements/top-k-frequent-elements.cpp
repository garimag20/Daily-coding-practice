class Solution {
    struct node{
        int no;
        int freq;
        
        node(int a, int b){
            no = a;
            freq = b;
        }
    };
    
    struct compare{
        bool operator()(node const& a, node const& b){
            return a.freq < b.freq;
        }
    };
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //To create hash map
        unordered_map<int,int> map;
        for(int x: nums)
            map[x] += 1;
        
        //Build heap
        priority_queue<node, vector<node>, compare> pq; // node- num,freq
        
        for(auto it : map)
            pq.push(node(it.first, it.second));
        
        vector<int> ans;
        while(k--){
            node temp = pq.top();
            pq.pop();
            ans.push_back(temp.no);
        }
        return ans;
    }
};