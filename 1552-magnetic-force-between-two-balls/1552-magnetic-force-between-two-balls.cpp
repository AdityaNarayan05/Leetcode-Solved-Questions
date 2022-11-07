class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int l=0,r=pos.back()-pos.front();
        while(l<r){
            int mid=r-(r-l)/2;
            if(cnt(pos,mid)>=m)
                l=mid;
            else
                r=mid-1;
        }
        return l;
    }
    
    int cnt(vector<int> &pos,int d){
        int ans=1,cur=pos[0];
        for(int i=1;i<pos.size();++i){
            if(pos[i]-cur>=d){
                ans++;
                cur=pos[i];
            }
        }
        return ans;
    }
};