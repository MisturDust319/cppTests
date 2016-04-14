//
//  virtualFunctions.cpp
//  tests
//
//  Created by Stan Slupecki on 4/13/16.
//  Copyright © 2016 Stan Slupecki. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Base {
public:
    virtual void aFunc(int anInt) {
        cout << "In the base" << endl
            << "String: " << anInt << endl;
    }
};

class Derived : public Base {
public:
    void aFunc(int anInt) {
        cout << "In the derived class" << endl
        << "String: " << anInt << endl;
    }
};

int main() {
    //create base class
    Base baseClass;
    
    cout << "running base class virtual function" << endl;
    //run base class's virtual method
    baseClass.aFunc(5);
    
    //create derived class
    Derived derivedClass;
    cout << "Running derived class virtual function" << endl;
    derivedClass.aFunc(10);
    
    //create a pointer to the base class
    Base* basePointer;
    
    //point base class pointer to base class
    basePointer = &baseClass;
    
    cout << "Running base class virtual function from base class pointer" << endl;
    //run base class virtual function from a base class pointer
    basePointer->aFunc(15);
    
    //point base class pointer to derived class
    basePointer = &derivedClass;
    
    cout << "Running derived class virtual function from base class pointer" << endl;
    //run derived class virtual function from a base class pointer
    basePointer->aFunc(20);
    
    return 0;
}