class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ans;
    
    int totalwords = words.size();//no of words present in vector
    int wordlength = words[0].size(); //len of each word
    int k = totalwords*wordlength;
    
    if(s.length() < k) return ans;
    
    unordered_map<string,int> mp;//to store count of words in vector
    for(int i = 0; i < totalwords; i++){
        mp[words[i]]++;
    }
    
    for(int i = 0; i <= s.length()-k; i++){
        unordered_map<string,int> visit;
        for(int j = 0; j < totalwords; j++){
            int wordIndex = i + j * wordlength;
            string w = s.substr(wordIndex, wordlength);
            if(mp.find(w) != mp.end()){
                visit[w]++;
                if(visit[w] > mp[w])
                    break;
            }
            else{
                break;
            }
            if(j + 1 == totalwords)
                ans.push_back(i);
        }
    }
    return ans;
    }
};