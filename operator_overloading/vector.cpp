#include <iostream>
#include <string>
#include <ostream>
#include "gtest/gtest.h" // google test
#include "vector.h"
#include <assert.h>

vector::vector(){
    
    this->x = 0;
    this->y = 0;
    this->z = 0;
    
}

vector::vector(double x, double y, double z){
    
    this->x = x;
    this->y = y;
    this->z = z;
    
}

const vector vector::operator/ (const double scalar){
    
    vector ans = vector();
    ans.x = this->x / scalar;
    ans.y = this->y / scalar;
    ans.z = this->z / scalar;
    
    return ans;    
    
}

const double operator* (const vector& v1, const vector& v2){
    
    double a = v1.x*v2.x;
    double b = v1.y*v2.y;
    double c = v1.z*v2.z;
    
    return a + b + c;
    
}
vector& vector::operator= (const vector& v){
    
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    
    return *this;
}

vector& vector::operator+= (const vector& v){
    
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    
    return *this;

}

vector& vector::operator-= (const vector& v){
    
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    
    return *this;
    
}

vector& vector::operator*= (const double scalar){
    
    *this = *this * scalar;
    
    return *this;
    
}
    
bool vector::operator== (const vector& v){
    
    double eps = 0.0001;
    
    double a = this->x - v.x; 
    double b = this->y - v.y;
    double c = this->z - v.z;
    
    if(a<0)
        a *= -1;
    if(b<0)
        b *= -1;
    if(c<0)
        c *= -1;
        
    if( (a < eps) && (b < eps) && (c < eps) )
        return true;
        
    return false;
    
}

bool vector::operator!= (const vector& v){
    
    return (!(*this == v));
    
}

vector vector::operator++ (int i = 1){
    
    this->x += 1;
    this->y += 1;
    this->z += 1;
    
    return *this;
    
}

const vector vector::operator- () const{
    
    vector ans = vector();
    ans.x = -this->x;
    ans.y = -this->y;
    ans.z = -this->z;

    return ans;    
    
}

double vector::operator[] (const int i){
    
    assert( (1 <= i) && (i <= 3) );
    
    double ans = 0;
    
    switch (i) {
        case 1:
            ans = this->x;
            break;
        case 2:
            ans = this->y;
            break;
        case 3:
            ans = this->z;
            break;
    }
    
    return ans;
}

const vector operator+ (const vector& v1, const vector& v2){
    
    vector ans = vector();
    ans.x = v1.x + v2.x;
    ans.y = v1.y + v2.y;
    ans.z = v1.z + v2.z;
    
    return ans;
    
}

const vector operator+ (const vector& v1, const double scalar){
    
    vector ans = vector();
    ans.x = v1.x + scalar;
    ans.y = v1.y + scalar;
    ans.z = v1.z + scalar;
    
    return ans;
    
}

const vector operator+ (const double scalar, const vector& v2){
    
    vector ans = vector();
    ans.x = scalar + v2.x;
    ans.y = scalar + v2.y;
    ans.z = scalar + v2.z;
    
    return ans;    
    
}

const vector operator- (const vector& v1, const vector& v2){
    
    vector ans = vector();
    ans.x = v1.x - v2.x;
    ans.y = v1.y - v2.y;
    ans.z = v1.z - v2.z;

    return ans;    
    
}

const vector operator- (const vector& v1, const double scalar){
    
    vector ans = vector();
    ans.x = v1.x - scalar;
    ans.y = v1.y - scalar;
    ans.z = v1.z - scalar;

    return ans;    
    
}

const vector operator- (const double scalar, const vector& v2){
    
    vector ans = vector();
    ans.x = scalar - v2.x;
    ans.y = scalar - v2.y;
    ans.z = scalar - v2.z;

    return ans;    
    
}

const vector operator* (const double scalar, const vector& v){
    
    vector ans = vector();
    ans.x = v.x * scalar;
    ans.y = v.y * scalar;
    ans.z = v.z * scalar;
    
    return ans;
    
}

const vector operator* (const vector& v, const double scalar){
    
    vector ans = vector();
    ans.x = v.x * scalar;
    ans.y = v.y * scalar;
    ans.z = v.z * scalar;
    
    return ans;
    
}


std::ostream& operator<< (std::ostream& os, const vector& v){
    
    return os << "[" << v.x << "]" << "\n"
              << "[" << v.y << "]" << "\n"            
              << "[" << v.z << "]" << "\n";            
}






// ==========================================================================================
// 
//                                      Tests
// 
// ==========================================================================================

class vector_test_case : public ::testing::Test {
    
    public:
        vector v1,v2,v3;
        double scalar;
    
        virtual void SetUp(){
            v1 = vector(5.5,6.5,7.5);
            v2 = vector(1.5,2.5,3.5);
            v3 = vector(9.5,5.5,4.5);
            
            scalar = 5.5;
        }
    
};


TEST_F(vector_test_case, plus){
    
    v1 = v1 + v2;
    
    EXPECT_DOUBLE_EQ(5.5 + 1.5, v1.x);
    EXPECT_DOUBLE_EQ(6.5 + 2.5, v1.y);
    EXPECT_DOUBLE_EQ(7.5 + 3.5, v1.z);
    
}

TEST_F(vector_test_case, lscalar_plus){
    
    v1 = 5 + v2;
    
    EXPECT_DOUBLE_EQ(5 + 1.5, v1.x);
    EXPECT_DOUBLE_EQ(5 + 2.5, v1.y);
    EXPECT_DOUBLE_EQ(5 + 3.5, v1.z);
    
}

TEST_F(vector_test_case, rscalar_plus){
    
    v1 = v1 + 5;
    
    EXPECT_DOUBLE_EQ(5.5 + 5, v1.x);
    EXPECT_DOUBLE_EQ(6.5 + 5, v1.y);
    EXPECT_DOUBLE_EQ(7.5 + 5, v1.z);
    
}

TEST_F(vector_test_case, minus){
    
    v1 = v1 - v2;
    
    EXPECT_DOUBLE_EQ(5.5 - 1.5, v1.x);
    EXPECT_DOUBLE_EQ(6.5 - 2.5, v1.y);
    EXPECT_DOUBLE_EQ(7.5 - 3.5, v1.z);
    
}

TEST_F(vector_test_case, rscalar_minus){
    
    v1 = v2 - 5;
    
    EXPECT_DOUBLE_EQ(1.5 - 5, v1.x);
    EXPECT_DOUBLE_EQ(2.5 - 5, v1.y);
    EXPECT_DOUBLE_EQ(3.5 - 5, v1.z);
    
}

TEST_F(vector_test_case, lscalar_minus){
    
    v1 = 5 - v2;
    
    EXPECT_DOUBLE_EQ(5 - 1.5, v1.x);
    EXPECT_DOUBLE_EQ(5 - 2.5, v1.y);
    EXPECT_DOUBLE_EQ(5 - 3.5, v1.z);
    
}

TEST_F(vector_test_case, unary_minus){
    
    v3 = -v1;
    
    EXPECT_DOUBLE_EQ(-5.5, v3.x);
    EXPECT_DOUBLE_EQ(-6.5, v3.y);
    EXPECT_DOUBLE_EQ(-7.5, v3.z);
    
}

TEST_F(vector_test_case, dot_product){
    
    double ans = v2*v3;
    
    double a = 1.5 * 9.5;
    double b = 2.5 * 5.5;
    double c = 3.5 * 4.5;
    
    EXPECT_DOUBLE_EQ(a + b + c, ans);
    
}

TEST_F(vector_test_case, lscalar_multiplication){
    
    v3 = scalar*v3;
    
    EXPECT_DOUBLE_EQ(9.5 * scalar, v3.x);
    EXPECT_DOUBLE_EQ(5.5 * scalar, v3.y);
    EXPECT_DOUBLE_EQ(4.5 * scalar, v3.z);
    
}

TEST_F(vector_test_case, rscalar_multiplication){
    
    v3 = v3*scalar;
    
    EXPECT_DOUBLE_EQ(9.5 * scalar, v3.x);
    EXPECT_DOUBLE_EQ(5.5 * scalar, v3.y);
    EXPECT_DOUBLE_EQ(4.5 * scalar, v3.z);
    
}

TEST_F(vector_test_case, scalar_division){
    
    v3 = v3/scalar;
    
    EXPECT_DOUBLE_EQ(9.5 / scalar, v3.x);
    EXPECT_DOUBLE_EQ(5.5 / scalar, v3.y);
    EXPECT_DOUBLE_EQ(4.5 / scalar, v3.z);
    
}

TEST_F(vector_test_case, assignment){
    
    v3 = v1 + v2;
    
    EXPECT_DOUBLE_EQ(5.5 + 1.5, v3.x);
    EXPECT_DOUBLE_EQ(6.5 + 2.5, v3.y);
    EXPECT_DOUBLE_EQ(7.5 + 3.5, v3.z);
    
}

TEST_F(vector_test_case, plus_assignment){
    
    v3 += v2;
    
    EXPECT_DOUBLE_EQ(9.5 + 1.5, v3.x);
    EXPECT_DOUBLE_EQ(5.5 + 2.5, v3.y);
    EXPECT_DOUBLE_EQ(4.5 + 3.5, v3.z);
    
}

TEST_F(vector_test_case, minus_assignment){
    
    v3 -= v2;
    
    EXPECT_DOUBLE_EQ(9.5 - 1.5, v3.x);
    EXPECT_DOUBLE_EQ(5.5 - 2.5, v3.y);
    EXPECT_DOUBLE_EQ(4.5 - 3.5, v3.z);
    
}

TEST_F(vector_test_case, multiplication_assignment){
    
    v1 *= 5;
    
    EXPECT_DOUBLE_EQ(5.5 * 5, v1.x);
    EXPECT_DOUBLE_EQ(6.5 * 5, v1.y);
    EXPECT_DOUBLE_EQ(7.5 * 5, v1.z);
    
}

TEST_F(vector_test_case, subscripting){
    
    EXPECT_DOUBLE_EQ(5.5, v1[1]);
    EXPECT_DOUBLE_EQ(6.5, v1[2]);
    EXPECT_DOUBLE_EQ(7.5, v1[3]);
}

TEST_F(vector_test_case, equality){
    
    EXPECT_TRUE(v1 == v1);
    
}

TEST_F(vector_test_case, inequality){
    
    EXPECT_TRUE(v1 != v2);
    
}

TEST_F(vector_test_case, increment){
    
    v2++;
    
    EXPECT_DOUBLE_EQ(2.5, v2.x);
    EXPECT_DOUBLE_EQ(3.5, v2.y);
    EXPECT_DOUBLE_EQ(4.5, v2.z);
    
}

TEST_F(vector_test_case, output){

    std::stringstream ss1;
    ss1 << v1;
    std::string str1 = ss1.str();
    
    std::stringstream ss2;
    ss2 << "[" << v1.x << "]" << "\n" 
        << "[" << v1.y << "]" << "\n"  
        << "[" << v1.z << "]" << "\n" ;
    std::string str2 = ss2.str();
    
    const char * cstr1 = str1.c_str();
    const char * cstr2 = str2.c_str();
    
    EXPECT_STREQ(cstr2, cstr1);
    
}
