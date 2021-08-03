#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>
#include<iterator>
#include<algorithm>
#include<list>

using namespace std;

int main()
{
    list <float> mylist;
    list <float>::iterator it;

    mylist.push_back(10);
    mylist.push_back(15);
    mylist.push_front(5);
    mylist.push_front(20);
    mylist.push_back(-1);

    mylist.reverse();
    cout<<mylist.size()<<endl;

    for(it=mylist.begin();it!=mylist.end();it++){
        cout<<*it<<endl;
    }

    return 0;
}
