#define ll long long int
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=-1;
        for(auto i:piles)
            maxi=max(maxi,i);
        int ans=-1;
        int low=1,high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            ll total=0;
            for(auto i:piles){
                if(i%mid==0)
                    total+=i/mid;
                else
                    total+=i/mid+1;
            }
            if(total>h)
                low=mid+1;
            else if(total<=h){
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};