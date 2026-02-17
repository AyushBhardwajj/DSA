class Solution {
public:
    void solve(int hrs,int minutes,set<string> &st,int k){
        if(k==0){
            if(hrs<=11 && minutes<=59){
                string h = to_string(hrs);
                string min = to_string(minutes);

                if(min.length()==1){
                    min = "0"+min;
                }

                h = h+":"+min;

                st.insert(h);
            }
            return;
        }

        if(k>0){
            for(int i=0;i<4;i++){
                if(hrs&(1<<i))continue;
                int nhrs = hrs|(1<<i);
                if(nhrs>11)break;
                solve(nhrs,minutes,st,k-1);
            }
        }

        if(k>0){
            for(int i=0;i<6;i++){
                if(minutes&(1<<i))continue;
                int mint = minutes|(1<<i);
                if(mint>59)break;
                solve(hrs,mint,st,k-1);
            }
        }

        return ;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        set<string> st;
        solve(0,0,st,turnedOn);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};