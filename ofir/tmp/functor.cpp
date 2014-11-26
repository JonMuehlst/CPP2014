#include <iostream>
 
class myFunctorClass
{
    public:
        myFunctorClass (int x) : _x( x ) {}
        int operator() (int y) { return _x + y; }
    private:
        int _x;
};
 
struct Accumulator
{
    int counter;
    int operator()(int i) { return counter += i; }
};

int main()
{
    myFunctorClass addFive( 5 );
    std::cout << addFive( 6 ) << std::endl;
    std::cout << addFive( 5 ) << std::endl;

    std::cout << std::endl << std::endl;
    
    Accumulator acc;
    acc.counter = 0;
    std::cout << acc(10) << std::endl; //prints "10"
    std::cout << acc(20) << std::endl; //prints "30"

 
    return 0;
}