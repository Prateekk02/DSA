#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;



    //Naive Solution --> O((n-k)*k*k)

    vector<int> solution(vector &arr, int k)
    {
        vector <int> v;
        int n = arr.size();
        for(int i=0;i<n-k;i++)
        {
            int count = 0;
            for(int j = 0;j<k;j++)
            {
                bool flag = false;
                for(int p = 0; p<j; p++)
                {
                    if(arr[i+j] == arr[i+p])
                    {
                        flag = true;
                        break;
                    }
                    if(flag == false)
                        count++;
                }
                v.push_back(count);
            }
        }

        return v;
    }



vector<int> solution(int arr[], int n)
{
    vector <int> v;
    unordered_set<int> s;
    
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
    for(auto it: solution(a,k))
        cout<<it<<" ";
    return 0;
}
