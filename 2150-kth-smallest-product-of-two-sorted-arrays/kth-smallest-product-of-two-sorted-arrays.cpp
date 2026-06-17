class Solution {
public:
    
    long long solve(vector<int> &nums1,vector<int> &nums2,long long mid){
        long long total = 0;

        int n = nums1.size();

        for(int i=0;i<n;i++){
            if(nums1[i]>=0){
                int l = 0,r = nums2.size()-1;

                while(l<=r){
                    int m = l + (r-l)/2;

                    long long curr = 1ll*nums1[i]*nums2[m];

                    if(curr<=mid){
                        l = m+1;
                    }
                    else{
                        r = m-1;
                    }
                }
                total += r+1;
            }
            else{
                int l = 0,r = nums2.size()-1;

                while(l<=r){
                    int m = l + (r-l)/2;

                    long long curr = 1ll*nums1[i]*nums2[m];

                    if(curr<=mid){
                        r = m-1;
                    }
                    else{
                        l = m+1;
                    }
                }
                int p = nums2.size();
                total += p-l;
            }
        }

        return total;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e15;
        long long right = 1e15;

        long long ans = 0;

        while(left<=right){
            long long mid = left + (right-left)/2;

            long long count = solve(nums1,nums2,mid);

            if(count>=k){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }

        return ans;
    }
};