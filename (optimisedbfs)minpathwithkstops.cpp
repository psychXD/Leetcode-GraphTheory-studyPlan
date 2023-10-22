//https://leetcode.com/problems/cheapest-flights-within-k-stops/description/?envType=study-plan-v2&envId=graph-theory
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
    // Create an adjacency list to represent the network of flights.
    vector<pair<int,int>> adj[n];

    // Populate the adjacency list with flight data.
    for(auto it: flights)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }

    // Initialize a queue for breadth-first search (BFS).
    queue<pair<int,int>> q;
    // Start at the source node with cost 0 and 0 stops.
    q.push({0,{src,0}});
    
    // Initialize a vector to store the minimum cost to reach each node.
    vector<int> dis(n,1e9);
    // The cost to reach the source node is 0.
    dis[src] = 0;

    // Start BFS traversal.
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stop = it.first;
        int node = it.second.first;
        int cost = it.second.first;
        
        // Check if the number of stops has exceeded the maximum allowed (K).
        // If so, continue to the next node without further exploration.
        if(stop > K) continue;

        // Explore all adjacent nodes (flights departing from the current node).
        for(auto ik:adj[node])
        {
            int ad = ik.first;  // The adjacent node.
            int ck = ik.second; // The cost of the flight.

            // Check if taking this flight results in a lower cost to reach the adjacent node
            // than the previously recorded cost.
            if(cost + ck < dis[ad] && stop <= K)
            {
                // Update the minimum cost to reach the adjacent node.
                dis[ad] = cost + ck;
                // Enqueue the adjacent node for further exploration.
                q.push({stop+1,{ad,cost+ck}});
            }
        }
    }

    // Check if a valid path to the destination node is found.
    if(dis[dst] == 1e9)
        return -1;  // No valid path exists within the given constraints.
    // Return the minimum cost to reach the destination node.
    return dis[dst];
 }
