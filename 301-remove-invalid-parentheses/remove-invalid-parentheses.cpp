class Solution {
public:
    int solve(int ind,string &s,int cnt){
        if(ind == s.length()){
            if(cnt == 0)return 0;
            return 1e8;
        }

        int take = 1e8,nottake = 1e8;

        if(s[ind]=='('){
            cnt++;
            take = solve(ind+1,s,cnt);
            cnt--;
        }
        else if(s[ind]==')' && cnt>0){
            cnt--;
            take = solve(ind+1,s,cnt);
            cnt++;
        }
        else if(s[ind]!=')' && s[ind]!='('){
            take = solve(ind+1,s,cnt);
        }

        nottake = 1+solve(ind+1,s,cnt);

        return min(take,nottake);
    }
    void solve2(int ind,int k,int bits,string &s,int cnt,vector<int> &ans){
        if(ind == s.length()){
            if(cnt == 0){
                ans.push_back(bits);
            }
            return;
        }

        if(s[ind]!='(' && s[ind]!=')'){
            int nbits = bits|(1<<ind);
            solve2(ind+1,k,nbits,s,cnt,ans);
        }
        else if(s[ind]=='('){
            int nbits = bits|(1<<ind);
            solve2(ind+1,k,nbits,s,cnt+1,ans);
        }
        else{
            if(cnt == 0){
                if(k>0){
                    solve2(ind+1,k-1,bits,s,cnt,ans);
                }
                else return;
            }
            else{
                int nbits = bits|(1<<ind);
                solve2(ind+1,k,nbits,s,cnt-1,ans);
            }

        }

        if(k>0){
            solve2(ind+1,k-1,bits,s,cnt,ans);
        }


        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        stack<char> st;
        int cnt = 0;
        int k = solve(0,s,cnt);

        vector<int> ans;
        int bits = 0;

        solve2(0,k,bits,s,cnt,ans);

        vector<string> anst;
        unordered_set<string> curr;

        for(int i=0;i<ans.size();i++){
            int num = ans[i];
            int ind = 0;
            string str="";
            while(num){
                if(num&1){
                    str.push_back(s[ind]);
                }

                ind++;
                num = num/2;
            }

            curr.insert(str);
        }

        //vector<string> anst;

        for(auto it:curr){
            anst.push_back(it);
        }

        return anst;
    }
};