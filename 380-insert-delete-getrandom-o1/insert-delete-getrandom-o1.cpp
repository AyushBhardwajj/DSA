#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

class RandomizedSet {
public:
    ordered_set st;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(st.find(val)==st.end()){
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.find(val) == st.end()){
            return false;
        }

        st.erase(val);

        return true;
    }
    
    int getRandom() {
        int siz = st.size();
        int ind = rand()%siz;

        return *st.find_by_order(ind);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */