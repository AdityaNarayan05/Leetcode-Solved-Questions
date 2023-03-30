class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || st.empty()) {
                st.push(ast[i]);
            }
            else {
                while(!st.empty() and st.top() > 0 and st.top() < abs(ast[i])) {
                    st.pop();
                }
                if(!st.empty() and st.top() == abs(ast[i])) {
                    st.pop();
                }
                else {
                    if(st.empty() || st.top() < 0) {
                        st.push(ast[i]);
                    }
                }
            }
        }
		// finally we are returning the elements which remains in the stack.
		// we have to return them in reverse order.
        vector<int> res(st.size());
        for(int i = (int)st.size() - 1; i >= 0; i--) {
            res[i] = st.top();
            st.pop();
        }
        return res;
    }
};