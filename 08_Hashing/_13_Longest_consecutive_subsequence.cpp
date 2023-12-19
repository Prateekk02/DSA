#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

/*
// Method 1 --> Sorting. --> O(nlogn), O(1).

int solution(int arr[], int n)
{
    sort(arr, arr+n);
    
    int res = 1;
    int currSum = 1;
    for(int i=0;i<n-1;i++)
    {
        
        if(arr[i] == arr[i+1]-1)
            currSum++;
        else
        {
            res = max(res, currSum);
            currSum = 1;
        } 
    }
    res = max(res,currSum) // To handle the case where all the elements are consecutive.
    return res;
}
*/

// Efficient Solution
// Approach 
/*
    >> Initialize res = 0
    >> Create a hash table, h
    >> Insert all elements into h
    >> for(i = 0; i<n;i++)
        if arr[i] -1 is not present in h
            curr = 1
            while(h contains arr[i]+curr)
                curr++;
            
            res = max(res, curr);
    >> Return res;
*/

// Implementation.
// Time complexity is O(n) and there are 2n no. of lookups.
int solution(int arr[], int n)
{
    int res = 0;
    unordered_set <int> s(arr, arr+n);
    for(auto x:s)
    {
        if(s.find(x-1) == s.end())
        {
            int curr = 1;
            while(s.find(x+curr)!=s.end())
            {
                curr++;
            }
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
       cin>>a[i];
    }
    cout<<solution(a,n)<<endl;
    return 0;
}