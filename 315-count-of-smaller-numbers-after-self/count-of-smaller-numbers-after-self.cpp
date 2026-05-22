class Solution {
public:
    void merge(vector<pair<int,int>> &vect,vector<int> &ans,int l,int mid,int r){
        int l1 = l,l2 = mid+1;

        int cnt = 0;

        vector<pair<int,int>> curr;

        while(l1<=mid && l2<=r){
            if(vect[l1].first <= vect[l2].first){
                curr.push_back(vect[l1]);
                ans[vect[l1].second] += l2-mid-1;
                l1++;
            }
            else{
                curr.push_back(vect[l2]);
                l2++;
            }
        }

        while(l1<=mid){
            curr.push_back(vect[l1]);
            ans[vect[l1].second] += l2-mid-1;
            l1++;
        }

        while(l2<=r){
            curr.push_back(vect[l2]);
            l2++;
        }

        for(int i=l;i<=r;i++){
            vect[i] = curr[i-l];
        }
    }

    void mergeSort(vector<pair<int,int>> &vect,vector<int> &ans,int l,int r){
        if(l>=r){
            return;
        }

        int mid = (l+r)/2;

        mergeSort(vect,ans,l,mid);
        mergeSort(vect,ans,mid+1,r);
        merge(vect,ans,l,mid,r);
    }
    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(n,0);
        // reverse(nums.begin(),nums.end());
        vector<pair<int,int>> vect;

        for(int i=0;i<n;i++){
            vect.push_back({nums[i],i});
        }

        mergeSort(vect,ans,0,n-1);

        return ans;
    }
};