class Solution {
public:
    //heap sort using stl
    vector<int> sortArray(vector<int>& nums) {
        priority_queue <int, vector<int>, greater<int> > pq;
        for(auto num : nums){
            pq.push(num);
        }
        int i=0;
        while(!pq.empty()){
            nums[i++]=pq.top();
            pq.pop();
        }
        return nums;
    }
};