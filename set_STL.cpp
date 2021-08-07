#include<bits/stdc++.h>

using namespace std;

int main()
{
    set <int> s;
    set <int>::iterator it;
    s.insert(10);
    s.insert(3);
    s.insert(5);
    s.insert(8);
    s.insert(13);

//    it=s.find(5);
//    s.erase(it);

    s.erase(s.find(5));



    for (it=s.begin(); it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
}
