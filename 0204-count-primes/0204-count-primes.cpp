class Solution {
public:
    int countPrimes(int n) {
        int ans =0;
        vector<bool> temp(n,1);
        
        for(int i=2;i<n;i++){
            if(temp[i]){
                ans++;
                for(int j =2*i;j<n;j=j+i)
                temp[j]=0;
            }
        }
        
        return ans;
    }
};