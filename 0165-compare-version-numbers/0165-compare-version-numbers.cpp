class Solution {
public:
    long long calculate(string& s, int& p) {
        int n = s.length();
        long long val = 0;
        while (p < n && s[p] != '.') {
            val = val * 10 + (s[p] - '0');
            p++;
        }
        if (p < n) {
            p++; // Move past the '.'
        }
        return val;
    }

    int compareVersion(string version1, string version2) {
        int n = version1.length();
        int m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            long long v1 = (i < n) ? calculate(version1, i) : 0;
            long long v2 = (j < m) ? calculate(version2, j) : 0;

            if (v1 > v2) {
                return 1;
            } else if (v1 < v2) {
                return -1;
            }
        }
        return 0;
    }
};
