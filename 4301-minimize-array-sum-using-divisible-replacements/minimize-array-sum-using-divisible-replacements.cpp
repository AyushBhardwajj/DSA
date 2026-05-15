class Solution {
public:
    long long minArraySum(vector<int>& nums) {

        int nt = 100001;

        map<int,int> mp;

        sort(nums.begin(),nums.end());
        
        vector<int> vec(nt,0);

        for(int i=0;i<nums.size();i++){
            vec[nums[i]]++;
        }

        for(int i=0;i<nt;i++){
            if(vec[i]==0)continue;
            for(int j=2*i;j<nt;j+=i){
                if(vec[j]>0){
                    vec[i]+=vec[j];
                    vec[j] = 0;
                }
            }
        }

        long long ans = 0;

        for(int i=0;i<nt;i++){
            ans += 1ll*vec[i]*i;
        }

        return ans;
    }
};