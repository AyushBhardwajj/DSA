class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> stones = {a,b,c};

        sort(stones.begin(),stones.end());

        int maxt = stones[1]-stones[0]-1+stones[2]-stones[1]-1;

        int cnt = 0;

        if(stones[1]-stones[0]-1>1 && stones[2]-stones[1]-1>1)cnt=2;
        else if(stones[1]-stones[0]-1>0 || stones[2]-stones[1]-1>0)cnt=1;
        
        return {cnt,maxt};
    }
};