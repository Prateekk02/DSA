#include<iostream>
#include<unordered_set>

using namespace std;

int solution(int arr[], int n)
{
    unordered_set <int> s;

    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
}


/*
    Efficient Approach
    unordered_set <int> s(arr, arr+n);
    return s.size();
*/
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

        cout<<solution(arr,n)<<endl;
    }
}