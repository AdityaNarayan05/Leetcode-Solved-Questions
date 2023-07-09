class Solution {
public:
    int largestVariance(string s) {
        int n = s.size();
        int res = 0;

        for (char p = 'a'; p <= 'z'; p++) {
            for (char q = 'a'; q <= 'z'; q++) {
                if (p == q) 
                    continue;
                
                // run Kadane's algo
                int pCount = 0; // higher one
                int qCount = 0; // lower one
                bool canExtendprevQ = false;
                
                for (auto c : s) {
                    if (c == p)
                        pCount++;
                    if (c == q)
                        qCount++;
                    
                    // an interval should contain at least one q
                    if (qCount > 0) {
                        res = max(res, pCount - qCount);
                    }
                    // edge case: consider previous q
                    else if (qCount == 0 && canExtendprevQ) {
                        res = max(res, pCount - 1);
                    }
                    // reset if # of q > # of p
                    if (qCount > pCount) {
                        qCount = pCount = 0;
                        
                        // once reset, the interval can be extended
                        // as there must be one q before the next interval
                        canExtendprevQ = true;
                    }
                }
            }
        }
        return res;
    }
};