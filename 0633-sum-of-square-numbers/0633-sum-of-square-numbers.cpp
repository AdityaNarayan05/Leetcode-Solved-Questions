class Solution {
public:
    bool judgeSquareSum(int c) {
        long l=0,r=sqrt(c);
        while(l<=r){
            long curr=l*l + r*r;
            if(curr<c)
                l++;
            else if(curr>c)
                r--;
            else
                return true;
        }
        return false;
    }
};