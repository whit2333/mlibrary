#include <typeinfo>
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Factory {
public:
	virtual void* Create() = 0;
};


template <class T>
class FactoryImpl : public Factory
{
	virtual void* Create() override
	{
		return new T();
	}
};


class Manager
{
public:
	template <class T>
	void RegisterObjectFactory(string name)
	{
		factoryMap_[name] = new FactoryImpl<T>();
	}
	
	
	template <class T>
	T* CreateObject(string name) const
	{
		auto factory = factoryMap_.find(name);
		if(factory == factoryMap_.end())
			return nullptr;

		return static_cast<T*>(factory->second->Create());
	}
	
	
	template <class T>
	void DestroyObject(T* object)
	{
		delete object;
	}
	
	
private:
	std::map<string, Factory*> factoryMap_;
};


// ----------------------------------------------------------------------------
// Example usage
// ----------------------------------------------------------------------------

class constantsForA {
public:
	int var1;
	double var2;
	
	void initConstants(int a, double b) {
		var1 = a;
		var2 = b;
	}
	
	void print() {
		cout << var1 << " " << var2 << endl;
	}
};

class Test
{
public:
	virtual void Greet() = 0;
	virtual ~Test() = default;

	
};


class TestD : Test
{
	
public:
	void Greet() { std::cout << "it works! " << std::endl; }


};


class TestA
{
public:
	virtual void GreetA() = 0;
	virtual ~TestA() = default;
};


class TestAD : TestA
{
public:
	void GreetA() { std::cout << "it works too!" << std::endl; }
};




int main()
{
	Manager managerA;
	Manager managerB;
	managerA.RegisterObjectFactory<TestD>("a1");
	managerB.RegisterObjectFactory<TestAD>("a2");
	
	auto test  = managerA.CreateObject<Test>("a1");
	test->Greet();

	for(int i=0; i<5; i++) {
	auto test  = managerA.CreateObject<Test>("a1");
	auto test2 = managerB.CreateObject<TestA>("a2");
	
	
	//	test->init();
	test->Greet();
//	test2->GreetA();
	
		
	managerA.DestroyObject(test);
	managerB.DestroyObject(test2);
	}
}



