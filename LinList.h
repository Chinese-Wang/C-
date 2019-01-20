//����
#include<iostream>
using namespace std;

//�����
template<class T>class LinList;
template<class T>
class ListNode
{
	friend class LinList<T>;
	protected:
		ListNode<T> *next;
		T data;

	public:
		ListNode(ListNode<T> *ptrNext = NULL) { next=ptrNext; } //�����һ�����

		ListNode(const T &item,ListNode<T> *ptrNext = NULL)
		{ data=item; next=ptrNext; }  //�����������

		~ListNode() {}
};

//��������Ķ���
template<class T>
class LinList
{
	private:
		ListNode<T> *head;          //ͷָ��
		int size;                   //��ǰԪ�ظ���
		ListNode<T> *Index(int i);  //��λ
	public:
		LinList();
		~LinList();
		int Size() const;          //ȡ��ǰԪ�ظ���
		void Insert(const T& item,int i); //����
		T Delete(int i);           //ɾ��
		T GetData(int i);          //ȡ����Ԫ��
		void OrderInsert(const T& item);   //����Ԫ���������
		void LinListSort();        //������Ԫ�ؾ͵�����
		void MoreDataDelete(const T& item);  //ɾ��������ֵΪx���ظ�Ԫ��
};

//��������ʵ��
template<class T>
LinList<T>::LinList()
{
	head = new ListNode<T>();
	size = 0;
}

template<class T>
LinList<T>::~LinList()
{
	ListNode<T>*p,*q;
	p=head;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		delete q;
	}
	size=0;
	head=NULL;
}


//���ҵ�i���ڵ�
template<class T>
ListNode<T> *LinList<T>::Index(int i)
//����ָ���i������ָ��
{
	if(i<-1||i>size-1)
	{
		cout<<"����iԽ�����!"<<endl;
		exit(0);
	}
	if(i==-1) return head;
	ListNode<T> *p=head->next;
	int j=0;
	while(p!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	return p;
}


//����������
template<class T>
int LinList<T>::Size() const
{
	return size;
}


//����ڵ�
template<class T>
void LinList<T>::Insert(const T& item,int i)
{
	if(i<0||i>size)
	{
		cout<<"����iԽ�����!"<<endl;
		exit(0);
	}
	ListNode<T> *p =Index(i-1);
	ListNode<T> *q=new ListNode<T>(item,p->next);
	p->next=q;
	size++;
}


//ɾ����i���ڵ�
template<class T>
T LinList<T>::Delete(int i)
{
	if(size==0)
	{
		cout<<"�����ѿ���Ԫ�ؿ�ɾ"<<endl;
		exit(0);
	}
	if(i<0||i>size-1)
	{
		cout<<"����iԽ�����!"<<endl;
		exit(0);
	}
	ListNode<T>* s,*p=Index(i-1);
	s=p->next;
	p->next=p->next->next;
	T x=s->data;
	delete s;
	size--;
	return x;
}


//��ȡ��i���ڵ�
template<class T>
T LinList<T>::GetData(int i)
{
	if(i<0||i>size-1)
	{
		cout<<"����iԽ�����!"<<endl;
		exit(0);
	}
	ListNode<T>* p=Index(i);
	return p->data;
}


//����Ԫ���������
template<class T>
void LinList<T>::OrderInsert(const T& item)
{
	ListNode<T>* curr,*pre=head;
	curr=head->next;
	while(curr!=NULL&&curr->data<=item)
	{
		pre=curr;
		curr=curr->next;
	}
	ListNode<T> *q=new ListNode<T>(item,pre->next);
	pre->next=q;
	size++;
}


//��������Ԫ�ؾ͵�����
template<class T>
void LinList<T>::LinListSort()
{
	ListNode<T>* curr,*pre,*p,*q;
	p=head->next;
	head->next=NULL;
	while(p!=NULL)
	{
		curr=head->next;
		pre=head;
		while(curr!=NULL&&curr->data<=p->data)
		{
			pre=curr;
			curr=curr->next;
		}
		q=p;
		p=p->next;
		q->next=pre->next;
		pre->next=q;
	}
}


//ɾ��������ֵΪi���ظ�Ԫ��
template<class T>
void LinList<T>::MoreDataDelete(const T& item)
{
	ListNode<T>* p,*temp;
	p=head->next;
	while(p->next!=NULL)
	{
		if(p->data==item) break;
		else p=p->next;
	}
	while(p->next!=NULL)
	{
		if(p->next->data==item)
		{
			temp=p->next;
			p->next=temp->next;
			delete temp;
		}
		else p=p->next;
	}
}