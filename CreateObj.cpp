#include <iostream>
using namespace std;

//只能在栈上创建对象
class StackType
{
public:
	static StackType CreatStackObj()
	{
		StackType obj;
		return obj;
	}
	void Print()
	{
		cout << "StackType::Print()" << endl;
	}
private:
	StackType()
	{}
	//将operator new 和 定位new表达式 功能屏蔽
	void* operator new(size_t n) = delete;
	void operator delete(void* p) = delete;
};
int main()
{
	StackType::CreatStackObj().Print();  // 相当于一个类
	StackType obj = StackType::CreatStackObj();
	obj.Print();
	return 0;
}

//只能在堆上创建对象
class Test
{
public:
	static Test* CreatObj()
	{
		return new Test;
	}

private:
	//将构造函数申明为私有
	Test() {};

	//防拷贝，但是这样是存在一个缺陷的，如果类中有friend函数该做法就会失效
	//这里我们只声明,不实现。因为实现可能会很麻烦，而我们本身可能不需要
	Test(const Test&t);

	//C++11提供的完美解决办法----删除函数
	Test(const Test&t) = delete;
private:
	int _data;
};

int main()
{
	Test *pt = Test::CreatObj();
	/*Test obj;
	Test obj3(*pt);*/

	return 0;
}