#include<iostream>
#include<unordered_map>
using namespace std;
// This solution is based on Moore's Voting Algorithm
// Let 'res_count' be the number of elements in the result
// res_count <= k-1

void solution(int arr[], int n, int k)
{
    unordered_map<int, int> m;

    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i])!=m.end())
            m[arr[i]]++;
        else if(m.size()<k-1)
        {
            m[arr[i]] = 1;
        }
        else 
            for(auto x: m)
            {
                x.second--;
                if(x.second == 0)
                    m.erase(x.first);
            }
    }

    for(auto x:m)
    {
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(x.first == arr[i])
                count++;
        }
         if(count>n/k)
        cout<<x.first<<" ";
    }

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
    int k;
    cin>>k;
    solution(a,n,k);
    return 0;
}