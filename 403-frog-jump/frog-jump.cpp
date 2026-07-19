class Solution {
public:
    bool solve(int k,int ind,vector<int> &stones,unordered_map<int,unordered_map<int,bool>> &mp){
        if(ind == (stones.size()-1))return true;

        if(mp.count(k) && mp[k].count(ind)){
            return mp[k][ind];
        }

        for(int i=-1;i<=1;i++){
            int curr = (int)(stones[ind]+k+i);
            if(curr <= stones[ind])continue;
            auto it = lower_bound(stones.begin(),stones.end(),curr);
            if(it == stones.end() || (*it) != curr)continue;
            int ind2 = it-stones.begin();

            if(solve(k+i,ind2,stones,mp))return true;
        }

        return mp[k][ind] = false;
    }
    bool canCross(vector<int>& stones) {
        if((stones[1] - stones[0]) != 1) return false;
        unordered_map<int,unordered_map<int,bool>> mp;
        return solve(1,1,stones,mp);
    }
};