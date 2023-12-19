#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

// Using stack  --> Aux sp. = O(n)
/*
    >> Create a stack.
    >> Push words one by one to the stack.
    >> Pop words from the stack and append to output.
*/
/*
void solution(string str)
{
    stack <string> s;
    string curr_word = "";
    
    // Splitting the words and pushing it in stack.

    for(char c : str)
    {
        if(c ==' ')
        {
            if(curr_word!="")
                s.push(curr_word);
                curr_word = "";   // After pushing in stack again made the curr_word empty
        }
        else
            curr_word+=c;  // Append the character one by one.
    }

    if (curr_word != "")     // to handle last word.
    {
        s.push(curr_word);
    }
    str.erase();
    // Poping out the words in reverse order
    while(!s.empty())
    {
        str.append(s.top()+ " ");
        s.pop();
    }
    cout<<str<<endl;
}*/

// Efficient Approach.  
// We reverse the indivisual words and then reverse the whole sentence.
void reverse(char str[], int low, int high)
{
    while(low<=high)
    {
        swap(str[low],str[high]);
        low++;
        high--;
    }
}
void solution(char str[],int n)
{
    int start = 0;
    for(int end = 0; end<n;end++)
    {
        if(str[end] == ' ')
        {
            reverse(str, start, end-1);
            start = end + 1;
        }
    }
    reverse(str, start, n-1);
    reverse(str, 0,n-1);
}

int main() 
{ 
    string s;
    getline(cin,s);
    int n=s.length();
    char str[n];
    strcpy(str, s.c_str());
    cout<<"After reversing words in the string:"<<endl;
    solution(str,n);
    for (int i = 0; i < n; i++) 
        cout << str[i];
    
    return 0; 
} 



/*
    >> In case you initialize a character array like below
        char str[] = "Welcome to Gfg";
        do pass array size-1 as parameter.
*/