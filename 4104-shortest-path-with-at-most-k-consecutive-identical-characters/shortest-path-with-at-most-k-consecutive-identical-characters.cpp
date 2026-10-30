
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
        }

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        vector<vector<long long>> res(n, vector<long long>(k+1, 1e18));

        res[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()){
            auto [d, node, cnt] = pq.top();
            pq.pop();

            if(res[node][cnt] < d){
                continue;
            }

            if(node == n-1){
                return d;
            }

            for(auto &v : adj[node]){
                int nnode = v.first;
                int nd = v.second;

                int ncnt = 1;

                if(labels[node] == labels[nnode]){
                    ncnt = cnt + 1;
                }

                if(ncnt > k){
                    continue;
                }

                if(res[nnode][ncnt] > d + nd){
                    res[nnode][ncnt] = d + nd;
                    pq.push({d + nd, nnode, ncnt});
                }
            }
        }

        return -1;
    }
};
