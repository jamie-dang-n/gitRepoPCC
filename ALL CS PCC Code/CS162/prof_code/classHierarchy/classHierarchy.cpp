/* Robert Martin
 * CS162 Class Inheritance Examples
 * Summer '23*/
#include <iostream>

class A { // base class
    int aVar;
    public:
    // Constructors
    A() { aVar = 1; };
    A(int a) { aVar = a; }
    // Getter and Setter
    void setAvar(int a) { aVar = a; }  // In-line functions for compact code.
    int getAvar() { return aVar; };
    // Member function.
    void sayName() { std::cout << "I'm an A and I have an A var: " <<
        aVar << std::endl; }
};

// public inheritance:
// if public in A, then public in B
// if protected in A, then protected in B.
// if private in A, then private in B.

// protected inheritance:
// if public in A, then protected in B
// if protected in A, then protected in B.
// if private in A, then private in B.

// private inheritance: (close the "window" completely.)
// if public in A, then private in B
// if protected in A, then private in B.
// if private in A, then private in B.


class B : public A { // B inherits from A, A is the base class, B is derived class.
    int bVar; // also inherits aVar from class A
    public:
    // Constructors
    B() { bVar = 2; }
    B(int a, int b) : A(a) { bVar = b; }; // Constructor with initialization list.
                                          // a is passed to A class constructor.
    // Getter and Setter
    void setBvar(int b) { bVar = b; }
    int getBvar() { return bVar; };
    // Member function, ** Overridden **, same signature as base class.
    void sayName() { std::cout << "I'm a B, and I have an A var: " <<
        getAvar() << " and a B var: " << bVar << std::endl;
    }

};

class C : public B { // C inherits from B, which inherits from A.
    int cVar; // also inheirts bVar from class B, and aVar from class B's base class (class A)
    public:C() { cVar = 3; }
    C(int a, int b, int c) : B(a, b) { cVar = c; } // with initialization list.
    void setCvar(int c) { cVar = c; };
    int getCvar() { return cVar; };
    // sayName overrides sayName from B.
    void sayName() { std::cout << "I'm a C and I have an A var: " <<
        getAvar() << ", a B var: " << getBvar() << ", and a C var: " <<
        getCvar() << std::endl;
    }
    // overloads sayName because the signature is different by One argument.
    void sayName(const char * greeting) {
        std::cout << greeting;
        sayName();
    }
};

int main() {
    A aObj;
    B bObj;
    C cObj1;
    C cObj2(3, 4, 5); // invoking constructor that takes 3 arguments for the C class
    aObj.sayName();
    bObj.sayName();
    cObj1.B::sayName(); // calling the base class version of sayName.
    cObj2.sayName("Hi, "); // call the overloaded version.
    cObj2.sayName();  // This is the overridden version.
    return 0;
}

// Subjects:
// Overridden functions, like overloaded but signatures match.
// Types of inheritance: public, protected, private.
// Default constructors automatically invoked.
// Invoking base class constructors with initializer lists.
