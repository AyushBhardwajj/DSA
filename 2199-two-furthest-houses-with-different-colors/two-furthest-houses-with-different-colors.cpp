class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        int n = colors.size();
        int col1 = colors[n-1];
        int col2 = colors[0];

        for(int i=0;i<n;i++){
            if(col1!=colors[i]){
                ans = max(ans,n-1-i);
            }
            if(col2!=colors[i]){
                ans = max(ans,i);
            }
        }

        return ans;
    }
};