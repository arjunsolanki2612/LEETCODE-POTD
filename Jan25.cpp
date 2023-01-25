2359. Find Closest Node to Given Two Nodes
https://leetcode.com/problems/find-closest-node-to-given-two-nodes/

// You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

// The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. 
//   If there is no outgoing edge from i, then edges[i] == -1.

// You are also given two integers node1 and node2.

// Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to 
// that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

// Note that edges may contain cycles.
// Example 1:


// Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
// Output: 2
// Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
// The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.


// code
class Solution {
public:
    int n;

    void dfs(vector<int>& edges,int node,vector<bool>&visited, vector<int>&dist ){
        visited[node]=true;

        int v = edges[node];

        if(v!=-1 && visited[v]!=true){
            dist[v]=1+dist[node];
            dfs(edges,v,visited,dist);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n=edges.size();
        // I made two visited array for both nodes 
        vector<bool>visited1(n,false);
        vector<bool>visited2(n,false);

        //Distance array of each node from node1 and node2. Initially the distances are infinity
        vector<int>dist1(n,INT_MAX);
        vector<int>dist2(n,INT_MAX);

        //distance of node1 and node2 is 0 from itself.
        dist1[node1]=0;
        dist2[node2]=0;

        // currently we don't know the index have minimum maximum distane so initalized with -1
        int minDistNodeIdx = -1;
        //initially the distance we consider as infinity
        int minDistanceFromNode = INT_MAX;

        //dfs call for both node
        dfs(edges,node1,visited1,dist1);
        dfs(edges,node2,visited2,dist2);

        //after the call is finished we will traverse through the distance vector and get out the maximum dist at each
        //iteration from both.  Eg the graph is like 0-->2 1-->2 and 2-->3.
        //node1=0, node2=1.  dist1[]={0,INT_MAX,1,2} so distance of 1 from 0 is infinity , and for 2 is 1 and for 3 is 2 
                           //nodes  = 0 1       2 3
        //likeswise for node2, dist2[]={INT_MAX,0,1,2} so distance of 0 from 1 is infinity , and for 2 is 1 and for 3 is 2 
                           //nodes  =   0       1 2 3

        for(int i=0;i<n;i++){
            int maxDist = max(dist1[i],dist2[i]);
            if(minDistanceFromNode>maxDist){
                minDistanceFromNode=maxDist;
                //at last we will store the minimum maximize distance from the index
                minDistNodeIdx=i;
            }
        }
        return minDistNodeIdx;
    }
};
