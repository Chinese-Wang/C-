//Á´Ê½¶ÑÕ»
#include<iostream>
using namespace std;

template<class T> class LinStack

template<class T>
class StackNode
{
    friend class LinStack<T>;
    private:
        T data;
        StackNode<T>* next;
    public:
        StackNode(StackNode<T>* ptrNext=NULL) { next=NULL; }
        StackNode(const T& item,StackNode<T>* ptrNext=NULL)
        { data=T; next=ptrNext; }
        ~StackNode() {};
};

template<class T>
class LinStack
{
    private:
        StackNode<T>* head;
        int size;
    public:
        LinStack();
        ~LinStack();

        void Push(const T& item);
        T Pop();
        T GetTop() const;
        int NotEmpty() const;
};

template<class T>
LinStack<T>::LinStack()
{
    head=new StackNode<T>;
    size=0;
}

template<class T>
LinStack<T>::~LinStack()
{
    StackNode<T>* p,*q;
    p=head;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        delete q;
    }
}

template<class T>
void LinStack::Push(const T& item)
{
    StackNode<T>* newNode=new StackNode<T>(item,head->next);
    head->next=newNode;
    size++;
}

template<class T>
T LinStack::Pop()
{
    if(size==0)
    {
        cout<<"¶ÑÕ»ÒÑ¿ÕÎÞÔªËØ¿ÉÉ¾"<<endl;
        exit(0);
    }
    StackNode<T>* p=head->next;
    T data=p->data;
    head->next=head->next->next;
    delete p;
    size--;
    return data;
}

template<class T>
T LinStack::GetTop() const
{
    if(size==0)
    {
        cout<<"¶ÑÕ»ÒÑ¿Õ"<<endl;
        exit(0);
    }
    return head->next->data;
}

template<class T>
int LinStack::NotEmpty() const
{
    if(size!=0) return 1;
    else return 0;
}

