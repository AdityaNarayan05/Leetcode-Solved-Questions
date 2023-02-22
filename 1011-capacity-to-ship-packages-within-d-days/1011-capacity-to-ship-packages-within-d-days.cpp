class Solution {
public:
    bool helper(int m,vector<int> &weights,int days){
        int cnt=1,sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>m){
                cnt++;
                sum=weights[i];
            }
        }
        if(cnt<=days)
            return true;
        
        return false;
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCap=0;
        int n=weights.size();
        
        for(int i=0;i<n;i++)
            maxCap+=weights[i];
        
        int low=*max_element(weights.begin(),weights.end());
        int high=maxCap;
        int res;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(mid,weights,days)){
                res=mid;
                high=mid-1;
            } else
                low=mid+1;
        }
        return res;
    }
};