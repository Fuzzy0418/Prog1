#include <iostream>

class B1 {
public:
	virtual void vf() {std::cout << "B1::vf()\n";}
	void f() {std::cout << "B1::f()\n";}
	virtual void pvf() {std::cout << "B1:pvf()\n";}
};

class D1 : public B1 {
public:
	void vf() override {std::cout << "D1::vf()\n";}
	void f() {std::cout << "D1::f()\n";}
};

class D2 : public D1 {
public:
	void pvf() override {std::cout << "D2::pvf()\n";}
};

class B2 {
public:
	virtual void pvf() {std::cout << "B2::pvf()\n";}
};

class D21 : public B2 {
public:
	std::string asd = "D21::pvf()\n";
	void pvf() {std::cout << asd;}
};

class D22 : public B2 {
public:
	int asd = 22;
	void pvf() {std::cout << asd << "\n";}
};

void call(B1& temp) {
	temp.vf();
	temp.f();
};

void f(B2& temp){
	temp.pvf();
};

int main()
{
	B1 b;
	D1 d;
	D2 dd;
	D21 degy;
	D22 dketto;


	b.vf();
	b.f();

	d.vf();

	call(d);

	dd.f();
	dd.vf();
	dd.pvf();

	f(degy);
	f(dketto);

	return 0;
}