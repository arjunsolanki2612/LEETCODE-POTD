93. Restore IP Addresses
https://leetcode.com/problems/restore-ip-addresses/description/

// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or 
// remove any digits in s. You may return the valid IP addresses in any order.
// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]


//TIME COMPLEXITY
/*

For at most we can have three number together in an ip address. 

a b c d

a._____   or ab.___ or abc.____ ---> 3^1

for a.____

a.b.___ or a.bc.___ or a.b.cd___ --> for a.__ and ab.__ and abc.__ each will generate 3 possiblities--> so 3^2
..
..
..
..
ans so on to 3^4.

So the T.C O(M^N)

and for every possiblities we are finding a substr and substr alone is a O(N) operation

so the total time complexity is --> O(M^N.N)
*/


class Solution {
public:
    
    int n;
    vector<string>result; 
//this is to check for substring of length 2 and 3 to match the condition that are given in the question
//leading integer should not be 0 and 0<=integer<=255
    bool isValid(string str){
        if(str[0]=='0'){
            return false;
        }

        int val=stoi(str);
        return val<=255;
    }

//recursive part
    void solveIp(string &s, int idx, string curr, int parts){
        //when the index gets out of bound and we get four parts of that string then we add it to our result
        if(idx==n && parts==4){
            // curr.pop_back();//last ka decimal hatane k liye --> backtracking appraoch
            // result.push_back(curr);

             // if not known backtracking then we can remove last index by doing this operation
             result.push_back(curr.substr(0,curr.length()-1));
            return;
           
           
        }
//case 1: considering only one integer at a time
        if(idx+1<=n){
            solveIp(s,idx+1,curr+s.substr(idx,1)+".",parts+1);
        }
//case 2: considering two integer at a time and checking is the substr is valid or not
        if(idx+2<=n && isValid(s.substr(idx,2))){
            solveIp(s,idx+2,curr+s.substr(idx,2)+".",parts+1);
        }
//case 3: considering three integer at a time and checking is the substr is valid or not
        if(idx+3<=n && isValid(s.substr(idx,3))){
            solveIp(s,idx+3,curr+s.substr(idx,3)+".",parts+1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
       n=s.length();
    //    result.clear();
// edge case if the string length is greater than 12 then we can never have ip address of 4 parts
//some integer will remain unused and always they make number greater than 255
       if(n>12){
           return {};
       }
       string curr="";
       int parts=0;
       
       solveIp(s,0,curr,parts);
       return result;
    }
};
