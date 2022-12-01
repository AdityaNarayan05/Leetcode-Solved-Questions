class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(0,s,0,p);    
    }
    bool isMatch(int i, string& s, int j, string &p) {
        int pn=p.size(), sn = s.size();
        if(j==pn)
            return i==sn;
        if(p[j+1]=='*'){
            if(isMatch(i,s,j+2,p))
                return 1;
            while(i<sn && (p[j]==s[i]||p[j]=='.')) 
				if(isMatch(++i,s,j+2,p)) 
                    return 1;
        } else if (i<sn && (p[j]=='.'|| s[i]==p[j]) && isMatch(i+1,s,j+1,p)) 
			return 1;
        
        return 0;
    }
};