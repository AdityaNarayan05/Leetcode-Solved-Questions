class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        cout<<(s+s)<<endl;
        cout<<(s+s).substr(1,s.size()*2-2)<<endl;
        cout<<((s+s).substr(1,s.size()*2-2).find(s)!=-1) << endl;
        
        return (s+s).substr(1,s.size()*2-2).find(s)!=-1;
    }
};