class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7;

        vector<pair<int, long long>> adj[n];

        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            long long wt = roads[i][2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            auto d = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            if (d > dist[node]) continue;

            for (auto it : adj[node]) {

                auto neighbour = it.first;
                auto edwt = it.second;

                if (d + edwt < dist[neighbour]) {

                    dist[neighbour] = d + edwt;
                    ways[neighbour] = ways[node];
                    pq.push({dist[neighbour], neighbour});
                }

                else if (d + edwt == dist[neighbour]) {

                    ways[neighbour] =
                        (ways[neighbour] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};