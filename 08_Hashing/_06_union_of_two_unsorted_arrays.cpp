#include<iostream>
#include<unordered_set>

using namespace std;


/*
    Naive Solution.
    int findUnion(int a[], int b[], int m, int n)
    {
        int c[m+n];
        for(int i=0;i<n;i++)
            c[i] = a[i];

        for(int i=0;i<m;i++)
            c[m+i] = b[i];
        
        int res = 0;

        for(int i=0;i<m+n;i++)
        {
            bool falg = false;
            for(int j = 0;j<i;j++)
                if(c[i] == c[j])
                {
                    flag = true;
                    break;
                }
            if(flag == false)
                res++;
        }
        return res;
    }
*/
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<m;i++)
        cin>>b[i];

    unordered_set <int> s(a,a+n);
    for(int i=0;i<m;i++)
        s.insert(b[i]);
    
    cout<<s.size()<<endl; 
        
    return 0;

}