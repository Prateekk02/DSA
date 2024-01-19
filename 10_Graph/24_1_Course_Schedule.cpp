//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Creating adjecency list
	    vector<int> adj[N];
	    for(auto &it : prerequisites){
	        adj[it.first].push_back(it.second); 
	    }
	    
	    // Calculating Indegree
	    int inDeg[N] = {0};
	   for(int i=0;i<N;i++){
	       for(auto &it: adj[i]){
	           inDeg[it]++;
	       }
	   }
	    
	    queue<int> q;
	    int count = 0;
	    for(int i=0;i<N;i++){
	        if(!inDeg[i]){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        count++;
	        q.pop();
	        
	        for(auto &it: adj[node]){
	            inDeg[it]--;
	            
	            if(inDeg[it] == 0){
	                q.push(it);
	            }
	        }
	    }
	    
	    return(count == N);
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends