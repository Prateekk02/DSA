#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

const int CHAR = 256;
/*
// Naive Solution
int solution(string str)
{
    for(int i=0;i<str.size();i++)
    {
        bool flag = false;
        for(int j=0;j<str.size();j++)
        {
            if(i!=j && str[i] == str[j])
            {
                flag = true;
                break;
            }
            if(flag == false)
                return i;
        }
    }
    return -1;
}
*/
/*
// Method 2 --> O(n) --> Two traverasl required.
int solution(const string &str)
{
    int count[CHAR] = {0};

    for(int i=0;i<str.size();i++)
    {
        count[str[i]]++;
    }
    
    for(int i=0;i<str.size();i++)
    {
        if(count[str[i]]==1)
            return i;
    }
    return -1;
}*/

// Method 3 --> In one traversal. --> theta(n).
int solution(const string &str)
{
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    for(int i=0;i<str.size();i++)
    {
        if(fI[str[i]] == -1)
            fI[str[i]] = i;
        else   
            fI[str[i]] = -2;
        
    }
    int res = INT_MAX;
    for(int i=0;i<CHAR;i++)   // constant loop
    {
        if(fI[i]>=0)
        res = min(res,fI[i]);
    }
    return (res == INT_MAX)? -1:res;
}
int main()
{
    string str;
    getline(cin,str);
    cout<<solution(str)<<endl;
    return 0;
}