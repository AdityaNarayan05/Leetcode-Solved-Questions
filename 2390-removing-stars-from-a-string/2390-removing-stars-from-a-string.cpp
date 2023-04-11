class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto c: s){
            if(c=='*')
                st.pop();
            else
                st.push(c);
        }
        
        int n=st.size()-1;
        string ans(st.size(),'*');
        
        while(!st.empty()){
            ans[n--]=st.top();
            st.pop();
        }
        return ans;
    }
};