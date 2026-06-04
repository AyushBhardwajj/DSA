class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());

        int ans = 0;

        for(int i=0;i<houses.size();i++){
            int pos = houses[i];

            int curr = INT_MAX;

            auto it = lower_bound(heaters.begin(),heaters.end(),pos);

            if(it != heaters.end()){
                int ind = it-heaters.begin();
                curr = min(curr,abs(heaters[ind]-houses[i]));
            }

            if(it != heaters.begin()){
                it--;
                int ind = it-heaters.begin();
                curr = min(curr,abs(heaters[ind]-houses[i]));
            }

            ans = max(ans,curr);
        }

        return ans;
    }
};