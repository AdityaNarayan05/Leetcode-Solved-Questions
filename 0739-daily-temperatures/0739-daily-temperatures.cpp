class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> days(n,0);
        stack<int> st;
        for(int i=n-1;i>=0;--i){
            while(!st.empty() and temp[st.top()]<=temp[i])
                st.pop();
            
            if(!st.empty())
                days[i]=st.top()-i;
            st.push(i);
        }
        return days;
    }
};