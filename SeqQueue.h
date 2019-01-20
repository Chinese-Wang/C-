//���У�˳���
#include<iostream>
using namespace std;

class SeqQueue
{
    private:
        DataType data[maxSize];
        int front;                //��ͷָʾ��
        int rear;                 //��βָʾ��
        int count;                //����Ԫ�ؼ�����
    public:
        SeqQueue() { front=rear=0; count=0; }
        ~SeqQueue() {}
        void Append(const DataType& item);
        DataType Delete();
        DataType GetFront() const;
        int NotEmpty() const { return(count!=0);}
};


void SeqQueue::Append(const DataType& item)
{
    if(count>0 && front==rear)
    {
        cout<<"��������"<<endl;
        exit(0);
    }
    data[rear]=item;
    rear=(rear+1)%maxSize;
    count++;
}


DataType SeqQueue::Delete() 
{
    if(count==0)
    {
        cout<<"�����ѿգ�"<<endl;
        exit(0);
    }
    DataType temp=data[front];
    front=(front+1)%maxSize;
    count--;
    return temp;
}


DataType SeqQueue::GetFront() const
{
    if(cout==0)
    {
        cout<<"�����ѿգ�"<<endl;
        exit(0);
    }
    return data[front];
}

