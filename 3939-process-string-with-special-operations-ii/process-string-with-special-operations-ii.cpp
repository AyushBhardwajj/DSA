class Solution {
public:
    char processStr(string s, long long k) {
        long long tot = 0;

        for(int i = 0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z')tot++;
            else if(s[i]=='*'){
                if(tot>0)tot--;
            }
            else if(s[i]=='#'){
                tot = tot*2ll;
            }
        }

        if(tot<=k)return '.';

        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='*')tot++;
            else if(s[i]=='#'){
                tot = tot/2;
                if(k>=tot){
                    k = k-tot;
                }
            }
            else if(s[i]=='%'){
                k = tot-k-1;
            }
            else {
                tot--;
                if(tot<=k)return s[i];
            }
        }

        return '.';


    }
};