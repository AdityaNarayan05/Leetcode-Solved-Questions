class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
        vector<int> combination(k, 0);
        
        for (int i = 0; i < k; ++i)
            combination[i] = i + 1;

        while (true) {
            result.push_back(combination);
            int j = k - 1;
            while (j >= 0 && combination[j] == n-(k-j-1))
                --j;

            if (j < 0)
                break;
            
            ++combination[j];
            
            for (int i = j + 1; i < k; ++i) 
                combination[i] = combination[i - 1] + 1;
        }

        return result;
	}
};