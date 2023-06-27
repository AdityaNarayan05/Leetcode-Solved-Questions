class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1); 
        stack<int> st;
        unordered_map<int, int> mp;
        
        for(int i=0; i<nums2.size(); i++){
            int x = nums2[i];
            while(!st.empty() && x > st.top()){
                mp[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        
        for(int i=0; i<nums1.size(); i++){
            int x = nums1[i];
            if(mp.find(x) != mp.end()){
                int ng = mp[x];
                res[i] = ng; 
            }
        }
        
        return res;
    }
};