class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        unordered_map<string,int> cnt;
        int j = 0;
        string prev = "";
        
        for(int i = 0; i < s.size() ; i++){
            string chk = "";
            while(s[i] != ' ' && i < s.size() ){
                chk += s[i];
                i++;
            }
            if(m.find(pattern[j]) != m.end()){
                if(m[pattern[j]] != chk){
                    return false;
                }
                m[pattern[j]] = chk;
            }
            else{
                m[pattern[j]] = chk;
                cnt[chk]++;
                if(cnt[chk] > 1){
                    return false;
                }
                
            }
            if(j >= pattern.size()){
                return false;
            }
            j++;
            prev = chk;
        }
        
         if(j < pattern.size()){
            return false;
        }
        return true;
    }
};