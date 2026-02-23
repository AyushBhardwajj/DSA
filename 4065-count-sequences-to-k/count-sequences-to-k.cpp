class Solution {
public:
    
    int solve(vector<int> &nums,int ind,long double n,long double d,long double k,unordered_map<int,unordered_map<long double,int>> &mp){
        if(ind == nums.size()){
            long double fin = n/d;
            if(fin == k)return 1;
            return 0;
        }

        if(mp.count(ind) && mp[ind].count(n/d))return mp[ind][n/d];

        

        int mul = 0,div = 0,leave = 0;
        
        
        mul = solve(nums,ind+1,n*nums[ind],d,k,mp);

        div = solve(nums,ind+1,n,d*nums[ind],k,mp);

        leave = solve(nums,ind+1,n,d,k,mp);

        return mp[ind][n/d] = (mul+div+leave);
    }
    int countSequences(vector<int>& nums, long long k) {
        long double val = 1.0;

        unordered_map<int,unordered_map<long double,int>> mp;
        
        long double n = 1.0,d = 1.0;
        return solve(nums,0,n,d,k,mp);
    }
};