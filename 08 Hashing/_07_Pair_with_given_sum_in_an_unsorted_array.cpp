#include<iostream>
#include<unordered_set>
using namespace std;
/*
    Naive Solution
    bool isPair(int arr[], in n , int sum)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]+arr[j]==sum)
                    return true;
            }
        }
        return false;
    }
*/

// Efficient solution.

bool isPair(int arr[], int n, int sum)
{
    unordered_set <int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(sum-arr[i]) != s.end())
        {
            return true;
        }
        s.insert(arr[i]);
    }
    return false;
}

int main()
{
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum = 0;
    cin>>sum;
    cout<<isPair(arr,n,sum)<<endl;
    return 0;
}