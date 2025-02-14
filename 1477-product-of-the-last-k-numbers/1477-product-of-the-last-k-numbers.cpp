class ProductOfNumbers {
public:
    vector<int> stream;
    void add(int num) {
        stream.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        int n = stream.size();
        for(int i = n-1;i>n-k-1;i--){
            prod *= stream[i];
        }
        return prod;
    }
};
