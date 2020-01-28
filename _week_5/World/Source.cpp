#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Animal {
public:
	
	Animal(const string type) : type_(type){}
	
	void Eat(const string& fruit) {
		cout << type_ << " eat " << fruit << endl;
	}
	virtual void Voice() const = 0;
	/* vitrual ������� ��� � �������� ����� ���� ����� �����
	 * � ����� �� ����������
	 * override �����. ���� ��� �������������, �� ��������� �� �����������
	 * virtual method = 0; ��� �������� ����� � ������� ������ �������� ���� ����������
	 *
	 * virtual void Voice() const { cout << type_ << " is silent." << endl; }
	 * ���� ���������� ������ �� �� ������,� �� �������� �� ����� ���������� ���. � �� ����� �������
	 */
private:
	const string type_;
};

class Dog : public Animal {
public:
	Dog() :Animal("Dog") {} // ��������� � ������ ������ ��������� ������������ �� ���������, ��������� _type ��� Dog
	
	void  Voice() const override {cout << "Bork" << endl;}
};

class Cat : public Animal {
public:
	Cat() : Animal("Cat") {} // ��������� � ������ ������ ��������� ������������ �� ���������, ��������� _type ��� Cat
	
	void  Voice() const override {cout << "Meow" << endl;}

};

class Parrot : public Animal {
public:
	Parrot(const string& name) : Animal("parrot"), name_(name) {}

	
	void  Voice()const override {
		cout << name_ << " is good!" << endl;
	}
private:
	const string name_;
};

class Horse : public Animal {
public:
	Horse() : Animal("Horse") {}
};
void MakeSound(const Animal& a) {//������� ������ �� ������,����� ������������ �������������� ����������� �������
	a.Voice();
}

int main() {
	vector<shared_ptr<Animal>> animals = {
	make_shared<Cat>(),
	make_shared<Cat>(),
	make_shared<Parrot>("Popka")
	};//������ �� ������ �� ���������. � ����� ������ ������ � ��������


	for (const auto& a : animals) {//�� ����������� �� ������
		a->Voice();
		// ��� MakeSound(*a);
	}

	
	return 0;
}