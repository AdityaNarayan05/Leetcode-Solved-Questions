#include<bits/stdc++.h>
class Solution {
public:
    
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         multiset<int,greater<int>> s;
//         vector<int> ans;
//         for(int i=0;i<k;i++)
//             s.insert(nums[i]);
        
//         ans.push_back(*s.begin());
//         for(int i=k;i<nums.size();i++){
//             s.erase(s.lower_bound(nums[i-k]));
//             s.insert(nums[i]);
//             ans.push_back(*s.begin());
//         }
//         return ans;
//     }
    
    // Heap solution 
    
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> ans;  
    
        for(int i=0;i<nums.size();++i){
            while(!pq.empty() and pq.top().second<=(i-k))
                pq.pop();
            pq.push({nums[i],i}); 
            if(i>=k-1){
                ans.push_back(pq.top().first);
                // cout<<pq.top().first<<" ";
            }          
        }
        return ans; 
    }

    
    // Deque solution
    
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     deque<pair<int,int>> dq;
    //     vector<int> ans;
    //     for(int i=0;i<nums.size();i++){
    //         if(!dq.empty() and dq.front().second<=(i-k))
    //             dq.pop_front();
    //         while(!dq.empty() and dq.back().first<nums[i])
    //             dq.pop_back();
    //         dq.push_back({nums[i],i});
    //         if(i>=k-1){
    //             ans.push_back(dq.front().first);
    //             // cout<<dq.front().first<<" ";
    //         } 
    //     }
    //     return ans;
    // }
    
    
};