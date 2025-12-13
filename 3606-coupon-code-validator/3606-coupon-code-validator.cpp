class Solution {
public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();
        unordered_map<string, int> mpp = {{"electronics", 0},
                                          {"grocery", 1},
                                          {"pharmacy", 2},
                                          {"restaurant", 3}};
        vector<pair<string, string>> valid;
        for (int i = 0; i < n; i++) {
            if (!isActive[i])
                continue;
            auto it = mpp.find(businessLine[i]);
            if (it == mpp.end())
                continue;
            if (code[i].empty())
                continue;

            bool flag = true;
            for (char ch : code[i]) {
                if (!(isalnum(ch) || ch == '_')) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                valid.emplace_back(businessLine[i], code[i]);
            }
        }
        sort(valid.begin(), valid.end(), [&](auto& A, auto& B) {
            int oa = mpp[A.first];
            int ob = mpp[B.first];
            if (oa != ob)
                return oa < ob;
            return A.second < B.second;
        });

        vector<string> output;
        for (auto& [_, c] : valid)
            output.push_back(c);
        return output;
    }
};