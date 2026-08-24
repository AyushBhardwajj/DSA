class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prim(1e5+1,-1);

        for(int i=0;i<=1e5;i++){
            prim[i] = i;
        }

        for(int i=2;i<=sqrt(1e5);i++){
            if(prim[i]!=i)continue;
            for(int j=i*i;j<=1e5;j+=i){
                if(prim[j]==j)prim[j] = i;
            }
        }

        //cout<<prim[6]<<" ";

        int l = 0,r = 0;

        map<int,int> mp;

        vector<vector<int>> vec(n);

        for(int i=0;i<n;i++){
            int curr = nums[i];

            while(curr>1){
                vec[i].push_back(prim[curr]);
                int spf = prim[curr];
                while((curr%spf) == 0){
                    curr = curr/spf;
                }
            }
        }

        int ans = 0;

        while(r<n){
            int t = vec[r].size();

            for(int j=0;j<t;j++){
                mp[vec[r][j]]++;
            }

            int m = mp.size();

            while(m>k){

                int nt = vec[l].size();

                for(int j=0;j<nt;j++){
                    mp[vec[l][j]]--;
                    if(mp[vec[l][j]] == 0){
                        mp.erase(vec[l][j]);
                    }
                }

                m = mp.size();
                l++;
            }

            ans = max(ans,r-l+1);
            r++;
        }

        // cout<<vec[0].size()<<" ";
        // cout<<vec[1].size()<<" ";
        // cout<<vec[2].size()<<" ";

        return ans;
    }
};