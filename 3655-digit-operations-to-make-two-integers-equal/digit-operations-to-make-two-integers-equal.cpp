class Solution {
public:
    int minOperations(int n, int m) {
        vector<int> vec(1e6,1);
        vec[1] = 0;
        vec[0] = 0;
        for(int i=2;i<1000;i++){
            if(vec[i]==0)continue;

            for(int j=i*i;j<1e6;j+=i){
                vec[j] = 0;
            }
        }
        if(vec[m] || vec[n])return -1;
        unordered_map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({n,n});
        mp[n]=1;
        while(!pq.empty()){
            int sum = pq.top().first;
            int val = pq.top().second;
            pq.pop();

            if(val == m)return sum;

            int curr = 1;
            string str = to_string(val);
            reverse(str.begin(),str.end());
            int ind = 0;

            while(true){
                if(curr>val)break;
                if(str[ind]!='9'){
                    int nval = val+curr;
                    if(!mp.count(nval) && !vec[nval]){
                        pq.push({sum+nval,nval});
                        mp[nval] = 1;
                    }
                }
                ind++;
                curr = curr*10; 
            } 

            curr=1,ind = 0;

            while(true){
                if(curr>val)break;
                if(str[ind]!='0'){
                    int nval = val-curr;
                    if(!mp.count(nval) && !vec[nval]){
                        pq.push({sum+nval,nval});
                        mp[nval] = 1;
                    }
                }
                ind++;
                curr = curr*10;
            }
        
        }

        return -1;
    }
};