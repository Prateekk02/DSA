#include<iostream>
#include<string>
using namespace std;
int q = 107;
int d = 5;
void RBsearch(const string &pat, const string &txt, int m , int n)
{
    int h=1;
    for(int i=1;i<m;i++)
    {
        h = (h*d)%q;
    }
    int p=0, t=0;
    for(int i=0;i<m;i++)
    {
        p = (p*d+pat[i])%q;
        t = (t*d + txt[i])%q;
    }
    for(int i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            bool flag = true;
            for(int j=0;j<m;j++)
            {
                if(txt[i+j]!=pat[j])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                cout<<i<<" ";
        }
        if(i<n-m)
        {
            t = ((d*(t-txt[i]*h)+ txt[i+m])%q);
            if(t<0)
                t = t+q;
        }
    }
}
int main()
{
    string txt, pat;

    getline(cin,txt);
    getline(cin,pat);
    int m = pat.size();
    int n = txt.size();
    RBsearch(pat, txt, m,n);
    return 0;
}