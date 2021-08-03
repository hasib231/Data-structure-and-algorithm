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
    int ar[5]={5,2,1,6,3};
    list <int> mylist (ar,ar+5);
    list <int>::iterator it;

    it = find(mylist.begin(), mylist.end(),1);
    mylist.erase(it);

//    if(it==mylist.end()){
//        cout<<"NOT FOUND"<<endl;
//    }
//    else{
//        cout<<"FOUND"<<endl;
//    }


    for(it=mylist.begin();it!=mylist.end();it++){
        cout<<*it<<"\t";
    }

    return 0;
}
