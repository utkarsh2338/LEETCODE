class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=0;i<numRows-1;i++){
            vector<int>dummyRow={0};
            dummyRow.insert(dummyRow.end(),ans.back().begin(),ans.back().end());
            dummyRow.push_back(0);
            vector<int>row;
            for(int j=0;j<dummyRow.size()-1;j++){
                row.push_back(dummyRow[j]+dummyRow[j+1]);
            }

            ans.push_back(row);
        }

        return ans;
    }
};