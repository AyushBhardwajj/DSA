class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        
        vector<pair<int,int>> vec(26,{-1,-1});

        int n = s.length();

        for(int i=0;i<n;i++){
            int ind = (int)(s[i]-'a');

            if(vec[ind].first == -1){
                vec[ind] = {i,i};
            }
            else vec[ind].second = i;
        }

        vector<pair<int,int>> vect;

        for(int i=0;i<26;i++){
            int start = vec[i].first;
            if(start == -1)continue;
            int end = vec[i].second;

            int l=start,e = end;

            do{
                start = l;
                end = e;
                for(int j=start;j<=end;j++){
                    int ind = (int)(s[j]-'a');
                    l = min({l,vec[ind].first,vec[ind].second});
                    e = max({e,vec[ind].second,vec[ind].first});
                }
            }while(start!=l || e!=end);

            //cout<<s.substr(l,e-l+1)<<" "<<i<<"\n";

            vect.push_back({l,e});
        }

        // sort(vect.begin(),vect.end(),[](pair<int,int> &a,pair<int,int> &b){
        //     return a.second<b.second;
        // });

        set<pair<int,int>> st;

        int k = vect.size();

        for(int i=0;i<k;i++){
            st.insert(vect[i]);
            //cout<<s.substr(vect[i].first,vect[i].second-vect[i].first+1)<<" ";
        }

        for(int i=0;i<k;i++){
            auto kt = st.find(vect[i]);
            if(kt == st.end())continue;

            for(int j=0;j<k;j++){
                if(i == j)continue;
                else if(vect[i].first>vect[j].first && vect[i].second<vect[j].second){
                    auto at = st.find(vect[j]);
                    if(at != st.end()){
                        st.erase(at);
                    }
                }
                else if(vect[i].first<vect[j].first && vect[i].second>vect[j].second){
                    auto pt = st.find(vect[i]);
                    st.erase(pt);
                    break;
                }
            }
        }

        vector<string> ans;

        //cout<<" "<<st.size()<<"\n";

        for(auto it:st){
            int start = it.first;
            int end = it.second;

            ans.push_back(s.substr(start,end-start+1));
        }

        return ans;
        
    }
};