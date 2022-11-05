class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int f = 0, b = arr.size() - 1;
        while (b - f + 1 > k) {
            if (arr[b] - x < x - arr[f])
                f++;
            else b--;
        }
        return vector<int>(arr.begin() + f, arr.begin() + b + 1);
    }
};