class Solution {
public:
    bool isPerfectSquare(int num) {
        int ans=floor(sqrt(num));
        if(ans*ans==num)
            return true;
        return false;
    }
};