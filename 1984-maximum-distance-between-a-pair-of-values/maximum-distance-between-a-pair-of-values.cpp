class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int frst = 0;

        int n = nums1.size();
        int m = nums2.size();

        int ans = 0;

        for(int i=0;i<n;i++){
            while(frst<m && nums2[frst]>=nums1[i]){
                frst++;
            }

            ans = max(ans,frst-i-1);
        }

        return ans;
    }
};