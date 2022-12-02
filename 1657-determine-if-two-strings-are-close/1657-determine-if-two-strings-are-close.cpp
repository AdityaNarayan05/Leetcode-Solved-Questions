class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        
        int n = word1.size();
        vector<int>h1(26,0);
        vector<int>h2(26,0);
        
        for(int i= 0 ; i < n ; ++i){
            h1[word1[i]-'a']++;
            h2[word2[i]-'a']++;
        }
        sort(h1.rbegin(),h1.rend());
        sort(h2.rbegin(),h2.rend());
        if(set(word1.begin(),word1.end())!=set(word2.begin(),word2.end()))
            return false;
        for(int i= 0;i<26;++i){
            if(h1[i]!=h2[i])
                return false;
        }
        return true;
    }
};