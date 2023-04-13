class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // stack<int> st;
        int i=0,j=0;
        for(int push:pushed){
            pushed[i++]=push;
            while(i>0 and pushed[i-1]==popped[j])
                ++j,--i;
        }
        return i==0;
    }
};