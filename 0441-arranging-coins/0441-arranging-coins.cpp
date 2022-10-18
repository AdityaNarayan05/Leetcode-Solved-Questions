class Solution {
public:
    int arrangeCoins(int n) {
        int l=1,r=n,ans;
        long rows,coinN;
        while(l<=r){
            rows=l+((r-l)>>1);
            coinN=(rows*(rows+1))>>1;
            if(coinN<=n)
                l=rows+1,ans=rows;
            else
                r=rows-1;
        }
        return ans;
    }
};