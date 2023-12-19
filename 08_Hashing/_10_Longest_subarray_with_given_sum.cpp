#include<iostream>
#include<unordered_map>
 using namespace std;
/*
    Naive solution --> O(n2), O(1)
    int maxLen(int arr[], int n, int sum)
    {
        int res = 0;
        for(int i=0;i<n;i++)
        {
            int currSum = 0;
            for(int j=i;j<n;j++)
            {
                curSum+=arr[j];
                if(cur_sum == sum)
                    res = max(res, j-i+1);
            }
        }
        return res;
    }
*/

// Efficient Appraoch. --> O(n) ,O(n) , complex version of subarray with given sum.

// We use prefix sum and hashing along with hash map
// We check if this element already exists in the map or not --> (preSum-sum) and map it to first index of every prefix sum and we will not store the second appearence of that element again.
// i.e the index of the leftmost prefix Sum is stored.

int maxLen(int arr[], int n, int sum)
{
    unordered_map<int,int> m;
    int preSum = 0, res = 0;
    for(int i=0;i<n;i++)
    {
        preSum+=arr[i];
        if(preSum == sum) // corner case.
            res = i+1;
        if(m.find(preSum)==m.end())  // It stores only the leftmost occurrence
            m.insert(make_pair(preSum, i));
        
        if(m.find(preSum-sum)!=m.end())
            res = max(res, i-m[preSum-sum]);
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
    int sum = 0;
    cin>>sum;
    cout<<maxLen(a,n,sum)<<endl;
    return 0;
 }