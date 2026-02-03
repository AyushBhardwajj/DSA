class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 1;

        while (i < n && nums[i] > nums[i - 1]) i++;
        if (i == 1 || i == n) return false;

        int j = i;
        while (j < n && nums[j] < nums[j - 1]) j++;
        if (j == i || j == n) return false;

        while (j < n) {
            if (nums[j] <= nums[j - 1]) return false;
            j++;
        }

        return true;
    }
};
