134. Gas Station
https://leetcode.com/problems/gas-station/description/

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
// You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, 
//otherwise return -1. If there exists a solution, it is guaranteed to be unique

 

// Example 1:

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.





class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int car_gas=0;
        int gas_cost=0;
        int curr_gas=0;
        int index=0;
        int n=gas.size();
        // idea: if total gas is less than the total cost then it cant reach any station
        //if curr_gas<0 it means that gas is less than cost so that index can be starting index so 
        //increase index by 1
        for(int i=0;i<n;i++){
            car_gas+=gas[i];
            gas_cost+=cost[i];

            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0){
                index=i+1;
                curr_gas=0;
            }
        }

        if(car_gas<gas_cost){
            return -1;
        }
        return index;

        


    }
};
