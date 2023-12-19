// ********************** Revision Question************************

#include<iostream>
#include<unordered_map>
using namespace std;
/*
// Naive Solution. --> O(n2), O(1)
int solution(int arr[], int n)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int c0 = 0, c1 = 0;
        for(int j=i;j<n;j++)
        {
            if(arr[j] == 0)
                c0++;
            else 
                c1++;
            
            if(c0==c1)
                res = max(res, j-i+1);
        }
    }
    return res;

}
*/
// Efficient Approach.  --> O(n), O(n)

// Hint --> This problem is going to reduce into the problem of finding length of longest subarray with 0 sum.
// Trick ---> replace all the zero with -1 and then use above logic

int solution(int arr[], int n)
{
    for(int i=0;i<n;i++)
        if(arr[i]==0)
            arr[i] = -1;
    unordered_map<int, int> m;
    int presum = 0, res = 0;
    for(int i=0;i<n;i++)
    {
        presum+=arr[i];
        if(presum==0)
            res = i+1;
        if(m.find(presum)==m.end())
            m.insert(make_pair(presum,i));
        if(m.find(presum)!=m.end())
            res = max(res, i-m[presum]);

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