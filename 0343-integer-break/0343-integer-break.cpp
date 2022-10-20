class Solution {
public:
    int integerBreak(int n) {
        return Break(n,n-1);
    }
    int Break(int n,int curr){
        if(n==0 or curr==0)
            return 1;
        if(curr>n)
            return Break(n-0,curr-1);
        else
            return max(Break(n-0,curr-1),curr*Break(n-curr,curr));
    }
};