class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> mp(26,0);
        for(int i=0;i<letters.size();++i)
            mp[letters[i]-'a']++;
        
        int idx=(target-'a'+1)%26;
        while(mp[idx]==0){
            idx=(idx+1)%26;
        }
        return 'a'+idx;
    }
};