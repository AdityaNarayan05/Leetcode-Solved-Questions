class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // method 1
        // - using nth_element 
        // - 3-way-partition
        // 
        // Idea
        // - find the median first 
        // - using 3 index to represent 
        // from 0 to i-1 = values less than median 
        // from i to j-1 = valuse equals to median
        // from j to k = values are not yet stored
        // from k+1 to end = values are greater than median
        // 
        // Complexity
        // Time: O(N)
        // - nth_element is O(N) in average
        // Space: O(1)
        int n = nums.size();
        if (n < 2) return;
        
        // Find the median
        auto midprt = nums.begin() + n/2;
        nth_element(nums.begin(), midprt, nums.end());
        int mid = *midprt;

        // sort
        // [1,3,2,2,3,1], median = 2, n = 6
        // i = 4, j = 4, k = 1
        // [1,3,2,2,3,1]
        //          i
        //          j
        //  k
        // 
        int i = (n - 1) / 2 * 2, j = i, k = 1;
        for (int c = 0; c < n; ++c) {
        // while (n--) {
            if (nums[j] < mid) {
                swap(nums[i], nums[j]);
                i -= 2;
                j -= 2;
                if (j < 0) j = n / 2 * 2 - 1;
            } else if (nums[j] > mid) {
                swap(nums[j], nums[k]);
                k += 2;
            } else {
                j -= 2;
                if (j < 0) j = n / 2 * 2 - 1;
            }
        }
    }
};