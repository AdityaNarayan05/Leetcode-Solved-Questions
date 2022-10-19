class Solution {
public:
    int greaternumberofelment(vector<int>& nums,int val){
            int count =0;
            for( int i=0;i<nums.size();++i){
                if(nums[i]>=val)
                    ++count;
            }
            return count;
        }
    int specialArray(vector<int>& nums) {
        int s=0;
        int e=1000;
        int mid;
        while(s<=e){
            mid=(s+e)/2;
            int comp= greaternumberofelment(nums,mid);            
            if(mid==comp)
                return comp;
            if(comp>mid)
                s=mid+1;
            else
                e=mid-1;
        }
        return -1;
    }
};