997. Find the Town Judge
https://leetcode.com/problems/find-the-town-judge/description/

// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// The town judge trusts nobody.
// Everybody (except for the town judge) trusts the town judge.
// There is exactly one person that satisfies properties 1 and 2.
// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

// Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

// Example 1:

// Input: n = 2, trust = [[1,2]]
// Output: 2
// Example 2:

// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3


class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int>count(n+1);
        for(auto &i:trust){
            int u=i[0];
            int v=i[1];

            count[u]--;
            count[v]++;
        }

        for(int i=1;i<=n;i++){
            if(count[i]==n-1){
                return i;
            }

        }
        return -1;
    //    vector<int>indegree(n+1);
    //    vector<int>outdegree(n+1);

    //    for(vector<int>&vec:trust){
    //        int u=vec[0];
    //        int v=vec[1];

    //        outdegree[u]++;
    //        indegree[v]++;
    //    }

    //    for(int i=1;i<=n;i++){
    //        if(indegree[i]==n-1 && outdegree[i]==0){
    //            return i;
    //        }
           
    //    }
    //    return -1;
        
    }
};
