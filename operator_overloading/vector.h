#ifndef VECTOR_H
#define VECTOR_H

class vector {
    
  friend class vectorTest;
    
  private:
    double x, y, z;
    
  public:
  
    //--------------------------------------------
    //    ctors
    //--------------------------------------------
    vector();
    vector(double,double,double);
    //--------------------------------------------
    
    
    //--------------------------------------------
    //    Binary operators
    //--------------------------------------------
    const vector operator/ (const double);
    vector& operator= (const vector&);
    vector& operator+= (const vector&);
    vector& operator-= (const vector&);
    vector& operator*= (const double);
    bool operator== (const vector&);
    bool operator!= (const vector&);
    //--------------------------------------------
    
    
    //--------------------------------------------
    //    unary operators
    //--------------------------------------------
    vector operator++ (int);
    const vector operator-() const;
    double operator[] (const int);
    //--------------------------------------------
    // double operator[] (const vector& v);
    
    
    //--------------------------------------------
    //    Friend global binary operators
    //--------------------------------------------
    friend const vector operator+ (const vector&, const vector&);
    friend const vector operator+ (const vector&, const double);
    friend const vector operator+ (const double, const vector&);
    friend const vector operator- (const vector&, const vector&);
    friend const vector operator- (const vector&, const double);
    friend const vector operator- (const double, const vector&);
    friend const double operator* (const vector&, const vector&);
    friend const vector operator* (const vector&, const double);
    friend const vector operator* (const double, const vector&);
    //--------------------------------------------
    
    
    //--------------------------------------------
    //    Friend global io operators
    //--------------------------------------------
    friend std::ostream& operator<< (std::ostream&, const vector&);
    //--------------------------------------------
    
    
    //--------------------------------------------
    //          Friend tests
    //--------------------------------------------
    FRIEND_TEST(vector_test_case, plus);
    FRIEND_TEST(vector_test_case, rscalar_plus);
    FRIEND_TEST(vector_test_case, lscalar_plus);
    FRIEND_TEST(vector_test_case, minus);
    FRIEND_TEST(vector_test_case, rscalar_minus);
    FRIEND_TEST(vector_test_case, lscalar_minus);
    FRIEND_TEST(vector_test_case, unary_minus);
    FRIEND_TEST(vector_test_case, dot_product);
    FRIEND_TEST(vector_test_case, rscalar_multiplication);
    FRIEND_TEST(vector_test_case, lscalar_multiplication);
    FRIEND_TEST(vector_test_case, scalar_division);
    FRIEND_TEST(vector_test_case, assignment);
    FRIEND_TEST(vector_test_case, plus_assignment);
    FRIEND_TEST(vector_test_case, minus_assignment);
    FRIEND_TEST(vector_test_case, multiplication_assignment);
    FRIEND_TEST(vector_test_case, subscripting);
    FRIEND_TEST(vector_test_case, equality);
    FRIEND_TEST(vector_test_case, inequality);
    FRIEND_TEST(vector_test_case, increment);
    FRIEND_TEST(vector_test_case, output);
    //--------------------------------------------
    
    
};

#endif