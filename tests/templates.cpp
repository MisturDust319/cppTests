//
//  templates.cpp
//  tests
//
//  Created by Stan Slupecki on 4/17/16.
//  Copyright © 2016 Stan Slupecki. All rights reserved.
//

#include <iostream>

using namespace std;

namespace TemplatesTest {
    //the template portion must immediately precede the function declaration
    //  tho you can exclude whitespace
    template <class dataType> void swap( dataType& x, dataType& y) {
        dataType temp;
        
        temp = x;
        x = y;
        y = temp;
    }
    
    //this explicitly creates an int overload of swap
    //rather than hoping the compiler makes one
    void swap(int& x, int& y) {
        cout << "Explicit int version of swap!" << endl;
        int temp;
        
        temp = x;
        x = y;
        y = temp;
    }
    
    //a template w/ more than one generic data type
    template <class a, class b> void multipleGenericTypes( a x, b y ) {
        cout << "Using multiple generic data types" << endl <<
        "x val: " << x << " y val: " << y << endl;
    }

}

int main() {
    
    //test multiple data types w/ swap function
    //start w/ ints
    int x = 10, y = 0;
    
    //display starting vals
    cout << "Int swap" << endl
    << "x: " << x << " y: " << y << endl
    << "swapping data" << endl;
    //try swapData w/ ints
    TemplatesTest::swap(x, y);
    //display results
    cout << "Result" << endl
    << "x: " << x << " y: " << y << endl;
    
    //next try floats
    float c = 20.1f, d = 30.4f;
    
    //display starting vals
    cout << "Float swap" << endl
    << "c: " << c << " d: " << d << endl
    << "swapping data" << endl;
    //swap floats
    TemplatesTest::swap(c, d);
    //display results
    cout << "Result" << endl
    << "c: " << c << " d: " << d << endl;
    
    /*
     The template function doesn't automatically
     handle type conversions, so this does not work:
    //display starting vals
    cout << "Float swap" << endl
    << "c: " << c << " x: " << x << endl
    << "swapping data" << endl;
    //swap floats
    TemplatesTest::swap(c, x);
    //display results
    cout << "Result" << endl
    << "c: " << c << " x: " << x << endl;
     */
    
    //test w/ multiple generic data types
    TemplatesTest::multipleGenericTypes(c, x);
    
    return 0;
}