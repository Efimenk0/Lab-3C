
#import <XCTest/XCTest.h>
#import "TernaryVectorClass.h"

using namespace TernaryVectorClass;

@interface tests : XCTestCase

@end

@implementation tests


- (void)testEmptyConstructor {
    TernaryVectorClass::TernaryVector v;
    XCTAssertEqual(0, v.GetSize());
    XCTAssertEqual(nullptr, v.GetMasAdress());
}


- (void)testDefaultConstructor1 {
    TernaryVectorClass::TernaryVector v(10);
    XCTAssertEqual(10, v.GetSize());
        for (int i = 0; i < v.GetSize(); ++i)
    XCTAssertEqual('X', v.GetValue(i));
}


- (void)testDefaultConstructor2 {
    std::string str = "211wkd0a  rewjn2";
    TernaryVectorClass::TernaryVector v(str);
    XCTAssertEqual('X', v.GetValue(0));
    XCTAssertEqual('1', v.GetValue(1));
    XCTAssertEqual('1', v.GetValue(2));
    XCTAssertEqual('X', v.GetValue(3));
    XCTAssertEqual('X', v.GetValue(4));
    XCTAssertEqual('X', v.GetValue(5));
    XCTAssertEqual('0', v.GetValue(6));
    XCTAssertEqual('X', v.GetValue(7));
    TernaryVectorClass::TernaryVector v2("");
    XCTAssertEqual(0, v2.GetSize());
    XCTAssertEqual(nullptr, v2.GetMasAdress());
}


- (void)testCopyConstructor {
    TernaryVectorClass::TernaryVector v1("1X00X1010X");
    TernaryVectorClass::TernaryVector v2(v1);
    XCTAssertEqual(false, v1.GetMasAdress() == v2.GetMasAdress());
    XCTAssertEqual(10, v2.GetSize());
    XCTAssertEqual('1', v2.GetValue(0));
    XCTAssertEqual('X', v2.GetValue(1));
    XCTAssertEqual('0', v2.GetValue(2));
    XCTAssertEqual('0', v2.GetValue(3));
    XCTAssertEqual('X', v2.GetValue(4));
    XCTAssertEqual('1', v2.GetValue(5));
    XCTAssertEqual('0', v2.GetValue(6));
    XCTAssertEqual('1', v2.GetValue(7));
    XCTAssertEqual('0', v2.GetValue(8));
    XCTAssertEqual('X', v2.GetValue(9));
}


- (void)testCopyAssigment {
    TernaryVectorClass::TernaryVector v1("1X00X1010X");
        TernaryVectorClass::TernaryVector v2("100218");
        char* ptr = v2.GetMasAdress();
        v2 = v1;
    XCTAssertEqual(false, ptr == v2.GetMasAdress());
    XCTAssertEqual(false, ptr == v1.GetMasAdress());
    XCTAssertEqual(false, v1.GetMasAdress() == v2.GetMasAdress());
    XCTAssertEqual(v2.GetSize(), v1.GetSize());
    XCTAssertEqual('1', v2.GetValue(0));
    XCTAssertEqual('X', v2.GetValue(1));
    XCTAssertEqual('0', v2.GetValue(2));
    XCTAssertEqual('0', v2.GetValue(3));
    XCTAssertEqual('X', v2.GetValue(4));
    XCTAssertEqual('1', v2.GetValue(5));
    XCTAssertEqual('0', v2.GetValue(6));
    XCTAssertEqual('1', v2.GetValue(7));
    XCTAssertEqual('0', v2.GetValue(8));
    XCTAssertEqual('X', v2.GetValue(9));
}


- (void)tetsMoveConstructor {
    TernaryVectorClass::TernaryVector v1("1X00X1010X");
    char* ptr = v1.GetMasAdress();
    TernaryVectorClass::TernaryVector v2(std::move(v1));
    XCTAssertEqual(v2.GetMasAdress(), ptr);
    XCTAssertEqual(nullptr, v1.GetMasAdress());
    XCTAssertEqual(v2.GetSize(), v1.GetSize());
}


- (void)testMoveAssigment {
    TernaryVectorClass::TernaryVector v1("1X00X1010X");
    TernaryVectorClass::TernaryVector v2("100218");
    char* ptr_v1 = v1.GetMasAdress();
    char* ptr_v2 = v2.GetMasAdress();
    int num_v1 = v1.GetSize();
    int num_v2 = v2.GetSize();
    v2 = std::move(v1);
    XCTAssertEqual(v1.GetMasAdress(), ptr_v2);
    XCTAssertEqual(v2.GetMasAdress(), ptr_v1);
    XCTAssertEqual(v1.GetSize(), num_v2);
    XCTAssertEqual(v2.GetSize(), num_v1);
    XCTAssertEqual('1', v2.GetValue(0));
    XCTAssertEqual('X', v2.GetValue(1));
    XCTAssertEqual('0', v2.GetValue(2));
    XCTAssertEqual('0', v2.GetValue(3));
    XCTAssertEqual('X', v2.GetValue(4));
    XCTAssertEqual('1', v2.GetValue(5));
    XCTAssertEqual('0', v2.GetValue(6));
    XCTAssertEqual('1', v2.GetValue(7));
    XCTAssertEqual('0', v2.GetValue(8));
    XCTAssertEqual('X', v2.GetValue(9));
}


- (void)testDisjunction {
    // 1. Если первый вектор меньше по размеру
    TernaryVectorClass::TernaryVector v1("01X");
    TernaryVectorClass::TernaryVector v2("000111XXX");
    TernaryVectorClass::TernaryVector v3 = v1 | v2;
    XCTAssertEqual(v2.GetSize(), v3.GetSize());
    XCTAssertEqual('0', v3.GetValue(0));
    XCTAssertEqual('X', v3.GetValue(2));
    XCTAssertEqual('1', v3.GetValue(3));
    XCTAssertEqual('1', v3.GetValue(4));
    XCTAssertEqual('1', v3.GetValue(5));
    XCTAssertEqual('X', v3.GetValue(6));
    XCTAssertEqual('X', v3.GetValue(7));
    XCTAssertEqual('X', v3.GetValue(8));
    // 2. Если первый вектор больше по размеру
    v1 = (std::string)"01X01X01X";
    v2 = (std::string)"110";
    v3 = v1 | v2;
    XCTAssertEqual(v1.GetSize(), v3.GetSize());
    XCTAssertEqual('1', v3.GetValue(0));
    XCTAssertEqual('1', v3.GetValue(1));
    XCTAssertEqual('X', v3.GetValue(2));
    XCTAssertEqual('X', v3.GetValue(3));
    XCTAssertEqual('1', v3.GetValue(4));
    XCTAssertEqual('X', v3.GetValue(5));
    XCTAssertEqual('X', v3.GetValue(6));
    XCTAssertEqual('1', v3.GetValue(7));
    XCTAssertEqual('X', v3.GetValue(8));
    // 3. Если вектора равных размеров
    v1 = (std::string)"01X01X01X";
    v2 = (std::string)"000111XXX";
    v3 = v1 | v2;
    XCTAssertEqual(v1.GetSize(), v3.GetSize());
    XCTAssertEqual('0', v3.GetValue(0));
    XCTAssertEqual('1', v3.GetValue(1));
    XCTAssertEqual('X', v3.GetValue(2));
    XCTAssertEqual('1', v3.GetValue(3));
    XCTAssertEqual('1', v3.GetValue(4));
    XCTAssertEqual('1', v3.GetValue(5));
    XCTAssertEqual('X', v3.GetValue(6));
    XCTAssertEqual('1', v3.GetValue(7));
    XCTAssertEqual('X', v3.GetValue(8));
}


- (void)testConjunction {
    //1. Если выбранный вектор меньше по размеру
    TernaryVectorClass::TernaryVector v1("01X");
    TernaryVectorClass::TernaryVector v2("010111XXX");
    v1 &= v2;
    XCTAssertEqual(v2.GetSize(), v1.GetSize());
    XCTAssertEqual('0', v1.GetValue(0));
    XCTAssertEqual('1', v1.GetValue(1));
    XCTAssertEqual('0', v1.GetValue(2));
    XCTAssertEqual('X', v1.GetValue(3));
    XCTAssertEqual('X', v1.GetValue(4));
    XCTAssertEqual('X', v1.GetValue(5));
    XCTAssertEqual('X', v1.GetValue(6));
    XCTAssertEqual('X', v1.GetValue(7));
    XCTAssertEqual('X', v1.GetValue(8));
    // 2. Если выбранный вектор больше по размеру
    v1 = (std::string)"01X01X01X";
    int sz = v1.GetSize();
    v2 = (std::string)"111";
    v1 &= v2;
    XCTAssertEqual(sz, v1.GetSize());
    XCTAssertEqual('0', v1.GetValue(0));
    XCTAssertEqual('1', v1.GetValue(1));
    XCTAssertEqual('X', v1.GetValue(2));
    XCTAssertEqual('0', v1.GetValue(3));
    XCTAssertEqual('X', v1.GetValue(4));
    XCTAssertEqual('X', v1.GetValue(5));
    XCTAssertEqual('0', v1.GetValue(6));
    XCTAssertEqual('X', v1.GetValue(7));
    XCTAssertEqual('X', v1.GetValue(8));
    // 3. Если выбранный вектор равен по размеру
    v1 = (std::string)"01X01X01X";
    v2 = (std::string)"000111XXX";
    v1 &= v2;
    XCTAssertEqual(v2.GetSize(), v1.GetSize());
    XCTAssertEqual('0', v1.GetValue(0));
    XCTAssertEqual('0', v1.GetValue(1));
    XCTAssertEqual('0', v1.GetValue(2));
    XCTAssertEqual('0', v1.GetValue(3));
    XCTAssertEqual('1', v1.GetValue(4));
    XCTAssertEqual('X', v1.GetValue(5));
    XCTAssertEqual('0', v1.GetValue(6));
    XCTAssertEqual('X', v1.GetValue(7));
    XCTAssertEqual('X', v1.GetValue(8));
}


- (void)testInvertion {
    TernaryVectorClass::TernaryVector v("000111XX");
    TernaryVectorClass::TernaryVector  res = ~v;
    XCTAssertEqual('1', res.GetValue(0));
    XCTAssertEqual('1', res.GetValue(1));
    XCTAssertEqual('1', res.GetValue(2));
    XCTAssertEqual('0', res.GetValue(3));
    XCTAssertEqual('0', res.GetValue(4));
    XCTAssertEqual('0', res.GetValue(5));
    XCTAssertEqual('X', res.GetValue(6));
    XCTAssertEqual('X', res.GetValue(7));
}


- (void)testCompare {
    // 1. Если вектор 1 меньше вектора 2
    TernaryVectorClass::TernaryVector v1("0001");
    TernaryVectorClass::TernaryVector v2("01X01X01");
    XCTAssertEqual(false, v1 == v2);
    XCTAssertEqual(-1, TernaryVectorClass::Compare(v1, v2));
    XCTAssertEqual(true, v1 == (std::string)"0001");
    // 2. Если вектор 1 больше вектора 2
    v1 = (std::string)"01101XX01";
    v2 = (std::string)"01X";
    XCTAssertEqual(false, v1 == v2);
    XCTAssertEqual(-1, TernaryVectorClass::Compare(v1, v2));
    // 3. Если вектора совпадают
    v2 = v1;
    XCTAssertEqual(true, v1 == v2);
    v2 = (std::string)"01101XX00";
    XCTAssertEqual(8, TernaryVectorClass::Compare(v1, v2));
}


- (void)testAnalysis {
    TernaryVectorClass::TernaryVector v1("000111XX");
    TernaryVectorClass::TernaryVector v2("011010010");
    TernaryVectorClass::TernaryVector v3("");
    XCTAssertEqual(6, v1.Analysis());
    XCTAssertEqual(-1, v2.Analysis());
    XCTAssertEqual(-1, v3.Analysis());
}

@end
