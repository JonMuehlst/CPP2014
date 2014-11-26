#include <iostream> 
using namespace std;

struct A {
   
   explicit A(int) { 
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
   
   A a1 = 37; // won't compile
   cout << "-------------------" << endl;
   
   A a2(37);  // compile ok
   cout << "-------------------" << endl;
   
   a1= 67; // won't compile
   cout << "-------------------" << endl;
   
   f(77); // won't compile
   cout << "-------------------" << endl;
}

int main() 
{
   g();
   return 0;
}
