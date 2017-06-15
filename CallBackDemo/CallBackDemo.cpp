#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

// event class
class CEvent {
public:
	virtual void hiReply() = 0;
};

// person A class , call an event
class A {
public:
	A() : m_pEvent(NULL) {}
	void sayHi() {
		cout << "A: hello B" << endl;
		if (nullptr != m_pEvent) {
			m_pEvent->hiReply();
		}
	}
	void setEvent(CEvent *event) {
		m_pEvent = event;
	}
private:
	CEvent *m_pEvent;
};

// person B class , implement the event function
class B : CEvent {
public:
	void hiReply() {
		cout << "B: I'm fine, thanks, and you ?" << endl;
	}
};

int main()
{
	A a;
	B b;
	a.setEvent((CEvent*)&b);
	a.sayHi();
	system("pause");
	return 0;
}