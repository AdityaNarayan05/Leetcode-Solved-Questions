class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        s1 = word1[0];
        s2 = word2[0];
        
        for (int i = 1; i < word1.size(); i++)
            s1 = s1.append(word1[i]);
        for (int i = 1; i < word2.size(); i++)
            s2 = s2.append(word2[i]);
        if (s1 == s2)
            return true;
        else
            return false;
    }
};