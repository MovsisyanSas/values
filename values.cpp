#include <iostream> 

class A {
public:
	std::string m_String;
	A(std::string s) : m_String(s) {
	}
	A(const A& obj) {
		this->m_String = obj.m_String;
	}
	A& operator = (const A& obj) {
		if (this != &obj)
		{
			this->m_String = obj.m_String;
		}
		return *this;
	}
	~A() {
	}
};
void print(std::string obj) {
		std::cout << 'A' << std::endl;
}
void print(A& obj) {
	std::cout << "A&" << std::endl;
}
void print(const A& obj) { 
	std::cout << "const A&" << std::endl;
}
void print(A&& obj) { 
	std::cout << "A&&" << std::endl;
}


int main() {
	A str("Say my name!");
	const A str1("Hello");
	print(str1.m_String);
	print(str);
	print(str1);
	print(A("Haisenberg"));
}