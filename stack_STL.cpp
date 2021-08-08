#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack <string> s;

    s.push("hasib");
    s.push("ashik");
    s.push("dipta");
    s.push("nabil");

//    s.pop();
//    cout<<s.top()<<endl;

    while(!s.empty()){

        string str;
        str=s.top();
        cout<<str<<endl;
        s.pop();
    }
}
