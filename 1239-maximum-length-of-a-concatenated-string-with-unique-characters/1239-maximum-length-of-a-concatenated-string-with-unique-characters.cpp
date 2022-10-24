class Solution {
public:
    int maxLength(vector<string>& arr,string str = "", int index = 0) {
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.size())) 
            return 0;
        
        int res = str.size();
        for (int i = index; i < arr.size(); i++)
            res = max(res, maxLength(arr, str+arr[i], i+1));

        return res;
    }
};