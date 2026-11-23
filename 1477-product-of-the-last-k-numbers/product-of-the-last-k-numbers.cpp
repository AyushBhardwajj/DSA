class ProductOfNumbers {
public:
   
    int zeros;
    int prod;
    vector<int> vec;
    
    ProductOfNumbers() {
        vec.push_back(1);
        zeros = 0;
        prod = 1;
    }


    
    void add(int num) {
        prod = prod*num;
        vec.push_back(prod);
        if(prod==0){
            zeros = vec.size()-1;
            prod = 1;
        }

    }
    
    int getProduct(int k) {
        int last_ind = vec.size()-k;
        if(zeros>=last_ind)return 0;

        if(vec[last_ind-1]==0)return vec[vec.size()-1];
        
        return vec[vec.size()-1]/vec[last_ind-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */