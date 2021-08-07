#include<bits/stdc++.h>

using namespace std;

int main()
{
    set <string> s;
    set <string>::iterator it;
    s.insert("hasib");
    s.insert("dipta");
    s.insert("ashik");
    s.insert("nabil");


    pair <set <string>::iterator, bool> p;
    p=s.insert("dipta");

    if(p.second==false){
        cout<<"can't insert"<<endl;
    }
    else{
        cout<<"inserted"<<endl;
    }



    for (it=s.begin(); it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
}
