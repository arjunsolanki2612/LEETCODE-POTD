974. Subarray Sums Divisible by K

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

// Explaination
here the intuition is: 
consider an array: [a, b, c, d, e, f, g, h]  
1) sum from a to e = S1 and S1%k is X (here X is the remainder)
2) sum from a to c = S2 and S2%k is also X
if the remainder of both the subarray sum is equal then the difference between this subarray sum is always divisible by k i.e. (d+e) is always divisible by k.

let say k=7
S1 = 7*n + X
S2 = 7*n' + X

S1-S2 = 7(n-n') --> S1-S2 = 7N. This eq. shows that the difference is always divisible by k ,here k =7. So we have proved our statement.

Edge case: In case of negative remainder--> let say S1 = 7n - X (-X means the remainder is negative). 
We can write this eq. as S1=7n - X +7 - 7.
S1 = 7(n+1) + 7 - X . So every time when the remainder is negative we will add 7 to that to make the remainder positive. Here k=7 that's why adding 7.

General eq. : S1 = k(n+1) + k - X.

Approach: we will initialize a map and increase the count of sum = 0 as 1 in the map because initially sum was 0 and we will maintain a count of the remainder 
we have seen till now if we got encounter with the same remainder in the map again it means we got a subarray which is divisible by k and then add that remainder 
freq in result variable.

At the end we will return result.
          
// code
  class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int rem=0;
        int res=0;
        unordered_map<int,int>mp;

        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            rem=sum%k;
            if(rem<0){
                rem+=k;
            }

            if(mp.find(rem)!=mp.end()){
                res+=mp[rem];
            }
            mp[rem]++;
        }
        return res;
    }
};
