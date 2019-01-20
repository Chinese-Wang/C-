//��ջʵ��
#include<iostream>
using namespace std;

class SeqStack
{
    private:
        DataType data[maxSize];
        int top;
    public:
        SeqStack() { top=0; };
        ~SeqStack() {};
        void Push(const DataType item);
        DataType Pop();
        DataType GetTop();
        int NotEmpty() const  { return (top != 0); };
};

void SeqStack::Push(const DataType item)
{
    if(top==maxSize)
    {
        cout<<"��ջ����"<<endl;
        exit(0);
    }
    data[top]=item;
    top++;
}


DataType SeqStack::Pop()
{
    if(top==0)
    {
        cout<<"��ջ�ѿ�"<<endl;
        exit(0);
    }
    top--;
    return data[top];
}


DataType SeqStack::GetTop()
{
    if(top==0)
    {
        cout<<"��ջ�ѿ�"<<endl;
        exit(0);
    }
    return data[top-1];
}

