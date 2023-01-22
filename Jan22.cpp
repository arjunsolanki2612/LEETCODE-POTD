131. Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/description/
https://www.youtube.com/watch?v=jHR7KUAAEzw

// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]




class Solution {
public:

    int n;
    vector<vector<string>>result;
// it is the palindrome function code to check whether the substring is palindrome or not.
    bool isPalindrome(string&s, int l, int r){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }
    void backtrack(string &s, int idx, vector<string>&curr){
        //it means idx becomes out of bound and we have traverse whole string and this is the possible 
        //partition of palindrome substring
        if(idx==n){
            result.push_back(curr);
        }

        //for each idx we are checking whether to consider this substring or not if yes then we have put the condition of is palindrome if it is palindrome 
//       then we will push back it to the curr vector and then call the function backtrack() to explore the remaining string and when we will come back it means 
//       backtrack we will pop back each substring because we need to explore other possibilities also.
        for(int i=idx;i<n;i++){
            if(isPalindrome(s,idx,i)){
                //the substr function takes two parameters. 1st is the index, 2nd is the length to which we have to take the substring
                curr.push_back(s.substr(idx,i-idx+1));
                backtrack(s,i+1,curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n=s.length();

        vector<string>curr;
        backtrack(s,0,curr);
        return result;
    }
};
