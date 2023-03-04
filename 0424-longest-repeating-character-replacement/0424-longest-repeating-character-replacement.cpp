class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26,0);
        int start=0;
        int maxCharCnt=0;
        int  n=s.size();
        int res=0;
        
        for(int end=0;end<n;end++){
            cnt[s[end]-'A']++;
            if(maxCharCnt < cnt[s[end]-'A'])
                maxCharCnt=cnt[s[end]-'A'];
            
            while(end-start-maxCharCnt+1 >k){
                cnt[s[start]-'A']--;
                start++;
                for(int i=0;i<26;i++){
                    if(maxCharCnt<cnt[i])
                        maxCharCnt=cnt[i];
                }
            }
            res=max(res,end-start+1);
        }
        return res;
    }
};