#include <iostream>
using namespace std;

//ֻ����ջ�ϴ�������
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
	//��operator new �� ��λnew���ʽ ��������
	void* operator new(size_t n) = delete;
	void operator delete(void* p) = delete;
};
int main()
{
	StackType::CreatStackObj().Print();  // �൱��һ����
	StackType obj = StackType::CreatStackObj();
	obj.Print();
	return 0;
}

//ֻ���ڶ��ϴ�������
class Test
{
public:
	static Test* CreatObj()
	{
		return new Test;
	}

private:
	//�����캯������Ϊ˽��
	Test() {};

	//�����������������Ǵ���һ��ȱ�ݵģ����������friend�����������ͻ�ʧЧ
	//��������ֻ����,��ʵ�֡���Ϊʵ�ֿ��ܻ���鷳�������Ǳ�����ܲ���Ҫ
	Test(const Test&t);

	//C++11�ṩ����������취----ɾ������
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