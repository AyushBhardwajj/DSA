class Solution {
public:
    long long binpow(long long base,long long pow,long long mod){
        long long ans = 1;
        while(pow>0){
            if(pow&1)ans = (ans*base)%mod;

            base = (base*base)%mod;

            pow = pow/2;
        }

        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        
        int n = nums.size();
        long long ans = 0,mod = 1e9+7;

        for(int i=0;i<n;i++){
            long long curr = nums[i];

            int w = curr%10;
            int d = curr/10;

            vector<int> vec;

            while(curr>0){
                int ele = curr%10;
                vec.push_back(ele);
                curr = curr/10;
            }

            reverse(vec.begin(),vec.end());

            int k = vec.size();

            long long x = 0,y=0;
            int j = 0;

            for(j=0;j<w;j++){
                x = x*10 + vec[j];
            }

            for(;j<k-1;j++){
                y = y*10 + vec[j];
            }

            ans  =  (ans + binpow(x,y,mod))%mod;



        }

        return ans;
    }
};