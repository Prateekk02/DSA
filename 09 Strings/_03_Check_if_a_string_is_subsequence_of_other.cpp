#include<iostream>
#include<string>

using namespace std;
/*
    Naive Solution --> O(2^n*n)
    Find all the subsequence and then match it with the s2 string.
*/

// Efficient approach  --> O(m+n), O(1)
// Using two pointer method for s1 and s2.
// Iterative solution.
bool checkSubseq (const string &s1, const string &s2)
{
    if(s1.size()<s2.size())
        return false;   // optimization

    int j=0;
    for(int i=0;i<s1.size() && j<s2.size();i++)
    {
        if(s1[i]==s2[j])
            j++;
    }
    return (j == s2.size());
}

/*
    Recursive solution. --> O(m+n), O(m+n)      
    // Less optimized compared to iterative in terms of space complexity.
    
    bool isSubSeqRec(string s1, string s2,int m,int n)
    {

        if(m==0)
            return true;
        if(n==0)
            return false;
        
        if(s1[n-1] == s2[m-1])
            return(isSubSeqRec(s1,s2,n-1,m-1));
        else
            return isSubSecRec(s1,s2,n-1,m);

    }
*/
int main()
{
    string s1;
    getline(cin,s1);
    string s2;
    getline(cin,s2);
    (checkSubseq(s1,s2))?cout<<"Yes\n":cout<<"No\n";
    return 0; 
}