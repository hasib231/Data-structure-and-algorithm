#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<iterator>
#include<algorithm>

bool myfunc(int a,int b){
    return (a>b);
    }
using namespace std;

int main()
{
    vector <int> vec;
    vector <int>::iterator it;

    vec.push_back(10);
    vec.push_back(432);
    vec.push_back(32);
    vec.push_back(52);
    vec.push_back(12);
    vec.push_back(50);

    sort(vec.begin(), vec.end(),myfunc);

    for(it=vec.begin(); it!=vec.end();it++){
        cout<<*it<<"\t";
    }
    puts("");

    return 0;
}
