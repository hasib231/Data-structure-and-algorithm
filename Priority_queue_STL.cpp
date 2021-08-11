#include<iostream>
#include<queue>

using namespace std;

int main()
{
    priority_queue <int> q;
    priority_queue <string> q2;

    q.push(156);
    q.push(65);
    q.push(367);
    q.push(56);
    q.push(15);

    q2.push("hasib");
    q2.push("ashik");
    q2.push("rahat");

    while(!q.empty())
    {
        int x=q.top();
        cout<<x<<endl;
        q.pop();
    }
    cout<<endl;

    while(!q2.empty())
    {
        string str=q2.top();
        cout<<str<<endl;
        q2.pop();
    }
    return 0;

}
