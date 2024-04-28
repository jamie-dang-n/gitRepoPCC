#include <iostream>
using namespace std;
#include "student.h"

int main()
{
	Student		s1;
	Student		s2("alice");
	Student		s3("jack", 3.8);
	Student		s4(s3);

	Student	*	s5 = new Student("mike", 3.4);
	
	s1.setName("emma");
	s1.setGpa(4.0);
	
	if(s4 < s3)
	{
		cout << "s4 < s3" << endl;
	}

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << *s5 << endl;
	
	delete s5;
	return 0;
}
