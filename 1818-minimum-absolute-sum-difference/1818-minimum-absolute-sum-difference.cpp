class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> h;
        for(auto &e:nums1)
            h.insert(e);
        long long gain=0;
        long long sum=0;
        int mod=1e9+7;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            long long ori=abs(nums1[i]-nums2[i]);
            sum+=ori;
            if(gain<ori){
                auto it=h.lower_bound(nums2[i]);
                if(it!=h.end()){
                    gain=max(gain,ori-abs(nums2[i]-(*it)));
                }
                if(it!=h.begin()){
                    it--;
                    gain=max(gain,ori-abs(nums2[i]-(*it)));
                }
            }
        }
        return (sum-gain)%mod;
    }
};