#include <iostream> 

class A {
	std::string m_String;
public:
	A(std::string s) : m_String(s){
		std::cout << "A par. constructor call " << std::endl;
	}
	A(const A& obj) {
		this->m_String = obj.m_String;
		std::cout << "A copy constructor call " << std::endl;
	}
	A& operator = (const A& obj) {
		if (this != &obj)
		{
			this->m_String = obj.m_String;
		}
		return *this;
	}
	~A(){
		std::cout << "A destructor call " << std::endl;
	}
public:
	static void print(const A& obj) { //this function is already usable for lvalue,lvalue reference,const lvalue reference
		std::cout << obj.m_String << std::endl;
	}
	static void print(A&& obj) { // and this one for rvalue reference,const rvalue reference(will work even without const keyword)
		std::cout << obj.m_String << std::endl;
	}
};

int main() {
	const A str("Say my name!");
	A::print(str);
	A::print(A("Haisenberg"));
}