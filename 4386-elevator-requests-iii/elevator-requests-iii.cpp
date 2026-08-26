// class Solution {
// public:
//     long long solve(int tot,int floor,int start,int bit,vector<vector<int>> &req){
//         if(bit == tot){
//             long long crr = abs(start - req[floor][1]);
//             crr = max(crr,1ll*req[floor][0]);
//             return crr;
//         }

//         long long ans = 1e15;

//         int n = req.size();

//         for(int i=0;i<n;i++){
//             if((bit&(1<<i)) == 0){
//                 int nbit = (bit|(1<<i));

//                 long long curr = solve(tot,i,start,nbit,req);

//                 long long diff = abs(req[floor][1] - req[i][1]);

//                 long long need = curr + diff;

//                 need = max(need,1ll*req[i][0]);

//                 ans = min(ans,need);
//             }
//         }

//         return ans;
//     }
//     long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
//         int nt = requests.size();

//         int tot = (1<<nt)-1;

//         long long ans = 1e15;

//         for(int i=0;i<nt;i++){
//             ans = min(ans,solve(tot,i,start,(1<<i),requests));
//         }

//         return ans;
//     }
// };
class Solution {
public:
    
    long long dp[(1<<16)][16];

    long long solve(int floor, int bit, int start,vector<vector<int>>& req) {

        if(bit == 0) {
            return max(1LL * abs(req[floor][1] - start),1LL * req[floor][0]);
        }

        if(dp[bit][floor]!=-1)return dp[bit][floor];

        long long ans = 1e18;

        int n = req.size();

        for(int i = 0; i < n; i++) {

            if(bit & (1 << i)) {

                int nbit = bit & ~(1 << i);

                long long curr = solve(i, nbit, start, req);

                long long diff = abs(req[floor][1] - req[i][1]);

                long long need = curr + diff;

                need = max(need,1LL * req[floor][0]);

                ans = min(ans, need);
            }
        }

        return dp[bit][floor] = ans;
    }

    long long elevatorRequests(int n,int start,vector<vector<int>>& requests) {

        int nt = requests.size();

        int tot = (1 << nt) - 1;

        long long ans = 1e18;

        for(int i = 0; i < nt; i++) {

            int mask = tot & ~(1 << i);

            memset(dp,-1,sizeof(dp));

            ans = min(ans,solve(i, mask, start, requests));
        }

        return ans;
    }
};