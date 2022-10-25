class Solution {
public:
    int getSum(int a, int b) {
        if(b==0)
            return a;
        int sum_without_carry = a^b;
        int carry = (unsigned int)(a&b)<<1;
        return getSum(sum_without_carry, carry);
    }
};