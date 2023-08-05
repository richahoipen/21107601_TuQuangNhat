//Thao tác dslk đơn trên struct
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Student
{
    int id;
    string name;
    int age;
    double mark_Math;
    double mark_English;
    double mark_Physic;
    double mark_average=(mark_Math+mark_Physic+mark_English)/3;
};
struct Node
{
	Student data;
	Node *link;
};
struct List
{
	Node *first,*last;
};
void Init(List &l);
Node *GetNode(Student s);
void AddFirst(List &l,Node* new_ele);
void InsertFirst(List &l,Student s);
void CreateListFirst(List &l,Student s);
void PrintList(List l);
void CreateOneStudent(Student s);
void PrintOneStudent(Student s);
void interchangeSort(List &l);
int countNodes(List l);
int main(int argc, char *argv[])
{
    Student s;
    List l;
    CreateListFirst(l,s);
    PrintList(l);
}
//3 hàm tạo danh sách
void Init(List &l)
{
	l.first=l.last= NULL;
}
Node *GetNode(Student s)
{
	Node *p;
	p=new Node;
	if(p== NULL)
		return NULL;
	p->data =s;
	p->link=NULL;
	return p;
}
void AddFirst(List &l,Node* new_ele)
{
	if(l.first== NULL)
	{
		l.first= new_ele;
		l.last = l.first;
	}
	else{
		new_ele->link = l.first;
		l.first = new_ele;
	}
}
void InsertFirst(List &l,Student s)
{
	Node* new_ele = GetNode(s);
	if (new_ele == NULL)
		return;
	AddFirst(l,new_ele);
}
void CreateOneStudent(Student s)
{
    cout<<"Enter id: ";
    cin>>s.id;
    cout<<"Enter name: ";fflush(stdin);
    cin>>s.name;
    cout<<"Enter age: ";
    cin>>s.age;
    cout<<"Enter mark Math: ";
    cin>>s.mark_Math;
    cout<<"Enter mark English: ";
    cin>>s.mark_English;
    cout<<"Enter mark Physic: ";
    cin>>s.mark_Physic;
}
void CreateListFirst(List &l,Student s)
{
	int x;
	do
	{
		/*printf("\nNhap danh sach cac so nguyen\n");
		printf("-1 de ket thuc:\n");
		scanf("%d",&x);*/
		CreateOneStudent(s);
		cout<<"Enter 0 to end list: ";
		cin>>x;
		if (x == 0)
	 		break;
		InsertFirst(l,s);
	}while(x!= 0);
	cout<<"DONE"<<endl;
}
void PrintOneStudent(Student s)
{
    cout<<"Id="<<s.id<<",name="<<s.name<<",age="<<s.age<<",Mark math="<<s.mark_Math<<",Mark english="<<s.mark_English<<",Mark physic="<<s.mark_Physic<<",Average="<<s.mark_average<<endl;
}
void PrintList(List l)
{
	Node *p;
	p = l.first;
	cout<<"List student:"<<endl;
	//Duyệt ds
	while (p!= NULL)
	{
		/*printf("%10d\t", p->data);
		p = p->link;
		printf("%10d\t", p);//bai10
		printf("\n");*/
		PrintOneStudent(p->data);
		//cout<<"Id="<<p->data.id<<",name="<<p->data.name<<",age="<<p->data.age<<",Mark math="<<p->data.mark_Math<<",Mark English="<<p->data.mark_English<<",Mark physic="<<p->data.mark_Physic<<",Average="<<p->data.mark_average<<endl;
		p=p->link;
		//cout<<"Pointer: "<<p<<endl;
	}
}
