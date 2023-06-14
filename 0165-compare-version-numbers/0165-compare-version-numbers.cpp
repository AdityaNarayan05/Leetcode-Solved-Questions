class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();

        while (i < n1 || j < n2) {
            int num1 = 0, num2 = 0;

            // Process version1
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }

            // Process version2
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 < num2) return -1;
            if (num1 > num2) return 1;

            i++; // Move past the '.'
            j++; // Move past the '.'

        }

        return 0;
    }
};
