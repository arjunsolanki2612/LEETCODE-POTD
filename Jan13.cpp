2246. Longest Path With Different Adjacent Characters
leetcode link: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/
youtube link:https://www.youtube.com/watch?v=EA8dP63iVPk

// You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. 
// The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

// You are also given a string s of length n, where s[i] is the character assigned to node i.

// Return the length of the longest path in the tree such that no pair of adjacent nodes on the path have the same character assigned to them.
// Example 1:


// Input: parent = [-1,0,0,1,1,2], s = "abacbe"
// Output: 3
// Explanation: The longest path where each two adjacent nodes have different characters in the tree is the path: 0 -> 1 -> 3. The length of this path is 3, 
// so 3 is returned.
// It can be proven that there is no longer path that satisfies the conditions. 

code:
class Solution {
public:

    int maxSum;
    int dfs(unordered_map<int,vector<int>>&mp,int curr, int parent,string&s){
        //as this is graph so there are many children of a node so we need the best two path they may be
        //equal also
        int largest=0;
        int second_largest=0;
        for(auto&child:mp[curr]){
            if(child!=parent){
                //it will give all the child sum of a node
                int child_largest_sum=dfs(mp,child,curr,s);

                // this means if the two adjacent node have same label so we will not consider that path
                if(s[child]==s[curr]){
                    continue;
                }

                // from this two if condition we will get two best path
                if(child_largest_sum>second_largest){
                    second_largest=child_largest_sum;
                }
                if(second_largest>largest){
                    swap(largest,second_largest);
                }

                
            }
            
        }
        //1. ya to neeche hi best path mil gaya
        int Got_the_answer_below=largest + second_largest+1;
        //2. ya fir ek left se or right se mila or inme se hum best le lenge
        int Got_one_of_the_good_sumFrom_leftOrRight = max(largest,second_largest)+1;
        //. ya fir dono left right se nhi mila to sirf root hi ek path me add hoga
        int Didnt_get_from_leftOrRight =1;

        // maxSum to teeno path length se hi niklega
        maxSum=max({maxSum,Got_the_answer_below,Got_one_of_the_good_sumFrom_leftOrRight,Didnt_get_from_leftOrRight});

        //return to hum max of 2 and 3 hi karenge because we have the hope of getting path above the parent
        // 1 kyu nhi because hume niche hi path mil gaya or hum ise return krenge to 3-directional path 
        //ban jaayga
        return max(Got_one_of_the_good_sumFrom_leftOrRight,Didnt_get_from_leftOrRight);
    }
    int longestPath(vector<int>& parent, string s) {
        unordered_map<int,vector<int>>mp;
        int n=parent.size();
        maxSum=0;
        for(int i=1;i<n;i++){
            int u=i;
            int v=parent[i];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
    dfs(mp,0,-1,s);
    return maxSum;
    }
};
