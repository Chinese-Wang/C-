#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class String
{
    private:
        char *str;   //��
        int size;    //��ǰ����
        int maxSize; //��󳤶�

        void GetNext(const String& t,int next[]) const;
        int KMPFind(const String& t,int start,int next[]) const;
    public:
        String(char *s="");
        String(int max);
        String(const String& s);
        ~String();

        void Insert(int pos,char *t);
        void Delete(int pos,int length);  //ɾ��
        String SubStr(int pos,int length);   //ȡ�Ӵ�

        char& operator[](int n);   //������[]����
        String& operator=(const String& s); //������=���� 1
        String& operator=(char* s);         //������=���� 2
        friend ostream& operator<<(ostream& out,const String& s); //������������
        friend istream& operator>>(istream& in,String& s);    //�������������
        int operator ==(const String& s) const; //������==����
        int operator ==(char* s) const; 
        friend int operator ==(char *strL,const String &strR);

        int KMPFindSubstr(const String& t,int start) const;  //KMP�㷨����
        int FindSubstr(const String& t,int start) const; //Brute-Force�㷨����
};

String::String(char* s)
{
    size=strlen(s);
    maxSize=size+1;
    str=new char[maxSize];
    strcpy(str,s);
}

String::String(int max)
{
    maxSize=max;
    size=0;
    str=new char[maxSize];
}

String::String(const String& s)
{
    maxSize=s.maxSize;
    size=s.size;
    str=new char[maxSize];
    
    for(int i = 0; i <maxSize; i++)
        str[i]=s.str[i];
}


String::~String()
{
    delete []str;
}

void String::Insert(int pos,char* t)  //��posλ�ò����ַ���t
{
    int length=strlen(t);
    int i;
    if (pos>size) 
    {
        cout<<"����λ�ô���"<<endl;
        exit(0);
    }
    if(size+length>=maxSize-1)
    {
        char* p=str;
        str=new char[size+length+1];
        for(i=0;i<=maxSize;i++)
            str[i]=p[i];
        delete []p;
    }
    for(i=size;i>=pos;i--)    //�����ַ�
        str[i+length]=str[i];
    
    for(i=0;i<length;i++)     //����
        str[pos+i]=t[i];
    
    maxSize=size+length+1;
    size=size+length;
}

void String::Delete(int pos,int length)
{
    int charsLeft=size-pos; 
    if(pos>size-1) return;

    if(length>charsLeft) length=charsLeft;

    for(int i=pos;i<=size;i++)
        str[i]=str[i+length];

    size=size-length;
}

String String::SubStr(int pos,int length)
{
    int charsLeft=size-pos;
    String temp;

    if(pos>size-1) return temp;

    if(length>charsLeft) length=charsLeft;

    delete []temp.str;
    temp.str=new char[length+1];

    for(int i=0;i<length;i++)
        temp[i]=str[pos+i];  //[] ���������
    
    temp[length]=NULL;
    temp.size=length;

    temp.maxSize=length+1;

    return temp;
}

char& String::operator[](int i)
{
    return str[i];
}

String& String::operator=(const String& s)
{
    if(maxSize<s.maxSize)
    {
        delete []str;
        str=new char[s.maxSize];
    }

    size=s.size;
    maxSize=s.maxSize;
    for(int i=0;i<=size;i++)
        str[i]=s.str[i];
    return *this;
}

String& String::operator=(char* s)
{
    int length=strlen(s);
    if(maxSize<length+1)
    {
        delete []str;
        str=new char[length+1];
        maxSize=length+1;
    }
    size=length;
    strcpy(str,s);
    return *this;
}

ostream& operator<<(ostream& out,const String& s)
{
    cout<<"s.size="<<s.size<<endl;
    cout<<"s.maxSize="<<s.maxSize<<endl;
    cout<<"s.str="<<s.str<<endl;
    return out;
}

istream& operator>>(istream& in,String& s)
{
    delete []s.str;
    cout<<"�����ַ�������:";
    cin>>s.size;
    s.maxSize=s.size+1;
    s.str=new char[s.maxSize];
    cout<<"�����ַ���:"<<endl;
    for(int i=0;i<s.size;i++)
        cin>>s.str[i];

    s.str[s.size]=NULL;
    return in;
}

int String::operator==(const String& s) const
{
    return (strcmp(str,s.str)==0);
}

int String::operator==(char* s) const
{
    return (strcmp(str,s)==0);
}

int operator==(char* strL,const String& strR)
{
    return (strcmp(strL,strR.str)==0);
}

int String::FindSubstr(const String& t,int start)const //Brute-Froce�㷨����
//�����Ӵ���startʼ���Ӵ�t���ҵ�����t���Ӵ��Ŀ�ʼ�ַ��±꣬���򷵻�-1
{
    int i=start,j=0,count=0;
    
    while(i < size && j < t.size)
    {
        if(str[i]==t.str[j])
        {
            i++;
            j++;
        }
        
        else
        {
            i=i-j+1;
            j=0;
        }
        count++;
    }
    if(j==t.size) cout<<"���ҳɹ���"<<endl;
    else cout<<"����ʧ�ܣ�"<<endl;
    
    return count;
}

int String::KMPFind(const String& t,int start,int next[])const  //KMP�㷨����
{
    int i=start,j=0,count=0;

    while(i<size && j<t.size)
    {
        if(str[i] == t.str[j])
        {
            i++;
            j++;
        }
        else if(j==0) i++;
        else j=next[j];
        count++;
    }

    if(j==t.size) cout<<"���ҳɹ���"<<endl;
    else cout<<"����ʧ�ܣ�"<<endl;

    return count;
}

void String::GetNext(const String& t,int next[])const
{
    int j=1,k=0;
    next[0]=-1;
    next[1]=0;
    while(j < t.size-1)
    {
        if(t.str[j]==t.str[k])
        {
            next[j+1]=k+1;
            j++;
            k++;
        }
        
        else if (k==0)
        {
            next[j+1]=0;
            j++;
        }
        else k=next[k];
    }
}

int String::KMPFindSubstr(const String& t,int start)const
{
    int m=t.size;
    int* next=new int[m];
    GetNext(t,next);
    int count=KMPFind(t,start,next);
    delete []next;
    return count;
}

