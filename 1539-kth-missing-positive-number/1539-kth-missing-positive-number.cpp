class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        int res;
        
        for(int i = 1; i < arr[arr.size()-1]; i++){
            auto idx =  find(arr.begin(),arr.end(),i);
            if(idx!=arr.end())
                continue;
            else
                count++;
            if(count == k)
                res = i;
        }
        if(count<k){
            res = arr[arr.size()-1]+(k-count);
        }
        
        return res;
    }
};