class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right) {
            int m = nums[right];
            int mid = (left + right) /2;
            if(nums[mid] == m) {
                    right--;
                    continue;
                }
            if(nums[mid] <= m) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[right];
    }
};