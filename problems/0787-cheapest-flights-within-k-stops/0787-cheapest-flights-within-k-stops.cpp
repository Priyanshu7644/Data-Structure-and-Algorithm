class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Use pair<int, int> to store {node, price} so .first and .second work
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }

        // Min-heap storing vectors of format: {cost, node, steps}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Renamed to avoid shadowing the 'steps' variable inside the loop
        vector<int> minStops(n, 1e9);

        // Initialize with {cost=0, node=src, steps=0}
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            
            int cost = temp[0];
            int node = temp[1];
            int steps = temp[2];

            // Because it's a min-heap by cost, the first time we hit the destination 
            // within the allowed steps, it is guaranteed to be the cheapest.
            if (node == dst) return cost;

            // If we've exhausted our allowed stops (k stops = k+1 edges)
            // we stop exploring further from this path.
            if (steps > k) continue;
            
            // Pruning: if we have reached this node previously with fewer or equal steps,
            // we can skip it. (Since the PQ prioritizes cost, earlier visits were cheaper).
            if (steps >= minStops[node]) continue;
            minStops[node] = steps;

            for (auto it : adj[node]) {
                int neighbour = it.first;
                int price = it.second;
                
                // Push updated cost and incremented steps
                pq.push({cost + price, neighbour, steps + 1});
            }
        } 
        
        return -1;
    }
};