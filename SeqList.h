//顺序表实现
#include<iostream>
using namespace std;

class SeqList
{
	protected:
		int maxSize;
		int size;
		DataType *list;
		
	public:
		SeqList(int max = 0);
		~SeqList();
		int Size() const;
		void Insert(const DataType & item, int i);  //插入
		DataType Delete(const int i);          //删除第i个元素
		int DataDelete(DataType x);            //删除值为x的元素
		int MoreDataDelete(DataType x); //删除相同元素
		DataType GetData(int i) const;    //获取第i个元素
		int Index(DataType x);      //查找值为x的元素地址
};

SeqList::SeqList(int max)
{
	maxSize = max;
	size = 0;
	list = new DataType[maxSize];
}


SeqList::~SeqList()
{
	delete[]list;
}
int SeqList::Size() const
{
	return size;
}


void SeqList::Insert(const DataType &item, int i)
{
	if (size == maxSize)
	{
		cout << "顺序表已满无法插入" << endl;
		exit(0);
	}
	if (i<0 || i>size)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	for (int j = size; j > i; j--)
		list[j] = list[j + 1];
	list[i] = item;
	size++;
}


DataType SeqList::Delete(const int i)
{
	if (size == 0)
	{
		cout << "顺序表已空无元素可删" << endl;
		exit(0);
	}
	if (i<0 || i>size)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	DataType x = list[i];
	for (int j = i; j < size - 1; j++)
		list[j] = list[j + 1];
	size--;
	return x;
}


DataType SeqList::GetData(int i) const
{
	if (i<0 || i>size)
	{
		cout << "参数i越界出错" << endl;
		exit(0);
	}
	return list[i];
}

int SeqList::DataDelete(DataType x)
{
	int i,j;
	for(i=0;i<size;i++)
		if(x==list[i]) break;
	if(i==size) return 0;
	
	else
	{
		for(j=i;j<size-1;j++)
			list[j]=list[j+1];
		size--;
		return 1;
	}
}

int SeqList::MoreDataDelete(DataType x)
{
	int i,j;
	int tag=0;
	for(i=0;i<size;i++)
	{
		if(x==list[i])
		{
			for(j=i;j<size-1;j++)
				list[j]=list[j+1];
			size--;
			i--;
			tag=1;
		}
	}
	return tag;
}

void SeqList::Index(DataType x)
{
	for(int i=0;i<size;i++)
	{
		if(list[i]==x) return i;
		else return -1;
	}
}