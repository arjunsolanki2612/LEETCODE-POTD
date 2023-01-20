491. Non-decreasing Subsequences

link:https://leetcode.com/problems/non-decreasing-subsequences/description/
youtube:youtube.com/watch?v=8dfPwZvvDc8&t=848s
  
// Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. 
// You may return the answer in any order.

// Example 1:

// Input: nums = [4,6,7,7]
// Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
// Example 2:

// Input: nums = [4,4,3,2,1]
// Output: [[4,4]]
  
 code:
class Solution {
public:
    int n;
    void subseq(vector<int>& nums,int idx,vector<int>&curr,vector<vector<int>>&result){
        if(curr.size()>=2){
            result.push_back(curr);
        }
        unordered_set<int>st;
        for(int i=idx;i<n;i++){
            if((curr.empty()|| nums[i]>=curr.back()) && st.find(nums[i])==st.end()){
                curr.push_back(nums[i]);
                subseq(nums,i+1,curr,result);
                curr.pop_back();

                st.insert(nums[i]);
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>result;
        vector<int>curr;

        subseq(nums,0,curr,result);
        return result;
    }
};
