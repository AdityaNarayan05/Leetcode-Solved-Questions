class Solution {
public:
    int countPrimes(int n) {
        vector<bool> notPrime(n);
        int cnt=0;
        for(int i=2;i<n;i++){
            if(notPrime[i]==false){
                cnt++;
                for(int j=2;i*j<n;j++)
                    notPrime[i*j]=true;
            }
        }
        return cnt;
    }
};