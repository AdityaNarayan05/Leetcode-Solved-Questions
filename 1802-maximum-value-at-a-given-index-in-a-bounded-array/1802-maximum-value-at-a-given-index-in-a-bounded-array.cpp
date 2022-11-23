class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int right=n-index-1;
        int left=index;
        int low=1, high=maxSum, res=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long sum=0, leftsum=0, righsum=0, m=mid-1;
            if(right<=m){
                righsum=m*(m+1)/2 - (m-right)*(m-right+1)/2;
            }else{
                righsum=m*(m+1)/2+right-m;
            }
            if(left<=m){
                leftsum=m*(m+1)/2 - (m-left)*(m-left+1)/2;
            }else{
                leftsum=m*(m+1)/2+left-m;
            }
            sum=mid+leftsum+righsum;
            if(sum<=maxSum) 
                res=mid, low=mid+1;
            else high=mid-1; 
        }
    return res;
    }
};