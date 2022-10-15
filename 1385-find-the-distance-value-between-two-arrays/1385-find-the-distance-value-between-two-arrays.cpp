class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        return count_if(begin(arr1),end(arr1),[&](const auto &a){
            return all_of(begin(arr2),end(arr2),[&](const auto &b){
                return abs(a-b)>d;
            });
        });
    }
};