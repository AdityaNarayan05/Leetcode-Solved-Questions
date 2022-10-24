class Solution {
    int helper(int mask, vector<string>& arr, int i = 0) {
        if (i >= arr.size())
            return 0;
        int tmp = mask;
        for (auto& c : arr[i]) {
            if ((mask >> (c - 'a') & 1)) 
                return helper(tmp, arr, i + 1);
            mask |= 1 << (c - 'a');
        }
        return max(helper(tmp, arr, i + 1), (int) (helper(mask, arr, i + 1) + arr[i].size()));
    }
public:
    int maxLength(vector<string>& arr) {
        return helper(0, arr);
    }
};