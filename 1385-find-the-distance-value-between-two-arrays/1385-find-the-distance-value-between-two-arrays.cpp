class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(begin(arr2), end(arr2));
        int ans = 0;
        for (int n : arr1) {
            if (upper_bound(begin(arr2), end(arr2), n + d) == lower_bound(begin(arr2), end(arr2), n - d))
                ++ans;
        }
        return ans;
    }
};