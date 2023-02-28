#include<iostream>
#include<string>

using namespace std;
/*
    Naive Method --> theta(n) , theta(n)
    bool checkPalin(string str)
    {
        string temp = reverse(temp.begin(), temp.end());
        return (rev == str);
    }
*/
// Efficient Approach --> O(n), O(1).
bool checkPalin(string str)
{
    int begin = 0;
    int end = str.size()-1;
    while(begin<end)
    {
        if(str[begin]!=str[end])
            return false;
        begin++;
        end--;
    }
}
int main()
{
    string str;
    getline(cin,str);
    (checkPalin(str))? cout<<"Yes\n": cout<<"No\n";
    return 0;
}