//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        int indeg[V] = {0};
        
        // Reversing the adjacency list and calculating indegree.
        for(int i=0;i<V;i++){
            // i -> it   (normal order)
            // it -> i   (reversed order)
            for(auto &it : adj[i]){
                adjRev[it].push_back(i);
                
                indeg[i]++;
            }
            
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> res;
        
        while(!q.empty()){
            int node = q.front();
            res.push_back(node);
            q.pop();
            
            for(auto &it : adjRev[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    q.push(it);
                }
            }
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends