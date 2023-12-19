#include<iostream>

#include<unordered_map>

using namespace std;
/*
// Naive Solution --> O(n2), O(1).
int solution(int a[], int b[],int n)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int sum1 = 0, sum2 = 0; 
        for(int j=i;j<n;j++)
        {
            sum1+=a[j];
            sum2+=b[j];
            if(sum1==sum2)
                res = max(res, j-i+1);
        }
    }
    return res;
}
*/

// Efficient Approach
// Hint --> This problem is going to reduce into the problem of finding the longest subarray with 0 sum.
// Approach --> Subtract both the arrays and then find longest zero sum sub array in the new array.




int solution(bool a[], bool b[],int n)
{
    int res = 0, presum = 0;
    int temp[n];
    for(int i=0;i<n;i++)
    {
        temp[i] = a[i]-b[i];
    }
    unordered_map<int, int> m;
    for(int i=0;i<n;i++)
    {
        presum+=temp[i];
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
    bool a[n], b[n];
    for(int i=0;i<n;i++)
       cin>>a[i];
    
    for(int i=0;i<n;i++)
        cin>>b[i];
    
    cout<<solution(a,b,n)<<endl; 

    return 0;
}