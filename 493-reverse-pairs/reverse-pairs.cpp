class Solution {
public:
    int ans;
    
    void merge(vector<int> &nums,int l,int mid,int r){
        int l1 = l, l2 = mid+1;

        vector<int> temp;

        while(l1<=mid && l2<=r){
            long long crr = nums[l1];
            long long prr = nums[l2];
            if(crr>2ll*prr){
                ans+=mid-l1+1;
                l2++;
            }
            else l1++;
        }

        l1 = l,l2 = mid+1;

        while(l1<=mid && l2<=r){
            if(nums[l1]<=nums[l2]){
                temp.push_back(nums[l1]);
                l1++;
            }
            else{
                temp.push_back(nums[l2]);
                l2++;
            }
        }

        while(l1<=mid){
            temp.push_back(nums[l1]);
            l1++;
        }

        while(l2<=r){
            temp.push_back(nums[l2]);
            l2++;
        }

        for(int i=l;i<=r;i++){
            nums[i] = temp[i-l];
        }

        return;
    }

    void part(vector<int> &nums,int l,int r){
        if(l>=r)return;

        int mid = (l+r)/2;

        part(nums,l,mid);
        part(nums,mid+1,r);
        merge(nums,l,mid,r);

        return;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        ans = 0;

        part(nums,0,n-1);

        return ans;
    }
};