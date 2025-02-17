class Solution {
public:
    unordered_set<string> st;
    int n;
    void solve(string &tiles,vector<bool>& visited,string current){
        n = tiles.size();
        // base case
        if(!current.empty()){
            st.insert(current);
        }

        for(int i=0;i<n;i++){
            if(visited[i] || (i>0 && tiles[i] == tiles[i-1] && !visited[i-1])) continue;
            visited[i] = true;
            solve(tiles,visited,current+tiles[i]);
            visited[i] = false;
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        // sort to handle duplicates
        sort(tiles.begin(),tiles.end());
        vector<bool> visited(n,false);
        solve(tiles,visited,"");
        return st.size();
    }
};