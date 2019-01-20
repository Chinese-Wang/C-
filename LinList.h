//链表
#include<iostream>
using namespace std;

//结点类
template<class T>class LinList;
template<class T>
class ListNode
{
	friend class LinList<T>;
	protected:
		ListNode<T> *next;
		T data;

	public:
		ListNode(ListNode<T> *ptrNext = NULL) { next=ptrNext; } //构造第一个结点

		ListNode(const T &item,ListNode<T> *ptrNext = NULL)
		{ data=item; next=ptrNext; }  //构造其他结点

		~ListNode() {}
};

//单链表类的定义
template<class T>
class LinList
{
	private:
		ListNode<T> *head;          //头指针
		int size;                   //当前元素个数
		ListNode<T> *Index(int i);  //定位
	public:
		LinList();
		~LinList();
		int Size() const;          //取当前元素个数
		void Insert(const T& item,int i); //插入
		T Delete(int i);           //删除
		T GetData(int i);          //取数据元素
		void OrderInsert(const T& item);   //数据元素有序插入
		void LinListSort();        //对数据元素就地排序
		void MoreDataDelete(const T& item);  //删除链表中值为x的重复元素
};

//单链表类实现
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


//查找第i个节点
template<class T>
ListNode<T> *LinList<T>::Index(int i)
//返回指向第i个结点的指针
{
	if(i<-1||i>size-1)
	{
		cout<<"参数i越界出错!"<<endl;
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


//返回链表长度
template<class T>
int LinList<T>::Size() const
{
	return size;
}


//插入节点
template<class T>
void LinList<T>::Insert(const T& item,int i)
{
	if(i<0||i>size)
	{
		cout<<"参数i越界出错!"<<endl;
		exit(0);
	}
	ListNode<T> *p =Index(i-1);
	ListNode<T> *q=new ListNode<T>(item,p->next);
	p->next=q;
	size++;
}


//删除第i个节点
template<class T>
T LinList<T>::Delete(int i)
{
	if(size==0)
	{
		cout<<"链表已空无元素可删"<<endl;
		exit(0);
	}
	if(i<0||i>size-1)
	{
		cout<<"参数i越界出错!"<<endl;
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


//获取第i个节点
template<class T>
T LinList<T>::GetData(int i)
{
	if(i<0||i>size-1)
	{
		cout<<"参数i越界出错!"<<endl;
		exit(0);
	}
	ListNode<T>* p=Index(i);
	return p->data;
}


//数据元素有序插入
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


//对数组中元素就地排序
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


//删除链表中值为i的重复元素
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