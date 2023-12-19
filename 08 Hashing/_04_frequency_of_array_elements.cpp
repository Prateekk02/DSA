#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<utility>
using namespace std;
/*
    Naive Approach: O(n2), O(1)

    ---> 

    void printFreq(int arr[], int n)
    {
        for(int i = 0; i<n;i++)
        {
            bool flag = false;     ........
            for(int j=0;j<i;j++)
                if(arr[i]==arr[j])           // check if seen before.
                {
                    flag = true;
                    break;
                }                  .........
                if(flag)            ..........................
                {
                    continue;           // If seen ignored.
                }                   ..........................

                int freq = 1;       .........................
                for(int j=i+1; j<n;j++)
                {
                    if(arr[i] == arr[j])           // If not seen before count frequency.
                        freq++;
                }                  ..............................
                cout<<arr[i]<<" "<<freq<<endl;
        }
    }

*/

// Efficient Approach.  ---> theta(n), O(n).

void solution(int arr[], int n)
{
    unordered_map <int, int> m;
    for(int i=0;i<n;i++)
        m[arr[i]]++;         // Putting all the entries in Hashmap

        
    // We are doing ++ so as to put the first entry with value 1 and not as 0.

    for(auto e : m)
        cout<<e.first<<" "<<e.second<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        solution(arr, n);
    }
}