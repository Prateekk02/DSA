#include<iostream>
#include<unordered_map>

using namespace std;
/*
    Naive Solution -->O(nlogn), O(1)
    void solution(int arr[], int n, int k)
    {
        sort(arr, arr+n);

        int i = 1, count = 1;
        while(i<n)
        {
            while(i<n && arr[i] = arr[i-1])
            {
                count++;
                i++;
            }
            if(count>n/k)
                cout<<arr[i-1]<<" ";
            count = 1;
            i++;
        }
    }
*/
// Efficient Approach --> O(n), O(n)
void solution(int arr[], int n, int k)
{
    unordered_map <int, int> h;
    for(int i=0;i<n;i++)
    {
        h[arr[i]]++; // count freq of each element and stores in the map.

    }
    for(auto it = h.begin(); it!=h.end(); it++)
    {
        if(it->second > (n/k))
            cout<<it->first<<" ";
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

/*
    Note --> What if the value of n is very very large and the value of k is small
    This problem can be solved in O(nk) time.
*/