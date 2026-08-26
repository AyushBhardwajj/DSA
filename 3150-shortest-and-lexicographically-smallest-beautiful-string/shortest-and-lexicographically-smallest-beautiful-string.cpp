class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        priority_queue<string> pq;

        int one = 0;

        int n = s.length();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(s[j]=='1')one++;
                if(one == k){
                    string st = s.substr(i,j-i+1);
                    pq.push(st);
                }
                int siz = pq.size();

                if(siz > 1){
                    string n1  = pq.top();
                    pq.pop();
                    string n2 = pq.top();
                    pq.pop();

                    int len1 = n1.length();
                    int len2 = n2.length();

                    if(len1>len2){
                        pq.push(n2);
                    }
                    else if(len2>len1){
                        pq.push(n1);
                    }
                    else{
                        pq.push(n1);
                        pq.push(n2);
                        pq.pop();
                    }
                }

                if(one > k)break;
            }

            one = 0;
        }

        int siz = pq.size();

        if(siz == 0)return "";

        return pq.top();

    }
};