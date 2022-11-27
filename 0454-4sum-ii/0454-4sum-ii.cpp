class Solution {
public:
    void xsort(vector<int>& V){
        sort(V.begin(), V.end());
    }
    int fourSumCount(vector<int>& nums1,vector<int>& nums2,vector<int>& nums3,vector<int>& nums4){
        xsort(nums1); xsort(nums2); xsort(nums3); xsort(nums4);
        int z=nums1.size()-1;
        int  left=min(nums1[0]+nums2[0], -nums3[z]-nums4[z]);
        int right=max(nums1[z]+nums2[z], -nums3[0]-nums4[0]);
        vector<int> V(right-left+1, 0);
      
        for(auto &a : nums1)
            for(auto &b : nums2)
                V[a+b-left]++;
        
        int cnt=0;
        for(auto &a : nums3)
            for(auto &b : nums4)
                cnt+=V[-a-b-left];
        
        return cnt;
    }
};