class Solution {
public:
    static bool compare(vector<int> &nums1,vector<int> &nums2){
        return nums1[1] < nums2[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int prev=0;
        int res=0;
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[prev][1]>intervals[i][0])
                res++;
            else
                prev=i;
        }
        return res;
    }
};