#include<bits/stdc++.h>
using namespace std;

struct myHash
{
    int bucket;
    list<int> *table;
    myHash(int b)
    {
        bucket = b;
        table = new list<int> [b];
    }

    void insert(int key)
    {
        int i = key % bucket;
        table[i].push_back(key);
    }
    bool search(int key)
    {
        int i = key % bucket;
        for(auto x : table[i])
            if(x == key)
                return true;
        return false;
    }
    void remove(int key)
    {
        int i=key % bucket;
        table[i].remove(key);
    }
};

int main()
{
    myHash mh(7);
    mh.insert(70);
    mh.insert(71);
    mh.insert(56);
    mh.insert(9); 
    mh.insert(72);
    cout<<"Search for 71 "<<mh.search(71)<<endl;
    cout<<"Search for 9 "<<mh.search(9)<<endl;
    mh.remove(9);
    mh.remove(72);
    cout<<"Search for 9 "<<mh.search(9)<<endl;
    cout<<"Search for 71 "<<mh.search(71)<<endl;
    cout<<"Search for 72 "<<mh.search(72)<<endl;
    return 0;
}
