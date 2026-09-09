class Solution {
public:
    int solve(vector<int> &vec,int ind,int mask){
        int n = vec.size();
        if(mask == ((1<<n)-1))return 1;

        int ans =0;

        for(int i=0;i<vec.size();i++){
            if((mask&(1<<i)) != 0)continue;

            if(vec[i]%ind != 0 && ind%vec[i] !=0)continue;

            int nmask = mask|(1<<i);

            ans += solve(vec,ind+1,nmask);
        }

        return ans;
    }
    int countArrangement(int n) {
        vector<int> vec(n);

        for(int i=0;i<n;i++){
            vec[i] = i+1;
        }

        int mask = 0;

        return solve(vec,1,mask);
    }
};