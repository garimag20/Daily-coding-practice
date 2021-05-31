class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge = "";
        while(word1.length() != 0 && word2.length() != 0){
            if(word1 >= word2){
                merge += word1[0];
                word1 = word1.substr(1);
            }
            else{
                merge += word2[0];
                word2 = word2.substr(1);
            }
        }
        
        if(word1.length())
            merge += word1;
        if(word2.length())
            merge += word2;
        
        return merge;
    }
};