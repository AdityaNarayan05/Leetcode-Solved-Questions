class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r=bs(nums,target,0,nums.size()-1);
        return r;
    }
private:
    int bs(vector<int>& arr,int k,int l,int r){
        if(l>r)
            return -1;
    
        int m=(l+r)/2;
        if(arr[m]==k)
            return m;
    
        if(arr[l]<=arr[m]){
            if(k>=arr[l]&&k<=arr[m]){
                return bs(arr,k,l,m-1);
            }
            return bs(arr,k,m+1,r);
        }
        if(k>=arr[m]&&k<=arr[r]){
            return bs(arr,k,m+1,r);
        }
        return bs(arr,k,l,m-1);
    }
};