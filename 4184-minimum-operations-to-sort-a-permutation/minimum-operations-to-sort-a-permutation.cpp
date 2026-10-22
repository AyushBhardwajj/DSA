class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<int> srt = nums;

        sort(srt.begin(),srt.end());

        if(nums == srt)return 0;
        vector<int> rev = nums;

        reverse(rev.begin(),rev.end());

        if(srt == rev)return 1;

        int ans = 1e9;

        for(int i=0;i<n-1;i++){
            if(nums[i]+1!=nums[i+1]){
                vector<int> numt = nums;
                reverse(numt.begin(),numt.begin()+i+1);
                reverse(numt.begin()+i+1,numt.end());
                reverse(numt.begin(),numt.end());

                if(numt == srt){
                    ans = min({ans,i+1,n-i+1});
                }
                // reverse(numt.begin(),numt.end());

                // if(numt == srt){
                //     ans = min(ans,i+2);
                // }
                break;
            }
        }

        cout<<ans<<"\n";

        //reverse(nums.begin(),nums.end());

        for(int i=n-1;i>0;i--){
            if(nums[i]+1!=nums[i-1]){
                vector<int> numt = nums;
                reverse(numt.begin(),numt.begin()+i);
                reverse(numt.begin()+i,numt.end());
                //reverse(numt.begin(),numt.end());

                if(numt == srt){
                    ans = min({ans,i+1,n-i+1});
                }
                // reverse(numt.begin(),numt.end());

                // if(numt == srt){
                //     ans = min(ans,i+2);
                // }
                break;
            }
        }



        return ans==1e9?-1:ans;

    
    }
};