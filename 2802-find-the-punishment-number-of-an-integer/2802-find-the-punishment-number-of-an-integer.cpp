class Solution {
public:
// khandani template of backtracking
bool solve(int n,int idx){
    // base case
    if(idx < 0 || idx > n) return false;
    
    if(n == idx){
        return true;
    }
    return solve(n/10,idx - n % 10) || solve(n/100, idx - n % 100) || solve(n/1000, idx - n%1000);
}
    int punishmentNumber(int n) {
        int count = 0;
        for(int i=1;i<=n;i++){
            int square = i * i;
            if(solve(square,i)){
                count += square;
            }
        }
        return count;
    }
};