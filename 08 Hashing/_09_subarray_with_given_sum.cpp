#include<iostream>
#include<unordered_set>

using namespace std;
/*
// Naive Solution. --> O(n^2), O(1).

bool subarr_sum(int arr[], int n, int sum)
{
    for(int i=0;i<n;i++)
    {
        int currSum = 0;
        for(int j=i;j<n;j++)
        {
            currSum+=arr[j];
            if(currSum == sum)
                return true;
        }

    }
    return false;
}
*/

// Efficient Solution.  --> O(n), O(n).

bool subarr_sum (int arr[], int n, int sum)
{
    int preSum = 0;
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        preSum+=arr[i];
        if(preSum==sum)
            return true;
        if(s.find(preSum-sum)!=s.end())
            return true; 

        s.insert(preSum);       
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
    int sum = 0;
    cin>>sum;
    cout<<subarr_sum(a,n,sum)<<endl;
    return 0;
}