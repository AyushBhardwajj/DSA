class Solution {
public:
    vector<long long> prefix;
    vector<vector<int>> rects;
    long long tot = 0;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        for(int i=0;i<rects.size();i++){
            long long curr = 1ll*(rects[i][2] - rects[i][0]+1)*(rects[i][3] - rects[i][1]+1);
            tot  = tot+curr;
            prefix.push_back(tot);
        }
    }
    
    vector<int> pick() {
        long long r = rand()%tot + 1;

        int idx = lower_bound(prefix.begin(),prefix.end(),r)-prefix.begin();

        int x1 = rects[idx][0];
        int x2 = rects[idx][2];
        int y1 = rects[idx][1];
        int y2 = rects[idx][3];

        int x = x1 + rand()%(x2-x1+1);
        int y = y1 + rand()%(y2-y1+1);

        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */