#include<iostream>
#include<string>

using namespace std;
// In this solution we slide the pattern over the text.
// O((n-m+1)*m) , O(1)
void solution(string &txt , string &pat)
{
    int m = pat.size();
    int n = txt.size();

    for(int i=0;i<=n-m;i++)
    {
        int j;
        for(j=0;j<m;j++)  // Matching all the characters of the pattern with the window.
        {
            if(pat[j]!=txt[i+j])
                break;
        }
        if(j==m)
            cout<<i<<" ";
    }
}
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    solution(s1,s2);
    return 0;
}