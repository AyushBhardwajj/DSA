class Solution {
public:
    long long binpow(long long a,long long b,long long mod){
        long long ans = 1;

        a = a%mod;

        while(b>0){
            if(b&1){
                ans = ans*a%mod;
            }

            a = a*a%mod;
            b = b>>1;
        }

        return ans;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        int n = variables.size();

        for(int i=0;i<n;i++){
            long long a = binpow(variables[i][0],variables[i][1],10ll);
            long long b = binpow(a,variables[i][2],variables[i][3]);

            int curr = (int)b;

            if(curr == target)ans.push_back(i);
        }

        return ans;
    }
};