class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(s.size() == 0 || k > n)   
            return 0;
        if(k == 0)  
            return s.size();
        
        unordered_map<char,int> Mp;
        for(int i = 0; i < n; i++){
            Mp[s[i]]++;
        }
        
        int idx =0;
        while(idx <n && Mp[s[idx]] >= k)   
            idx++;
        if(idx == n) 
            return n;
        
        int left = longestSubstring(s.substr(0 , idx) , k);
        int right = longestSubstring(s.substr(idx+1) , k);
        
        return max(left, right);
    }
};