class Solution {
public:
    int len = 0;
    int maxLength(vector<string>& arr) {
        checklen("", arr, 0);
        return len;
    }
    
    void checklen(string temp, vector<string>& arr,int idx){
        if(!isunique(temp)) return;
        
        if(temp.length() > len) len = temp.length();
        for(int i = idx;i < arr.size(); i++){
            checklen(temp+arr[i], arr, i+1);
        }
    }
    
    bool isunique(string temp){
        set<char> st;
        for(auto ele : temp){
            if(st.find(ele) != st.end()) return false;
            st.insert(ele);
        }
        return true;
    }
};