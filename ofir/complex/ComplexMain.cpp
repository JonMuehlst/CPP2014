#include "Complex.h"

#include <fstream>
#include <iostream>
using namespace std;
#include <assert.h>

int main(int argc, char **argv) {
   
    if (argc!=2) {
        cerr << "Usage: " << argv[0] << " filename" << endl;
        return 1;
    }
   
    Complex c1(3.14,-1.0), c2(42.0), c3;
    cout << c1 << endl << c2 << endl << c3 << endl << endl;
   
    Complex c5= c1 + c2; // When C++ does a shallow copy of this class, it will copy the member variables using the standard integer assignment operator
    cout << c5 << endl << endl;
   
    Complex c6= 42.0 + c1; // implicit conversion, the complex ctor is called. 42.0 is passed as the real part
    Complex c7= c1 + 42.0;
    Complex c8= 3.0 + 2.0;
    cout << c6 << endl << c7 << endl << c8 << endl << endl;
   
   
    cout << c1 + c2*c8 << endl << endl;
   
    cout << -(c1 + c2*c8) << endl << endl;
   
    cout << (c1+=2.0) << endl << (c1+=c2) << endl << endl;
    cout << (c1*=2.0) << endl << (c1*=c2) << endl << endl;

   
    if (c1==c2) {
        assert(false);
    } else {
        cout << "c1 was not c2" << endl;
    }
   
    if (c1!=c2) {
        cout << "c1 was not c2" << endl;
    } else {
        assert(false);
    }

    cout << endl;
    
    Complex c9(4.0,-2.2);
    Complex c10= c9;
    Complex c11= c10;
    Complex c12= c11;
    Complex c13= c9;
    assert(c9==c10);

    cout << c9*c10 << "==";
    c9*=c9;
    cout << c9 << "==" << (c10*c10) << "==" << (c11*=c12) << "==" << (c13*=c13) << endl << endl;
   
   
    // won't compile as we return const
    //-c9= c10;
    //(c1+c2)= c3;
    //(c1*c2)= c3;
   

    c3= c1 * c2;
    assert (c1*c2==c3);

      


    fstream fin(argv[1]);
    if (!fin) {
        cerr << "File " << argv[1] << " not open" << endl;
        return 1;
    }
   
    fin >> c1;
    if (!fin) { // checks for the failbit ; if fin failed the overloaded extract operator rewinds the stream to the start position
        if (fin.bad()) {
            cout << "Fatal error with stream, quiting" << endl;
            return 1;
        }
        cout << "Error in format. You inserted: " << endl;
        char c;
        fin.clear(); // clear the flags so we can use the extraction operator
        while (fin >> c) {
            cout << c;
        }
        cout << endl;
        return 1;
    }
   
    cout << "You inserted: " << c1 << endl;
    return 0;
}
