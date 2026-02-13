class Solution {
public:
    int longestBalanced(string s) {
        int a = 0,b = 0,c = 0;

        int ans = 0;

        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
                b=0;
                c=0;
            }
            else if(s[i]=='b'){
                b++;
                a = 0;
                c = 0;
            }
            else{
                c++;
                a = 0;
                b = 0;
            }

            ans = max({ans,a,b,c});
        }

        int last = -1;
        map<int,int> mp;

        a = 0,b = 0;
        mp[0]=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='c'){
                a =0;
                b =0;
                last = i;
            }
            else if(s[i]=='a'){
                a++;
            }
            else b++;

            int diff = a-b;

            if(mp.find(diff)!=mp.end()){
                if(mp[diff]>=last){
                    ans = max(ans,i-mp[diff]);
                }
                else{
                    mp[diff] = i;
                }
            }
            else{
                mp[diff] = i;
            }
        }

        a = 0,b = 0,c = 0;
        last = -1;
        map<int,int> mp1;
        mp1[0]=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                b =0;
                c =0;
                last = i;
            }
            else if(s[i]=='b'){
                b++;
            }
            else c++;

            int diff = b-c;

            if(mp1.find(diff)!=mp1.end()){
                if(mp1[diff]>=last){
                    ans = max(ans,i-mp1[diff]);
                }
                else{
                    mp1[diff] = i;
                }
            }
            else{
                mp1[diff] = i;
            }
        }

        a = 0,b = 0,c = 0;
        last = -1;
        map<int,int> mp2;
        mp2[0]=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                a =0;
                c =0;
                last = i;
            }
            else if(s[i]=='a'){
                a++;
            }
            else c++;

            int diff = a-c;
            

            if(mp2.find(diff)!=mp2.end()){
                if(mp2[diff]>=last){
                    ans = max(ans,i-mp2[diff]);
                }
                else{
                    mp2[diff] = i;
                }
            }
            else{
                mp2[diff] = i;
            }
        }

        a = 0,b=0,c=0;

        map<string,int> mp4;

        mp4["0&0"]=-1;

        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            else if(s[i]=='b')b++;
            else c++;

            int diff1 = a-b;
            int diff2 = b-c;

            string str = to_string(diff1)+"&"+to_string(diff2);

            if(mp4.find(str)!=mp4.end()){
                ans = max(ans,i-mp4[str]);
            }
            else{
                mp4[str] = i;
            }
        }

        return ans;


    }
};