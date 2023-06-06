class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int d=arr[1]-arr[0];
        
        for(int i=2;i<n;i++)
            if(arr[i]-arr[i-1]!=d)
                return false;
        
        return true;
    }
};