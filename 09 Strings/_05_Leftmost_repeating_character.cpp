#include<iostream>
#include<string>
#include<limits.h>

using namespace std;

// Naive Solution  --> O(n^2)
/*
    int lefMost(string &str)
    {
        for(int i=0;i<str.size();i++)
        {
            for(int j=i+1;j<str.size();j++)
            {
                if(str[i] == str[j])
                    return i;
            }
        }
        return -1;
    }
*/

/*
// Method 2 --> O(n)  --> Two traversal is needed.
const int CHAR = 256;
int solution(const string &str)
{
    int count[CHAR] = {0};
    for(int i=0;i<str.size();i++)
        count[str[i]]++;
    
    for(int i=0;i<str.size();i++)
        if(count[str[i]]>1)
            return i;

    return -1;
}

/*
// Method 3
// Efficient Approach  --> takes only one traversal.
// ----> O(n)
const int CHAR = 256;
int solution(const string &str)
{
    int fIndex[CHAR];
    fill(fIndex, fIndex+CHAR, -1);

    int res = INT_MAX;
    for(int i=0;i<str.size();i++)
    {
        int fi = fIndex[str[i]];
        if(fi == -1)
            fIndex[str[i]] = i;
        else
            res = min(res,fi);
    }
    return ((res ==INT_MAX)? -1:res);
}
*/

// Optimization of method 3.
const int CHAR = 256;
int solution(const string &str)
{
    bool visited[CHAR];
    fill(visited, visited+CHAR, false);
    int res = -1;
    for(int i=str.size()-1; i>=0;i--)
    {
        if(visited[str[i]])
            res = i;
        else
            visited[str[i]] = true;
    }
    return res;
}
int main()
{
    string str;
    getline(cin,str);

    cout<<solution(str)<<endl;
    return 0;
}