// class Solution {
// public:
//     vector<string> removeSubfolders(vector<string>& folder) {
//         vector<string> ans;
//         for(int i=0;i<folder.size()-1;i++){
//             int j=i+1;
//             if(i[0]!='/') return -1;
//             if(i[0]==j[0] && i[1]==j[1]){
//                 ans.push_back(folder[i]);
//                 i++;
//                 j++;
//             }
//             else{
//                 i++;
//                 j++;
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<string> removeSubfolders(vector<string>& folder) {
//         sort(folder.begin(),folder.end());
//         vector<string>ans;
//         ans.push_back(folder[0]);//initialise the ans vector with the first folder
//         for(int i=0;i<folder.size();i++){
//            //i need to get the last added folder so that i can compare and it should start with a slash
//            string lastFolder = ans.back();
//            lastFolder.push_back('/');
//            if(folder[i].comapare(0,lastFolder.size(),lastFolder) !=0){
//             ans.push_back(folder[i]);
//            }
//         }
//         return ans;
// }
// };


class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folders lexicographically so parent folders come before their subfolders
        sort(folder.begin(), folder.end());

        // Initialize result vector with the first folder
        vector<string> ans;
        ans.push_back(folder[0]);

        // Iterate through remaining folders starting from index 1
        for(int i = 1; i < folder.size(); i++) {
            // Get the last added folder path and add a trailing slash
            // This helps in comparing if current folder is a subfolder
            string lastFolder = ans.back();
            lastFolder.push_back('/');

            // Compare current folder with last added folder
            // compare(0, lastFolder.size(), lastFolder) checks if folder[i] starts with lastFolder
            // If it doesn't start with lastFolder (returns != 0), then it's not a subfolder
            if(folder[i].compare(0, lastFolder.size(), lastFolder) != 0) {
                // If not a subfolder, add to result
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};