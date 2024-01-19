//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
  private:
    bool checkCycle(int node, int vis[], int pathVis[], vector<int> adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it: adj[node])
        {
            if(vis[it] == 1 && pathVis[it] == 1)
            {
                return true;
            }
            else if(vis[it] == 0 && pathVis[it] == 0)
            {
                if(checkCycle(it, vis, pathVis, adj))
                {
                    return true;
                }
            }
          
        }
        pathVis[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] ;
        int pathVis[V];
        
        for(int i=0;i<V;i++)
        {
            vis[i] = 0;
            pathVis[i] = 0;
        }
        
        // Checking for each component of the graph.
        for(int i=0;i<V;i++)
        {
            if(vis[i] == 0)
            {
                if(checkCycle(i, vis, pathVis, adj))
                    return true;
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends




// // Implementation using only one visited array.


// class Solution {
    
//   private:
//     bool checkCycle(int node, int vis[], /*int pathVis[],*/ vector<int> adj[]){
//         vis[node] = 2;
//        // pathVis[node] = 1;
        
//         for(auto it: adj[node])
//         {
//             if(vis[it] == 2)
//             {
//                 return true;
//             }
//             else if(!vis[it])
//             {
//                 if(checkCycle(it, vis,/* pathVis,*/ adj))
//                 {
//                     return true;
//                 }
//             }
          
//         }
//         vis[node] = 1;
//         return false;
//     }
//   public:
//     // Function to detect cycle in a directed graph.
//     bool isCyclic(int V, vector<int> adj[]) {
//         int vis[V] ;
//        // int pathVis[V];
        
//         for(int i=0;i<V;i++)
//         {
//             vis[i] = 0;
//             //pathVis[i] = 0;
//         }
        
//         for(int i=0;i<V;i++)
//         {
//             if(vis[i] == 0)
//             {
//                 if(checkCycle(i, vis, /*pathVis,*/ adj))
//                     return true;
//             }
//         }
//         return false;
//     }
// };


