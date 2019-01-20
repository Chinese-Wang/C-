//˳���ʵ��
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
		void Insert(const DataType & item, int i);  //����
		DataType Delete(const int i);          //ɾ����i��Ԫ��
		int DataDelete(DataType x);            //ɾ��ֵΪx��Ԫ��
		int MoreDataDelete(DataType x); //ɾ����ͬԪ��
		DataType GetData(int i) const;    //��ȡ��i��Ԫ��
		int Index(DataType x);      //����ֵΪx��Ԫ�ص�ַ
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
		cout << "˳��������޷�����" << endl;
		exit(0);
	}
	if (i<0 || i>size)
	{
		cout << "����iԽ�����" << endl;
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
		cout << "˳����ѿ���Ԫ�ؿ�ɾ" << endl;
		exit(0);
	}
	if (i<0 || i>size)
	{
		cout << "����iԽ�����" << endl;
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
		cout << "����iԽ�����" << endl;
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