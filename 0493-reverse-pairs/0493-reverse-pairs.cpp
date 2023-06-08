class Solution {
public:
    int count;
    int reversePairs(vector<int>& nums) {
        if(!nums.size())
            return 0;
        count=0;
        mergesort(nums,0,nums.size()-1);
        return count;
    }
    void mergesort(vector<int>& nums,int start,int end){
        if(start==end)
            return;
        int mid=(start+end)/2;
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        
        checkcount(nums,start,mid,end);
        return;
    }
    void checkcount(vector<int>& nums,int start,int mid,int end){
        int l=start,r=mid+1;
        while(l<=mid&&r<=end){
            if((long)nums[l]>(long)2*nums[r]){
                count+=(mid-l+1);
                r++;
            }
            else
                l++;
        }
        sort(nums.begin()+start,nums.begin()+end+1);
        return;
    }
};