#include<iostream>
#include<unordered_set>
using namespace std;
/*
// Naive Solution. --->  O(n^2) , O(1)
bool zero_subarr(int arr[], int n)
{

    for(int i=0;i<n-1;i++)
    {
        int curr_sum = 0;
        for(int j = i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==0)
                return true;
        }
    }
    return false;
}
*/
// Efficient Approach.  -->O(n), O(n).
// We use prefix sum technique  + hashing.
bool zero_subarr(int arr[], int n)
{
    int pre_sum = 0;
    unordered_set <int> h;
    for(int i=0;i<n;i++)
    {
        pre_sum+=arr[i];
        if(h.find(pre_sum)!=h.end())  //element not found till last
        {
           return true;
        }
        if(pre_sum == 0)
            return true;
        
        h.insert(pre_sum);
    }
    return false;
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

    cout<<zero_subarr(a,n)<<endl;
    return 0;
}