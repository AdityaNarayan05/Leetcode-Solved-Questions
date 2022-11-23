class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int maxV=1;
        maxSum-=n;
        int layer=1;
        int points;
        while(maxSum>0){
            points=2*layer-1;
            int r=index+layer-1-(n-1);
            if(r>0)
                points-=r;
            
            int l=layer-index-1;
            if(l>0)
                points-=l;
            
            if (points >= n || maxSum < points)
                break;
            
            maxSum -= points;
            layer++;
            maxV++;
        }
        return maxV+=maxSum/n;
    }
};