#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pii;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<pii,vector<pii>,greater<pii>> pq;

        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;

        vector<vector<pii>> graph(n+1, vector<pii>());

        // FIXED LOOP ONLY
        for(auto &e : times){
            int u=e[0], v=e[1], w=e[2];
            graph[u].push_back({v,w});
        }

        pq.push({0,k});
        vector<int> visited(n+1,false);

        while(!pq.empty()){
            auto [dist,node]=pq.top();
            pq.pop();

            if(visited[node]) continue;
            visited[node]=true;

            for(auto [nei,weight] : graph[node]){
                if(dis[node] + weight < dis[nei]){
                    dis[nei] = dis[node] + weight;
                    pq.push({dis[nei],nei});
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};