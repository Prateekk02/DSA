//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // converting wordList to set.
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        queue<pair<string,int>> q;
        
        q.push({startWord, 1});
        st.erase(startWord);
        
        while(!q.empty()){
            string str = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(str == targetWord)
                return dist;
            
            for(int i = 0;i<str.size();i++){
                char original = str[i];
                for(char j = 'a' ; j<='z';j++){
                    str[i] = j;
                    if(st.count(str)){
                        q.push({str,dist+1});
                        st.erase(str);
                    }
                }
                str[i] = original;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends