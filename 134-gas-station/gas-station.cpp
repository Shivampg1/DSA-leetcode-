class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int pet=0;
        int total=0;
        int count=0;
        for(int i=0;i<n;i++){
        total += gas[i]-cost[i];
        }
        for(int i=0;i<n;i++){
            pet += gas[i]-cost[i];
            if(pet<0){
                count=i+1;
                pet=0;
            }
        }
        // else{
        //     return -1;
        // }
            //if(pet<=0 && count<)
        // if(count==n+1 && pet<=0){
        //     return ans[0];
        // }
        // else 
        if(total<0){
            return -1;
        }
        return count;
    }
};