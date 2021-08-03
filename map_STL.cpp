#include<iostream>
#include<stdio.h>
#include<string>
#include<iterator>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
    map <string, int> m;
    map <string, int>::iterator it;

    m["dipta"]=43;
    m["arnob"]=42;
    m["arnob"]=45;
    m.insert(make_pair("nabil",41));

    for(it=m.begin();it!=m.end();it++){
        cout<<it->first <<" "<<it->second<<endl;
    }

    return 0;
}
