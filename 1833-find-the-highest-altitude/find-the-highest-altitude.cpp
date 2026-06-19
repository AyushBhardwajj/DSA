class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int val = 0;
        int ans = 0;

        for(int i=0;i<gain.size();i++){
            val += gain[i];
            ans = max(ans,val);
        }

        return ans;
        
    }
};