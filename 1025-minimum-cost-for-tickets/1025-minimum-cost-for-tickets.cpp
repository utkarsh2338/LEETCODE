class Solution {
public:

    int t[366];

    int solve(int idx,vector<int>& days, vector<int>& costs){

        // base case
        if(idx>=days.size()){
            return 0;
        }
        if(t[idx] != -1){
            // mtlab mai solve kar chuka hu iss index ke liye
            // retuern the value at index
            return t[idx];
        }


    // explore for first day
    int first_day = costs[0] + solve(idx+1,days,costs);


    // explore for seventh day
    int max_day = days[idx] + 7;// here we have to rach at that index jaha tak ki ye days wale array me usko uss pass se chhut mili hai.
    // this step is the mist crucial thing in this  
    int j = idx;
    while(j<days.size() && days[j] < max_day){
        j++;
    }
    // iss j me mera vo index hai jaha tak mai uss seven day pass se ja sakta hu
    int seven_day = costs[1] + solve(j,days,costs);


    // explore thirtieth day pass;
    j = idx;
    max_day = days[idx] + 30;
    while(j<days.size()&&days[j] < max_day){
        j++;// got the index
    }
    int thirty_day = costs[2] + solve(j,days,costs);

    return t[idx] = min({first_day, seven_day,thirty_day});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        return solve(0,days,costs);
    }
};