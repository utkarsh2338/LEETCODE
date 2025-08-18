class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int n = plants.size();
        int steps = 0;
        int cap = capacity;
        for(int i=0;i<n;i++){
            if(plants[i] <= cap){
                steps++;
                cap -= plants[i];
            }
            else{
                steps += 2*i+1;
                cap = capacity - plants[i];
                
            }
        }
        return steps;
    }
};