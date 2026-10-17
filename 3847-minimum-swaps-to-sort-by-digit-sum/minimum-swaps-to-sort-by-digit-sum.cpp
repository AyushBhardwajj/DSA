class Solution {
public:
    
    void dfs(int node,vector<int> &arr,int &cnt,vector<int> &vis){
        vis[node] = 1;
        cnt++;
        if(vis[arr[node]]==0){
            dfs(arr[node],arr,cnt,vis);
        }
    }

    int minSwaps(vector<int>& nums) {
        vector<vector<int>> vec(82);
        map<int,int> mp2;

        int n = nums.size();

        for(int i=0;i<n;i++){
            int val = nums[i];
            int sum = 0;
            while(val>0){
                sum += val%10;
                val = val/10;
            }

            vec[sum].push_back(nums[i]);
        }

        vector<int> ans;

        for(int i=0;i<82;i++){
            if(vec[i].empty())continue;
            sort(vec[i].begin(),vec[i].end());
            ans.insert(ans.end(),vec[i].begin(),vec[i].end());
        }

        for(int i=0;i<n;i++){
            mp2[ans[i]]=i;
        }

        vector<int> arr(n,0);

        for(int i=0;i<n;i++){
            int pos2 = mp2[nums[i]];
            arr[i] = pos2;
        }

        vector<int> vis(n,0);
        int anst = 0;

        for(int i=0;i<n;i++){
            if(vis[i]==1)continue;
            int cnt = 0;
            dfs(i,arr,cnt,vis);
            anst += cnt-1;

        }

        return anst;

    }
};