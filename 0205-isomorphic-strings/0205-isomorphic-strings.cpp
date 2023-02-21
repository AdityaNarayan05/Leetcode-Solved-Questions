class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()){
            cout<<"1st one ";
            return 0;
        }
            
        unordered_map<char,int> smp,tmp;
        for(int i=0;i<s.size();i++){
            if(smp[s[i]]!=tmp[t[i]])
                return 0;
            smp[s[i]]=i+1;
            tmp[t[i]]=i+1;
        }
       
        return 1;
    }
};