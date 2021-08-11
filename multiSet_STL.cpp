#include<iostream>
#include<set>

using namespace std;

int main()
{
    multiset <int> s;
    multiset <int>::iterator it;
    s.insert(100);
    s.insert(100);
    s.insert(100);
    s.insert(100);
    s.insert(10);


    for(it=s.begin(); it!=s.end(); it++){
        cout<<*it<<endl;
    }
    return 0;


}


