typedef long long int ll;
#define MAX_ANS 2e9

class Solution {
public:
    ll gcd(ll a, ll b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
    
    ll lcm(ll a, ll b) {
        return a * b / gcd(a, b);
    }
    
    int count(ll num, ll a, ll b, ll c) {
        return (int)(num / a + num / b + num / c
            - num / lcm(a, b)
            - num / lcm(b, c)
            - num / lcm(a, c)
            + num / (lcm(a, lcm(b, c))));
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        int l=0,r=MAX_ANS,res=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(count(m,a,b,c)>=n){
                res=m;
                r=m-1;
            } else {
                l=m+1;
            }
        }
        return res;
    }
};