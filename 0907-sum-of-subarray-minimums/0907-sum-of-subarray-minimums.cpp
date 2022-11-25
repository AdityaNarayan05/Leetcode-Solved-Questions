class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        arr.push_back(0);
        int n=arr.size();
        vector<int> l(n,-1),r(n,n-1);
        vector<int> st;
        for(int i=0;i<n;++i){
            while(!st.empty() && arr[st.back()]>arr[i]){
                int mid=st.back();
                st.pop_back();
                r[mid]=i-mid;
                l[mid]=st.empty() ? mid+1 : mid-st.back();
            }
            st.push_back(i);
        }
        n-=1;
        const long long mod=1e9+7;
        long long ans=0;
        for(int i=0;i<n;++i){
            ans=(ans+(long long)(l[i])*(r[i])*arr[i])%mod;
        }
        return ans;
    }
};