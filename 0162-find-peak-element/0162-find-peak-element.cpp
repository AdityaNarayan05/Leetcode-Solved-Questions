class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        vector<int> arr;
        for(auto num:nums)
            arr.push_back(num);
        sort(arr.begin(),arr.end());
        int i=0;
        for(auto num:nums){
            if(arr[nums.size()-1]==num)
                break;
            i++;
        }
        return i;
    }
};