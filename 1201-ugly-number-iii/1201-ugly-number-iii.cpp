typedef long long ll;
class Solution {
public:
    int nthUglyNumber(int N, int A, int B, int C) {
        ll a = A, b = B, c = C;
        ll low = 1, high = 2*1e9;
        ll ans = 1;
        ll ab = (a*b/__gcd(a, b));
        ll bc = (c*b/__gcd(c, b));
        ll ac = (a*c/__gcd(c, a));
        ll abc = (a*bc/__gcd(a, bc));
        while(low<=high){
            ll mid = low + (high - low)/2;
            ll cnt = mid/a + mid/b + mid/c - (mid/ab) - (mid/bc ) - (mid/ac) + mid/abc;

            if(cnt==N)
                ans = mid;
            if(cnt>=N)
                high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};