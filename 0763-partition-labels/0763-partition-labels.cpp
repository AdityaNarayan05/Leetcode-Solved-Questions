class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> charIdx(26, 0);
        for(int i = 0; i < s.size(); i++){
            charIdx[s[i]-'a'] = i;
        }
        
        vector<int> results;
        int maxIdx = -1, lastIdx = 0;
        
        for(int i = 0; i < s.size(); i++){
            // cout<<charIdx[s[i]-'a']<<":";
            maxIdx = max(maxIdx, charIdx[s[i]-'a']);
            // cout<<maxIdx<<" ";
            if(i == maxIdx) {
                results.push_back(maxIdx - lastIdx + 1);
                lastIdx = i+1;
            }
        }
        return results;
    }
};