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
	/* vitrual говорит что у потомков может быть аткой метод
	 * с такой же структурой
	 * override метод. Если его переименовать, то программа не скомпилится
	 * virtual method = 0; Это означает чтобы в каждолм классе потомков была реализация
	 *
	 * virtual void Voice() const { cout << type_ << " is silent." << endl; }
	 * если передавать объект не по ссылке,а по значению то будет вызываться она. И ве будут сайлент
	 */
private:
	const string type_;
};

class Dog : public Animal {
public:
	Dog() :Animal("Dog") {} // наследуем у класса энимал поведение конструктора по умолчанию, определяя _type для Dog
	
	void  Voice() const override {cout << "Bork" << endl;}
};

class Cat : public Animal {
public:
	Cat() : Animal("Cat") {} // наследуем у класса энимал поведение конструктора по умолчанию, определяя _type для Cat
	
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
void MakeSound(const Animal& a) {//передаём объект по ссылке,чтобы пользоваться преимуществами абстрактных классов
	a.Voice();
}

int main() {
	vector<shared_ptr<Animal>> animals = {
	make_shared<Cat>(),
	make_shared<Cat>(),
	make_shared<Parrot>("Popka")
	};//вектор из ссылок не создается. А нужны именно вектор с ссылками


	for (const auto& a : animals) {//не обязательно по ссылке
		a->Voice();
		// или MakeSound(*a);
	}

	
	return 0;
}