#ifndef b_LinkedList_h
#define b_LinkedList_h

template<class T>
class Node
{
public:
    T data;
    Node<T>* next;
};

template<class T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    unsigned size;
public:
    friend Node<T>;
    struct iterator;
    LinkedList(): head(nullptr), tail(nullptr), size(0) {}
    LinkedList(T* itBegin,T* itEnd): head(nullptr), tail(nullptr), size(0)
    {
        while(itBegin!=itEnd)
        {
            add(*itBegin);
            ++itBegin;
        }
    }
    template<class I>
    LinkedList(I itBegin,I itEnd): head(nullptr), tail(nullptr), size(0)
    {
        while(itBegin!=itEnd)
        {
            add(*itBegin);
            ++itBegin;
        }
    }
    
    LinkedList& operator = (const LinkedList& l)
    {
        if(this==&l) return *this;
        head=nullptr;
        tail=nullptr;
        size=0;
        auto it=l.begin();
        while(it!=l.end())
        {
            add(*it);
            ++it;
        }
        return *this;
    }
    
    LinkedList& add(T val);
    LinkedList& remove(iterator itr);
    
    T& get(unsigned index) const
    {
        Node<T>* it=head;
        while(index--)
        {
            it=it->next;
        }
        return it->data;
    }
    
    iterator begin() const {return iterator(*this,0);}
    iterator end() const {return iterator(*this,size);}
    
    struct iterator
    {
    public:
        const LinkedList<T>& m_container;
        unsigned m_index;
    public:
        iterator(const LinkedList<T>& l,unsigned index=0):
        m_container(l),m_index(index)
        {}
        
        bool operator !=(const iterator& iter){return m_index!=iter.m_index;}
        T& operator *(){return m_container.get(m_index);}
        iterator& operator ++(){m_index++; return *this;}
        
    };
};

template<class T>
LinkedList<T>& LinkedList<T>::add(T val)
{
    ++size;
    Node<T>* new_node=new Node<T>;
    new_node->data=val;
    if (head == nullptr)
    {
        new_node->next = nullptr;
        tail=new_node;
        head=new_node;
        return *this;
    }
    tail->next=new_node;
    new_node->next = nullptr;
    tail = new_node;
    return *this;
}
template<class T>
LinkedList<T>& LinkedList<T>::remove(iterator itr)
{
        if(head==nullptr)
        {
            std::cout<<"empty"<<std::endl;
            return *this;
        }
    
    Node<T>* current_node=head;
    unsigned index= itr.m_index;
    if(index>=(size-1))
        return *this;
    while(index--)
    {
        current_node=current_node->next;
    }
    if(current_node->next!=head)
        current_node->next=current_node->next->next;
    else
            head=current_node->next;
    
    --size;
    return *this;
}
template<class T>
std::ostream& operator <<(std::ostream& ostr, const LinkedList<T>& l)
{
    for(const T& x: l)
        ostr << x << "\t";
    return ostr;
}


#endif
