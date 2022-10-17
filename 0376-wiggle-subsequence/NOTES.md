Following cases can be possible : -
​
nums[i] > nums[i-1] => peak=valley + 1
nums[i] < nums[i-1] => valley = peak + 1
nums[i] = nums[i-1] => do nothing and just iterate to the next element