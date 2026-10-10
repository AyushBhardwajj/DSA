class Solution {
public:
    long long solve(int mid,vector<int> &nums1,vector<int> &nums2,int k1,int k2){
        for(int i=0;i<nums1.size();i++){
            int diff = abs(nums1[i]-nums2[i]);
            if(diff<=mid)continue;
            int need = diff-mid;
            if(k1+k2<need){
                return -1;
            }
            if(k1<need){
                need = need-k1;
                k1 = 0;
                k2-=need;
            }
            else{
                k1-=need;
            }
        }

        return k1+k2;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long low = 0,high = 1e5;

        long long diff = 1e5;
        long long ans = 0;
        long long rem = 0;

        while(low<=high){
            long long mid = (low+high)/2;

            long long f = solve(mid,nums1,nums2,k1,k2);

            if(f == -1){
                low = mid+1;
            }
            else{
                rem = f;
                diff = mid;
                high = mid-1;
            }
        }

        if(diff == 0)return 0;
        vector<vector<int>> adj;
        cout<<rem<<"\n";
        

        for(int i=0;i<nums1.size();i++){
            long long curr = abs(nums1[i]-nums2[i]);
            if(curr>=diff){
                if(rem>0){
                    ans += (diff-1)*(diff-1);
                    rem-=1;
                }
                else ans += diff*diff;
            }
            else{
                ans += curr*curr;
            }
        }

        cout<<diff<<"\n";

        return ans;


    }
};