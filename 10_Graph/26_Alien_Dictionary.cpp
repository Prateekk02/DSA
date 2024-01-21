//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private: 
    vector<int> topoSort(vector<int> adj[], int V){
        int inDeg[V-1] = {0};
        for(int i=0;i<V;i++){
            for(auto &it : adj[i]){
                inDeg[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(inDeg[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> res;
        while(!q.empty()){
            int node = q.front();
            res.push_back(node);
            q.pop();
            for(auto &it: adj[node]){
                inDeg[it]--;
                
                if(inDeg[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return res;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        // Making the directed graph of the elements.
        vector<int> adj[K];
        
        for(int k=0;k<N-1;k++){
            string s1 = dict[k];
            string s2 = dict[k+1];
            
            int i = 0;
            int len = min(s1.size(),s2.size());
            while(i<len){
                if(s1[i]!=s2[i]){
                    // Add it to DAG.
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
                i++;
            }
        }
        
        vector<int> ansVector =  topoSort(adj,K);
        
        string res ;
        for(auto &it: ansVector){
            res.push_back(it+'a');
        }
        
        return res;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends