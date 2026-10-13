class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[&](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]>b[0];
        });
        int n = people.size();

        vector<vector<int>> ans(n,{-1,-1});
        vector<int> sample = {-1,-1};

        for(int i=0;i<n;i++){
            int ind = people[i][1];

            if(ans[ind] == sample){
                ans[ind] = people[i];
            }
            else{
                for(int j=n-2;j>=ind;j--){
                    ans[j+1] = ans[j];
                }
                ans[ind] = people[i];
            }
        }

        return ans;
    }
};