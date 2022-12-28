class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        int res = accumulate(piles.begin(), piles.end(), 0);
        // cout<<res;
        while (k--) {
            int a = pq.top();
            pq.pop();
            pq.push(a - a / 2);
            res -= a / 2;
        }
        return res;
    }
};