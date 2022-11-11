class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        set <int> st;
        for(auto num:nums)
            st.insert(num);
        
        int ans = st.size();
        int i=0;
        for(auto s:st){
            nums[i]=s;
            i++;
        }
        return ans;
    }
};