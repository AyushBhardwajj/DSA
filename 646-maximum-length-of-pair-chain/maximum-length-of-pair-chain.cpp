class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());

        int l = pairs[0][0];
        int r = pairs[0][1];

        int cnt = 1;

        for(int i=1;i<pairs.size();i++){
            if(r<pairs[i][0]){
                l = pairs[i][0];
                r = pairs[i][1];
                cnt++;
            }
            else{
                r = min(r,pairs[i][1]);
            }
        }

        return cnt;


    }
};