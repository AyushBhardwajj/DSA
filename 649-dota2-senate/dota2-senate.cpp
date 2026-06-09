class Solution {
public:
    string predictPartyVictory(string senate) {

        queue<char> q;

        int n = senate.length();
        int cntr = 0;
        int cntd = 0;
        int minusr =0 ;
        int minusd = 0;

        for(int i=0;i<n;i++){
            q.push(senate[i]);
            if(senate[i]=='R')cntr++;
            else cntd++;
        }

        while(true){
            if(cntr == 0)return "Dire";
            if(cntd == 0)return "Radiant";

            if(q.front()=='R'){
                if(minusr>0){
                    minusr--;
                    cntr--;
                    q.pop();
                }
                else{
                    minusd++;
                    q.push('R');
                    q.pop();
                }
            }
            else{
                if(minusd>0){
                    minusd--;
                    cntd--;
                    q.pop();
                }
                else{
                    minusr++;
                    q.push('D');
                    q.pop();
                }
            }
        }

        return "";


    }
};