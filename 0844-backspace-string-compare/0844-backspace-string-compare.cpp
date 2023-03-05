class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a="",b="";
        for(auto c:s){
            if(c=='#'){
                if(a.size()>0)
                    a.pop_back();
                else
                    void();
            }
            else
                a.push_back(c);
        }
        for(auto c:t){
            if(c=='#'){
                if(b.size()>0)
                    b.pop_back();
                else
                    void();
            }
            else
                b.push_back(c);
        }
        return a==b;
    }
};