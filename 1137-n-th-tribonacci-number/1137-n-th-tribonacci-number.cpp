class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1||n==2)
            return 1;
        int i=0,j=1,k=1,t=0;
        while (n>=3)
        {
            n--;
            t= i+j+k;
            i=j;
            j=k;
            k=t;
        }
        return k;
    }
};