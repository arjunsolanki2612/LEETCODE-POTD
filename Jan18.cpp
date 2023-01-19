918. Maximum Sum Circular Subarray

// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element 
// of nums[i] is nums[(i - 1 + n) % n].

// A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not 
// exist i <= k1, k2 <= j with k1 % n == k2 % n.

// Example 1:

// Input: nums = [1,-2,3,-2]
// Output: 3
// Explanation: Subarray [3] has maximum sum 3.

// Code
class Solution {
public:
    
    int maxKadane(vector<int>& nums){
        int res=nums[0];
        int maxending=nums[0];

        for(int i=1;i<nums.size();i++){
            maxending=max(maxending+nums[i],nums[i]);
            res=max(res,maxending);
        }
        return res;
    }
    
    int minKadane(vector<int>& nums){
        int min_res=nums[0];
        int minending=nums[0];

        for(int i=1;i<nums.size();i++){
            minending=min(minending+nums[i],nums[i]);
            min_res=min(min_res,minending);
        }
        return min_res;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int maxNormal=maxKadane(nums);
        if(maxNormal<0){
            return maxNormal;
        }

        int arr_sum=0;
        for(auto i:nums){
            arr_sum+=i;
        }

        
        int cir_sum=arr_sum-minKadane(nums);
        return max(maxNormal,cir_sum);

    }
};
