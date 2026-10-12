class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long sum = 0;
        long long mod = 1e9+7;
        vector<int> vec(33,0);
        int n = nums.size();

        for(int i=0;i<n;i++){
            int ptt = nums[i];
            int cnt = 0;

            while(ptt>0){
                if(ptt&1){
                    vec[cnt]++;
                }

                ptt = ptt>>1;
                cnt++;
            }
        }

        while(k--){
            long long curr = 0;
            for(int i=32;i>=0;i--){
                if(vec[i]>0){
                    curr += pow(2,i);
                    vec[i]--;
                }
            }
            sum = (sum + curr*curr)%mod;
        }

        return sum;
    }
};