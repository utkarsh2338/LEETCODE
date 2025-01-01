class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mpp;
        // iterating through the strs string so that i can fill the map;
        for(auto utkar: strs){
            // sort the string
            string temp = utkar;// storing the string to acsess it in future
            sort(utkar.begin(),utkar.end());
            // here the utkar string is sorted string and it is acting as a key for the unordered_map and now i am adding the value corresponding to this key in the vector.
            mpp[utkar].push_back(temp);
        }
        // now iterate through the map
        for(auto shukla:mpp){
            vector<string>shuk = shukla.second;
            ans.push_back(shuk);
        }
        return ans;
    }
};