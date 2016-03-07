#include <iostream>
#include "stack.h"
using namespace std;
void insert(int t,Stack& b)
{
    if(b.isEmpty())
    {
        b.push(t);
    }
    
    else if(t<b.top())
    {
        int tmp=b.top();
        b.pop();
        insert(t, b);
        b.push(tmp);
    }
    else
        b.push(t);
}

void sort(Stack& a)
{
    if(!a.isEmpty())
    {
        int temp=a.top();
        a.pop();
        a.out();
        sort(a);
        insert(temp,a);
    }
}

int main()
{
    Stack s;
    int data;
    cout<<"please enter:";
    while(cin>>data)
    {
        s.push(data);
    }
    s.out();
    sort(s);
    s.out();
}