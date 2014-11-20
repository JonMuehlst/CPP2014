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

vector vector::operator+ (const vector& v){
    
    vector ans = vector();
    ans.x = this->x + v.x;
    ans.y = this->y + v.y;
    ans.z = this->z + v.z;
    
    return ans;
    
}

vector vector::operator- (const vector& v){
    
    vector ans = vector();
    ans.x = this->x - v.x;
    ans.y = this->y - v.y;
    ans.z = this->z - v.z;

    return ans;    
    
}

double vector::operator* (const vector& v){
    
    double a = this->x*v.x;
    double b = this->y*v.y;
    double c = this->z*v.z;
    
    return a + b + c;
    
}

vector vector::operator* (const double scalar){
    
    vector ans = vector();
    ans.x = this->x * scalar;
    ans.y = this->y * scalar;
    ans.z = this->z * scalar;
    
    return ans;
    
}

vector vector::operator/ (const double scalar){
    
    vector ans = vector();
    ans.x = this->x / scalar;
    ans.y = this->y / scalar;
    ans.z = this->z / scalar;
    
    return ans;    
    
}

void vector::operator= (const vector& v){
    
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    
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

vector vector::operator++ (int i = 1){
    
    this->x += 1;
    this->y += 1;
    this->z += 1;
    
    return *this;
    
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

TEST_F(vector_test_case, minus){
    
    v1 = v1 - v2;
    
    EXPECT_DOUBLE_EQ(5.5 - 1.5, v1.x);
    EXPECT_DOUBLE_EQ(6.5 - 2.5, v1.y);
    EXPECT_DOUBLE_EQ(7.5 - 3.5, v1.z);
    
}

TEST_F(vector_test_case, dot_product){
    
    double ans = v2*v3;
    
    double a = 1.5 * 9.5;
    double b = 2.5 * 5.5;
    double c = 3.5 * 4.5;
    
    EXPECT_DOUBLE_EQ(a + b + c, ans);
    
}

TEST_F(vector_test_case, scalar_multiplication){
    
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

TEST_F(vector_test_case, subscripting){
    
    EXPECT_DOUBLE_EQ(5.5, v1[1]);
    EXPECT_DOUBLE_EQ(6.5, v1[2]);
    EXPECT_DOUBLE_EQ(7.5, v1[3]);
}

TEST_F(vector_test_case, equality){
    
    EXPECT_TRUE(v1 == v1);
    
}

TEST_F(vector_test_case, increment){
    
    v2++;
    
    EXPECT_DOUBLE_EQ(2.5, v2.x);
    EXPECT_DOUBLE_EQ(3.5, v2.y);
    EXPECT_DOUBLE_EQ(4.5, v2.z);
    
}

