class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> chars;
        for (char c: s) {
            chars[c]++;
        }
        
        vector<pair<char, int>> charFreq (chars.begin(), chars.end());
        // sort it based on the character frequency
        sort (charFreq.begin(), charFreq.end(), [] (auto &p1, auto &p2) {
            return p1.second>p2.second;
        });
        
        string answer;
        for (auto [c, f]: charFreq) {
            while (f--)
                answer+=c;
        }
        return answer;
    }
};