class Solution {
public:
    vector<vector<int>> rects;
    vector<long long> cF;
    long long sumt = 0;

    Solution(vector<vector<int>>& rects) {
        long long sum = 0;
        this->rects = rects;
        cF.push_back(0);

        for(int i=0;i<rects.size();i++){
            long long x1 = rects[i][0];
            long long y1 = rects[i][1];
            long long x2 = rects[i][2];
            long long y2 = rects[i][3];

            long long curr = 1ll*(x2-x1+1)*(y2-y1+1);
            sum += curr;

            cF.push_back(sum);
        }

        this->sumt = sum;

    }
    
    vector<int> pick() {
        long long freq = rand()%sumt + 1;

        int ind = lower_bound(cF.begin(),cF.end(),freq) - cF.begin();

        int count = freq - cF[ind-1];
        count--;

        int x1 = rects[ind-1][0];
        int y1 = rects[ind-1][1];
        int x2 = rects[ind-1][2];
        int y2 = rects[ind-1][3];

        int y3 = y1+count/(x2-x1+1);
        int x3 = x1+count%(x2-x1+1);

        return {x3,y3};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */