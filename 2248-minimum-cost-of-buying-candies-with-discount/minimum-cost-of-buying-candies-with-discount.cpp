class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());

        int n = cost.size();
        int ans = 0;

        for(int i=n-1;i>=0;i--){
            ans += cost[i];
            i--;
            if(i>=0){
                ans+=cost[i];
            }
            i--;
        }

        return ans;
    }
};