class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<int> setElements(n);
        for (int i = 0; i < n; ++i) {
            setElements[i] = i + 1; // Assuming the set contains elements 1 to n
        }

        vector<vector<int>> result;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (__builtin_popcount(mask) == k) { // Check if the number of set bits in the mask is k
                vector<int> combination;
                for (int i = 0; i < n; ++i) {
                    if (mask & (1 << i)) {
                        combination.push_back(setElements[i]);
                    }
                }
                result.push_back(combination);
            }
        }
        return result;
	}
};