class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r) / 2;
            if (accumulate(begin(nums), end(nums), 0, [&](int s, int n){
                return s + (n - 1) / m; }) <= maxOperations)
                r = m;
            else
                l = m+1;
        }
        return l;
    }
};