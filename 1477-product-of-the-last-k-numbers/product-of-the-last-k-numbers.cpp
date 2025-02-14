class ProductOfNumbers {
public:
    vector<int>vc,prod;
    priority_queue<int>pq;
    int mul=1,i=0;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        vc.push_back(num);
        mul=mul*num;
        prod.push_back(mul);
        if(mul==0){
            mul=1;
            pq.push(i);
        }
        i++;
    }
    
    int getProduct(int k) {
        int size=vc.size()-k;
        if(size==0){
            if(!pq.empty()) return 0;
            return prod[prod.size()-1];
        }
        if(!pq.empty() && size<=pq.top()) return 0;
        if(prod[size-1]==0){
            return prod[prod.size()-1];
        }
        return prod[prod.size()-1]/prod[size-1];  
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */