class Solution {
public:
    int countAsterisks(string s) {
        bool isPaired=false;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*' and isPaired==false)
                count++;
            else if(s[i]=='|' and isPaired==false)
                isPaired=true;
            else if(s[i]=='|' and isPaired==true)
                isPaired=false;
        }
        return count;
    }
};