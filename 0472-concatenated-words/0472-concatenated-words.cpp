class Solution {
public:
    set<string> s;
    bool checkCon(string word){
        for(int i=1;i<word.size();i++){
            string pW=word.substr(0,i);
            string sW=word.substr(i,word.size()-i);
            
            if(s.find(pW) != s.end() and (s.find(sW) !=s.end() or checkCon(sW)))
                return true;
        }
        return false;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> cW;
        for(auto word:words)
            s.insert(word);
        
        for(auto word:words)
            if(checkCon(word))
                cW.push_back(word);
        
        return cW;
    }
};