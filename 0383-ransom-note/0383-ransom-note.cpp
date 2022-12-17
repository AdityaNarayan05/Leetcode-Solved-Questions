class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>v(128);
        for(char a:magazine){
            v[a]++;
        }
        for(char a:ransomNote){
            if(v[a]<=0)
                return false;
                v[a]--;
        }
        return true;
    }
};