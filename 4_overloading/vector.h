#ifndef VECTOR_H
#define VECTOR_H

class vector {
    
  friend class vectorTest;
    
  private:
    double x, y, z;
    
  public:
    vector();
    vector(double,double,double);
    vector& operator+ (const vector&);
    vector& operator- (const vector&);
    double operator* (const vector&);
    vector& operator* (const double);
    vector& operator/ (const double);
    vector& operator= (const vector&);
    double operator[] (const int);
    bool operator== (const vector&);
    vector operator++ (int);
    double operator[] (const vector& v);
    
    
    FRIEND_TEST(vector_test_case, plus);
    FRIEND_TEST(vector_test_case, minus);
    FRIEND_TEST(vector_test_case, dot_product);
    FRIEND_TEST(vector_test_case, scalar_multiplication);
    FRIEND_TEST(vector_test_case, scalar_division);
    FRIEND_TEST(vector_test_case, assignment);
    FRIEND_TEST(vector_test_case, subscripting);
    FRIEND_TEST(vector_test_case, equality);
    FRIEND_TEST(vector_test_case, increment);
    
    
    
};

#endif