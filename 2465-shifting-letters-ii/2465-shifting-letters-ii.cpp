// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         int n = shifts.size();// no. of rows
//         int m = shifts[0].size();// no. of columns
//         for(int i=0;i<n;i++){
//             int st = shifts[i][0];
//             int end = shifts[i][1];
//             for(int j = st;j<=end;j++){
//                 if(shifts[i][3] == 0){
//                     // forward shifting
//                     s[j] = (s[j] -'a' +1 )%26 + 'a';
//                 }
//                 else{
//                     // backward shifting
//                     s[j] = (s[j] -'a' -1 + 26)%26 + 'a';//To prevent underflow (negative values) during backward shifts, add 26 before applying modulo.
//                 }
//             }
//         }
//         return s;
//     }
// };



class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shift(n + 1, 0);

        // Process the shifts
        for (auto& shiftOp : shifts) {
            int start = shiftOp[0], end = shiftOp[1], direction = shiftOp[2];
            shift[start] += (direction == 1 ? 1 : -1);
            shift[end + 1] -= (direction == 1 ? 1 : -1);
        }

        int currentShift = 0;
        for (int i = 0; i < n; ++i) {
            currentShift += shift[i];
            shift[i] = currentShift;
        }

        for (int i = 0; i < n; ++i) {
            int netShift = (shift[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};