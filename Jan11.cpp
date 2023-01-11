// Given an undirected tree consisting of n vertices numbered from 0 to n-1, which has some apples in their vertices. You spend 1 second to walk over one edge of the tree. 
// Return the minimum time in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex.

// The edges of the undirected tree are given in the array edges, where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. 
// Additionally, there is a boolean array hasApple, where hasApple[i] = true means that vertex i has an apple; otherwise, it does not have any apple.

 

// Example 1:


// Input: n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], hasApple = [false,false,true,false,true,true,false]
// Output: 8 
// Explanation: The figure above represents the given tree where red vertices have an apple. One optimal path to collect all apples is shown by the green arrows. 

class Solution {
public:
    int dfs(unordered_map<int,vector<int>>&adj,int node, int parent,vector<bool>& hasApple ){
        int time=0 ,child_time=0;
        for(auto &child:adj[node]){
           
            if(child!=parent){

                cout<<child_time<<endl;
            child_time=dfs(a+dj,child,node,hasApple);

            
            if(child_time || hasApple[child]){
                time+=child_time+2;

            }
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;
        for(auto &e :edges){
            int u= e[0];
            int v=e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj,0,-1,hasApple);
    }

    
};
