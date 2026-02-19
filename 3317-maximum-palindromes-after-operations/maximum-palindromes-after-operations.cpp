class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int ans = 0;

        int n = words.size();
        vector<int> vec(26,0);

        vector<pair<int,string>> vect;

        for(int i=0;i<words.size();i++){
            vect.push_back({words[i].size(),words[i]});
        }

        sort(vect.begin(),vect.end());

        for(int i=0;i<n;i++){
            words[i] = vect[i].second;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                vec[words[i][j]-'a']++;
            }
        }

        for(int i=0;i<n;i++){
            int siz = words[i].size();
            bool flag = true;
            if(siz%2)flag = false;

            if(siz%2){
                for(int k=0;k<26;k++){
                    if(vec[k]%2){
                        vec[k]--;
                        flag = true;
                        siz--;
                        break;
                    }
                }
            }

            if(flag==false){
                for(int k=0;k<26;k++){
                    if(vec[k]>0){
                        vec[k]--;
                        siz--;
                        flag = true;
                        break;
                    }
                }
            }

            if(siz == 0){
                ans++;
                continue;
            }

            for(int j=0;j<26;j++){
                if(vec[j]>1){
                    if(vec[j]>=siz){
                        vec[j]-=siz;
                        siz = 0;
                    }
                    else{
                        siz -= (vec[j]/2)*2;
                        vec[j]-=(vec[j]/2)*2;
                    }
                }
                if(siz == 0)break;
            }

            if(siz == 0)ans++;
        }

        return ans;
    }
};