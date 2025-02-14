class ProductOfNumbers {
public:
// BRUTE FORCE APPROACH
    vector<int> stream;
    void add(int num) {
        stream.push_back(num);// 0(1) complexity isme lag rahi hai
    }
    
    int getProduct(int k) {
        int prod = 1;
        int n = stream.size();
        for(int i = n-1;i>n-k-1;i--){// isme 0(n) lag rahi hai
            prod *= stream[i];
        }
        return prod;
    }
};
