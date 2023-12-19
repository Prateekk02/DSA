//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool check(int start, int colored[], vector<int> adj[])
    {
        
	    queue<int> q;
	    colored[start] = 0;
	    q.push(start);
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        for(auto it : adj[node])
	        {   
	            // if the adjacent node in not colored
	            // then we will make its color opposite to the current node's color.
	            if(colored[it] == -1)
	            {
	                colored[it] = !colored[node];
	                q.push(it);
	            }
	            
	            // if the color of the parent and the current node is same that means someone has already colored it.
	            else if(colored[it] == colored[node]){
	                return false;
	            }
	        }
	    }
	    return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int colored[V];
	    
	    for (int i = 0 ; i<V ;i++)
	    {
	        colored[i] = -1;
	    }
	    
	    
	    // Checking for each components.
	    for(int i=0 ; i< V ; i++)
	    {
	        if(colored[i] == -1)
	            if(!check(i, colored,adj))
	                return false;
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends