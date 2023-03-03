#include<iostream>
#include<string>

using namespace std;
void solution (string &txt, string &pat)
{
    // Finding lengths of each string.
    int n = txt.size();
    int m = pat.size();

    for(int i=0;i<=n-m;)
    {
        int j;
        for(j=0;j<m;j++)
        if(pat[j]!=txt[i+j])   // sliding the window over txt.
            break;

        if(j==m)         // if the pat window matches txt we print i
            cout<<i<<" ";

        if(j==0)    // Optimization case if the first character of pat does not matches with txt we increment i.
            i++;
        else    
            i = i+j;   // if the window doesn't match then we shift the window by i+j.
            // As we know that each character in pat is different and there is no chance to get a match in middle of txt.
            // Hence rather than increamenting value of i by 1 we increment it by j.
        
    }
}
int main()
{
    string txt, pat;
    getline(cin,txt);
    getline(cin, pat);

    solution(txt, pat);
    return 0;
}