#include <iostream>
#include <vector>
using namespace std;

class CirQueue{
public:
    typedef float Item;
    size_t MAX_SIZE;
    vector<Item> m_data;
    size_t m_front, m_rear, m_n;
    inline CirQueue():
    m_front(0), m_n(0), MAX_SIZE(5), m_data(vector<Item> (MAX_SIZE)),
    m_rear(MAX_SIZE-1)
    {}
    inline CirQueue(size_t x):
    m_front(0), m_n(0), MAX_SIZE(x), m_data(vector<Item> (MAX_SIZE)),
    m_rear(MAX_SIZE-1)
    {}

    inline void init()
    { m_front = 0; m_rear = MAX_SIZE - 1; m_n = 0;}
    inline bool isEmpty() const{ return m_n == 0; }
    inline bool isFull() const{ return m_n >= MAX_SIZE;}
    inline size_t size() const{ return m_n; }
    inline Item& front();
    const inline Item& rear();
    CirQueue& push(const Item& x);
    CirQueue& pop();
    void out() const;
};

CirQueue::Item& CirQueue::front()
{ return m_data[m_front];}
const CirQueue::Item& CirQueue::rear()
{ return m_data[m_rear];}
void CirQueue::out() const
{
    cout << "N = " << m_n << ": ";
    for(size_t i=0, j = m_front; i < m_n;)
    {
        cout << m_data[j++];
        ++i;
        if(i < m_n) cout << ", ";
        j %= MAX_SIZE;
    }
    cout << endl;
}
CirQueue& CirQueue::push(const CirQueue::Item& x){ if(!isFull())
{
    m_rear = (m_rear + 1) % MAX_SIZE;
    m_data[m_rear] = x;
    ++m_n;
}
    return *this;
}
CirQueue& CirQueue::pop()
{
    if(!isEmpty())
    {
    m_front = (m_front + 1) % MAX_SIZE;
    --m_n;
    }
    return *this;
}
class Stack
{
    CirQueue CirQ;
public:
    Stack(){}
    Stack(size_t x):CirQ(x){}
    inline size_t capacity() const {return CirQ.MAX_SIZE;}
    inline size_t size() const {return CirQ.size();}
    inline bool isEmpty() const {return CirQ.isEmpty();}
    inline bool isFull() const {return CirQ.isFull();}
    void oo()const {CirQ.out();}
    Stack& push(const CirQueue::Item& x){
        if(!CirQ.isFull())
        {
            const size_t s=CirQ.size();
            if(s==0)
                CirQ.push(x);

            else
            {
                CirQ.push(x);
                CirQueue::Item y;   //y=front
                
                for(size_t i=0;i<s;i++)
                {
                    y=CirQ.front();
                    CirQ.pop();
                    CirQ.push(y);
                }
            }
        }
        return *this;
    }
    Stack& pop() {
        
        if(!CirQ.isEmpty()){ CirQ.pop();}
        return *this;
    }
    void const out()
    {
        cout << "Stack N = " << CirQ.size() << ": ";
        size_t j = CirQ.m_rear;
        for(size_t i=0; i < CirQ.size();)
        {
            cout << CirQ.m_data[j];
            if(j==0)
                j=CirQ.MAX_SIZE;
            j--;
            ++i;
            if(i < CirQ.size()) cout << ", ";
            j %= CirQ.MAX_SIZE;
        }
        cout << endl;
    
    }
};
int main()
{
    Stack stk1{};
    stk1.push(1);
    stk1.out();
    stk1.push(2).push(3);
    stk1.out();
    stk1.push(4);
    stk1.pop();
    stk1.out();
    stk1.push(5).push(6).push(7);
    stk1.out();
    stk1.pop().pop().pop().pop();
    stk1.out();
}