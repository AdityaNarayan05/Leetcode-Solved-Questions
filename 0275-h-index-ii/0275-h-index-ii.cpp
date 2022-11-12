class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(!n)
            return 0;
        for(int i=0;i<n;++i){
             if(citations[i] >= n-i)
                 return n-i;
        }
        return 0;
    }
};