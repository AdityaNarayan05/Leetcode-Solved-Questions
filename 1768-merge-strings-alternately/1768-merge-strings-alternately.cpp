class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p = 0, sz = min(word1.size(), word2.size());
        string res;
        while (p < sz)
            res += string() + word1[p] + word2[p++];
        return res + word1.substr(p) + word2.substr(p);
    }
};