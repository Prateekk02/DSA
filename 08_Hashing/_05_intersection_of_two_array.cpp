#include<iostream>
#include<unordered_set>

using namespace std;

/*
    Naive Solution --> O(m*(m+n))
    int intersection(int a[], int b[], int m, int n)
    {
        int res = 0;
        for(int i=0;i<m;i++)
        {
            bool flag = false;
            for(int j=0;j<i-1;j++)    // checking the frequency of appeared element like previous question.
            {
                if(a[j] == a[i])
                {
                    flag = true; 
                    break;
                }
            }
            if(flag)
                continue;
            
            for(int j=0;j<n;j++)   // If the element is not found previously then we find it in the next array and if the element is found then res++
            {
                if(a[i] == b[j])
                {
                    res++;
                    break;
                }
            }
            return res;
        }
    }
*/
// O(m+n) , O(m)

/*
    Approach:-
    >> create set and insert element of a in it.
    >> Traverse through array b and find b[j] element in unordered set s
    >> If found res++ -> remove(b[j]);
    >> return res.

*/
int solution(int a[], int m, int b[], int n )
{
    unordered_set <int> s ;
    for(int i=0;i<m;i++)
        s.insert(a[i]);

    int res = 0;
    for(int j=0;j<n;j++)
    {
        if(s.find(b[j])!=s.end())
        {
            res++;
            s.erase(b[j]);
        }
    }
    return res;    
}

int main()
{
    int t; 
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int a[m], b[n];
        for(int i=0;i<m;i++)
        {
           cin>>a[i];
        }
        
        for(int i=0;i<n;i++)
        {
           cin>>b[i];
        }
        cout<<solution(a,m,b,n)<<endl;
    }
}