class ProductOfNumbers {
public:
    vector<int>p;
    ProductOfNumbers() {
        p.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            p.clear();
            p.push_back(1);
        }
        else{
            p.push_back(p.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n=p.size();
        if(k>=n) return 0;
        return p.back()/p[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */