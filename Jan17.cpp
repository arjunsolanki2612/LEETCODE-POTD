926. Flip String to Monotone Increasing
LINK: https://leetcode.com/problems/flip-string-to-monotone-increasing/description/
U-TUBE LINK: https://www.youtube.com/watch?v=mLfcUysjj6I

// A binary string is monotone increasing if it consists of some number of 0's (possibly none), followed by some number of 1's (also possibly none).

// You are given a binary string s. You can flip s[i] changing it from 0 to 1 or from 1 to 0.

// Return the minimum number of flips to make s monotone increasing.
// Example 1:

// Input: s = "00110"
// Output: 1
// Explanation: We flip the last digit to get 00111.
// Example 2:

// Input: s = "010110"
// Output: 2
// Explanation: We flip to get 011111, or alternatively 000111.




CODE:

class Solution {
public:
    int n;
    int minFlips(string &s,int curr_index,int prev_val,vector<vector<int>>&dp)
    {

        if(curr_index>=n){
            return 0;
        }
        if(dp[curr_index][prev_val]!=-1){
            return dp[curr_index][prev_val];

        }
        int flips=INT_MAX;
        int no_flips=INT_MAX;
        if(s[curr_index]=='0'){
            if(prev_val==1){
                flips=1+minFlips(s,curr_index+1,1,dp);
            }
            else{
                flips=1+minFlips(s,curr_index+1,1,dp);
                no_flips=minFlips(s,curr_index+1,0,dp);
            }

        }
        else if(s[curr_index]=='1'){
            if(prev_val==0){
                flips=1+minFlips(s,curr_index+1,0,dp);
                no_flips=minFlips(s,curr_index+1,1,dp);
            }
            else{
                no_flips=minFlips(s,curr_index+1,1,dp);
            }
        }
        return dp[curr_index][prev_val]=min(flips,no_flips);
    }
    int minFlipsMonoIncr(string s) {
        n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        return minFlips(s,0,0,dp);
    }
};
