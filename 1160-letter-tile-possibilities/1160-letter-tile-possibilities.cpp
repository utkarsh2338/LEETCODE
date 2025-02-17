class Solution {
public:
    unordered_set<string>st;
    int n;
    void solve(string& tiles,vector<bool>& visited,string& output){
        n = tiles.length();
        if(!output.empty()){
            st.insert(output);
        }
        for(int i=0;i<n;i++){
            // base case
            if(visited[i]) continue;
            visited[i] = true;// take
            output.push_back(tiles[i]);
            solve(tiles,visited,output);// explore
            visited[i] = false;// not take
            output.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        string output ="";
        vector<bool>visited(n,false);
        solve(tiles,visited,output);
        return st.size();
    }
};