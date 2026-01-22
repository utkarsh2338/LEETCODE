class Solution {
public:
    int vowelConsonantScore(string s) {
        constexpr int mask = 0x104111;
        int A[2] = {0, 0};

        for (auto& c : s)
            if (isalpha(c))
                A[(mask >> (c - 'a')) & 1]++;

        //return (A[1] / (A[0] + (A[0] == 0))) * (A[0] != 0);
        return A[0] > 0 ? A[1] / A[0] : 0;
    }
};