// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
//EXPLAINATION IS IN THIS LINK
https://drive.google.com/drive/u/0/folders/1brHxYxXGmy7BJhaD8SrufEW_OiT4VQki
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0;
        int twos=0;
        for(auto i:nums){
            ones = ones^i &(~twos);
            twos = twos^i &(~ones);
        }
        return ones;
        
    }
};

