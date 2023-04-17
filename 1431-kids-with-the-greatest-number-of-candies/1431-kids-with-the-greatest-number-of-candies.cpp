class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
        vector<bool> res;
        int maxCand = *max_element(candies.begin(), candies.end());
        
        for(int i=0; i < candies.size(); i++){
            res.push_back(candies[i]+extraCandies >= maxCand);
        }
        return res;
    }
};