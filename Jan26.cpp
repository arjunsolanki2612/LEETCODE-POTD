//HAPPY REPUBLIC DAY
787. Cheapest Flights Within K Stops
https://leetcode.com/problems/cheapest-flights-within-k-stops/
https://www.youtube.com/watch?v=VmUpydhNmuw

// There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight 
// from city fromi to city toi with cost pricei.

// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

// Example 1:
// Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
// Output: 700
// Explanation:
// The graph is shown above.
// The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
// Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

CODE:
class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int , vector<pair<int,int>>>adj;

        for(vector<int>&vec:flights){
            int u = vec[0];
            int v = vec[1];
            int cost = vec[2];

            adj[u].push_back({v,cost});
        }

        vector<int>dist(n,INT_MAX);
        queue<pair<int,int>>que;
        que.push({src,0});
        dist[src]=0;
        int steps=0;

        while(!que.empty() && steps<=k){
            int N = que.size();
            while(N--){
                int from = que.front().first;
                int cost_of_from = que.front().second;
                que.pop();

                for(pair<int,int>&P : adj[from]){
                    int to = P.first;
                    int cost_to = P.second;

                    if(dist[to]> cost_of_from+cost_to){
                        dist[to] = cost_of_from+cost_to;
                        que.push({to,cost_of_from+cost_to});
                    }
                }
            }
            steps++;
        }

        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
