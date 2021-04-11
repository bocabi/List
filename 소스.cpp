
#include "MyList.h"
#include <iostream>
#include <string>
using namespace std;
class Element
{
public:
	Element(string a) : a(a) {}
	string a = "";
};
void main()
{
	MyList<Element*> a;
	cout << "뒤에서 추가\n";
	a.Push_Back(new Element("1"));
	a.Push_Back(new Element("2"));
	a.Push_Back(new Element("3"));
	a.Push_Back(new Element("4"));
	a.Push_Back(new Element("5"));
	a.Push_Back(new Element("6"));
	a.Push_Back(new Element("7"));

	for (size_t i = 0; i < a.Size(); i++)
	{
		cout << a.Find(i)->a<<"\n";
	}
	cout << "뒤에서 제거\n";

	a.Pop_Back();

	for (size_t i = 0; i < a.Size(); i++)
	{
		cout << a.Find(i)->a<<"\n";
	}
	cout << "앞에서 추가\n";
	a.Push_Front(new Element("7"));
	for (size_t i = 0; i < a.Size(); i++)
	{
		cout << a.Find(i)->a << "\n";
	}
	cout << "앞에서 제거\n";
	a.Pop_Front();
	for (size_t i = 0; i < a.Size(); i++)
	{
		cout << a.Find(i)->a << "\n";
	}
	cout << "3번째 값\n";

	cout << a.Find(2)->a << "\n";

	cout << "3번째값 지우기\n";
	a.erase(3);
	for (size_t i = 0; i < a.Size(); i++)
	{
		cout << a.Find(i)->a << "\n";
	}
}