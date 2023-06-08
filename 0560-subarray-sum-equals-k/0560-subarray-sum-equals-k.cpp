class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        
        //brute force
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
                
//                 int sum=0;
//                 for(int k=i;k<=j;k++)
//                     sum+=nums[k];
                
//                 if(sum==k)
//                     cnt++;
//             }
//         }
        
        //something better than brute force
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=nums[j];
                
//                 if(sum==k)
//                     cnt++;
//             }
//         }
        
        //optimal solution
        map<int,int> mp;
        int presum=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove=presum-k;
            cnt+=mp[remove];
            mp[presum]+=1;
        }
        
        return cnt;
    }
};