// Minimum Rounds to Complete All Tasks
// You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

// Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

 

// Example 1:

// Input: tasks = [2,2,3,3,2,4,4,4,4,4]
// Output: 4
// Explanation: To complete all the tasks, a possible plan is:
// - In the first round, you complete 3 tasks of difficulty level 2. 
// - In the second round, you complete 2 tasks of difficulty level 3. 
// - In the third round, you complete 3 tasks of difficulty level 4. 
// - In the fourth round, you complete 2 tasks of difficulty level 4.  
// It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
// Example 2:

// Input: tasks = [2,3,3]
// Output: -1
// Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.


//Explaination
1. if the freq is multiple of 3 let say 12 --> then it can be factorized by 3 3 3 3 so output is 4
2. if the freq is multiple of 3k+1 ley say 7 -->then it can be factorized by 3 3 1, so we can add extra 1 from the last second factor then 3 2 2 it means add extra one to the output 
3. if 3k+2 then it also means add one extra task to the output.
  
//CODE
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>freq;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;
        }
    int res=0;
    for(auto e:freq){
        if(e.second==1){
            return -1;
        }
        
        if(e.second%3==0){
            res+=e.second/3;
        }
        else{
            res+=e.second/3+1;
        }
    }
    return res;
        
        
    }
};
