class Solution {
public:
    vector<vector<int>> subs;
    vector<int> sub;
    
    void subset(vector<int> nums,int i){
        if(i==nums.size()){
            subs.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        cout<<i<<endl;
        subset(nums,i+1);
        sub.pop_back();
        subset(nums,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        subset(nums,0);
        return subs;    
    }
};