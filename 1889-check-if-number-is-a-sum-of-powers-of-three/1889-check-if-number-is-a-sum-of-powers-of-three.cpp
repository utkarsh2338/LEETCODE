class Solution {
public:
    string toBase3(int n) {
    if (n == 0) return "0"; 

    string base3 = "";
    while (n > 0) {
        base3 = char((n % 3) + '0') + base3; 
        n /= 3;
    }
    return base3;
}
    bool checkPowersOfThree(int n) {
        // convert n to base 3
        string ans = toBase3(n);
        int len = ans.length();
        for(char ch: ans){
            if(ch != '0' && ch != '1'){
                return false;
            }
        }
        return true;
    }
};