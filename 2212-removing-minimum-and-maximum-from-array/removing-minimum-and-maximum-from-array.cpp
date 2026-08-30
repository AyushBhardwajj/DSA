class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int frst1 = (int)(min_element(nums.begin(),nums.end()) - nums.begin());
        int frst2 = (int)(max_element(nums.begin(),nums.end()) - nums.begin());

        int last1 = n-frst1;
        int last2 = n-frst2;

        frst1++;
        frst2++;

        int ans = n;
        ans = min(ans,max(frst1,frst2));
        ans = min(ans,max(last1,last2));

        ans = min(ans,frst1+last2);
        ans = min(ans,frst2+last1);

        return ans;
    }
};