class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int cnt = 0;
        for(int i=0 ;i< s.size(); i++){
           string words;
           if(s[i]!= ' '){
              while(i<s.size() && s[i]!=' '){
               words+=s[i];
               i++;
               }
            st.push(words);
           }
               
        }
        // cout<<st.top();
        string ans;
        ans += st.top();
        st.pop();
        while(!st.empty()){
            ans+=' '+st.top();
            st.pop();
        }        
        return ans;
    }
};