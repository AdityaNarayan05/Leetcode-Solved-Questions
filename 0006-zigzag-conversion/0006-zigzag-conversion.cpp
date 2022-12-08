class Solution {
public:
    string convert(string s, int nR) {
        string ans;
        vector<string> tmp(nR);
        int i=0,n=s.size();
        while(i<n){
            for(int j=0;j<nR and i<n;j++,i++)
                tmp[j]+=s[i];
            
            for(int j=nR-2;j>0 and i<n;j--,i++)
                tmp[j]+=s[i];
        }
        for(int j=0;j<nR;j++){
            ans+=tmp[j];
        }
        return ans;
    }
};