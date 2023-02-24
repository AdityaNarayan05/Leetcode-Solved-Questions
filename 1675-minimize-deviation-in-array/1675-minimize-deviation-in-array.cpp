class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int res=INT_MAX,Min=INT_MAX;
        priority_queue<int> pq;
        for(auto num:nums){
            num=num%2 ? num*2:num;
            pq.push(num);
            Min=min(Min,num);
        }
        while(pq.top()%2==0){
            res=min(res,pq.top()-Min);
            Min=min(Min,pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res,pq.top()-Min);
    }
};