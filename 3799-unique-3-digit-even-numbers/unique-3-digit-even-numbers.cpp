class Solution {
public:
    void solve(vector<int> &digits,unordered_set<int> &st,int mask,int curr,int digi){
        if(digi == 4){
            st.insert(curr);
            return;
        }

        for(int i=0;i<digits.size();i++){
            if((mask&(1<<i))!=0)continue;
            if(digi == 1 && digits[i]==0)continue;
            if(digi == 3 && digits[i]%2!=0)continue;

            int nmask = mask|(1<<i);

            int ncurr = curr*10 + digits[i];

            solve(digits,st,nmask,ncurr,digi+1);
        }

        return;
    }
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;

        solve(digits,st,0,0,1);

        return st.size();
    }
};