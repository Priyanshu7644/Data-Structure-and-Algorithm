#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start_node, int end_node) {

        vector<vector<pair<int,double>>> graph(n);

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0], v=edges[i][1];
            double w = -log(succProb[i]);

            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        priority_queue<pair<double,int>,
            vector<pair<double,int>>,
            greater<pair<double,int>>> pq;

        vector<double> dist(n,1e18);
        dist[start_node]=0;
        pq.push({0,start_node});

        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop();

            for(auto [v,w]:graph[u]){
                if(dist[v] > d+w){
                    dist[v]=d+w;
                    pq.push({dist[v],v});
                }
            }
        }

        if(dist[end_node]==1e18) return 0.0;
        return exp(-dist[end_node]); // convert back
    }
};