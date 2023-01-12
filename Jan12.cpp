1519. Number of Nodes in the Sub-Tree With the Same Label
https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
// You are given a tree (i.e. a connected, undirected graph that has no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges. The root of the tree is the node 0, and each node of the tree has a label which is a lower-case character given in the string labels (i.e. The node with the number i has the label labels[i]).

// The edges array is given on the form edges[i] = [ai, bi], which means there is an edge between nodes ai and bi in the tree.

// Return an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i.

// A subtree of a tree T is the tree consisting of a node in T and all of its descendant nodes.

 

// Example 1:


// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
// Output: [2,1,1,1,1,1,1]
// Explanation: Node 0 has label 'a' and its sub-tree has node 2 with label 'a' as well, thus the answer is 2. Notice that any node is part of its sub-tree.
// Node 1 has a label 'b'. The sub-tree of node 1 contains nodes 1,4 and 5, as nodes 4 and 5 have different labels than node 1, the answer is just 1 (the node itself).

code:
class Solution {
public:

    vector<int> DFS(int curr, int parent,unordered_map<int,vector<int>>&adj,string &labels,vector<int>&result){
        
        //each node will maintain its count and then return its count to the parent
        vector<int>my_count(26,0);
        //each node will first increase its label count at that node
        char mychar = labels[curr];
        my_count[mychar-'a']=1;

        // traversing through the graph
        for(auto &child:adj[curr]){
            if(child!=parent){

                //each node will have to have to child_count vector so that it can add this vector to its 
                //my_count vector
                vector<int>child_count=DFS(child,curr,adj,labels,result);
                for(int i=0;i<26;i++){
                    my_count[i]+=child_count[i];
                }
            }
        }
        //before returning the my_count vector it will firstly update the count of label in result vector
        result[curr]=my_count[mychar-'a'];
        //and then it will return the count
        return my_count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        //creating an adjacency list
        unordered_map<int,vector<int>>adj;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //creating a result vector that holds the count of nodes in subtree having same label
        vector<int>result(n,0);
        //dfs call with node as 0 and parent as -1
        DFS(0,-1,adj,labels,result);
        return result;
    }
};


  
