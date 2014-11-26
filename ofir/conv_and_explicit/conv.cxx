#include <iostream> 
using namespace std;

struct A {
   
   A(int) { 
      cout << "In ctor" << endl; 
   }
   
   A(const A& a) { 
      cout << "In copy ctor" << endl; 
   }
   
   A& operator=(const A& a) { 
      cout << "In operator=" << endl; 
      return *this;
   }
   
};

void f (A a) {
   cout << "In f" << endl;
}

void g() {
   
   A a1 = 37; // calls the ctor that gets int
   cout << "-------------------" << endl;
   
   A a2(37);  // same
   cout << "-------------------" << endl;
   
   a1= 67; // builds a new A and then calls operator =
   cout << "-------------------" << endl;
   
   f(77); // builds a new A and then send it to f
   cout << "-------------------" << endl;
}

int main() 
{
   g();
   return 0;
}
