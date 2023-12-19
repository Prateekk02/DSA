#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
// Naive Solution.  --> O(n*logn)
// Sort both the string .
bool isAnagram(const string &s1, const string &s2, int m, int n)
{
    if(s1.size()!=s2.size())
        return false;
    sort(s1.begin(),s1.end());
    sort(s2.begin(), s2.end());

    return(s1==s2);
}
*/

// Efficient Solution  --> O(n) 
const int CHAR=256;

bool isAnagram(const string &s1, const string &s2)
{
    if(s1.size()!=s2.size())
        return false;

    int count[CHAR] = {0};

    for(int i=0;i<s1.size();i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i=0;i<CHAR;i++)
    {
        if(count[i]!=0)
            return false;
    }
    return true;
}

int main()
{
    string s1, s2;
    
    getline(cin,s1);
    getline(cin,s2);

    (isAnagram(s1,s2))?cout<<"Yes\n":cout<<"No\n";

    return 0;
}