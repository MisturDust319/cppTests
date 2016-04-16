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
    //a virtual function to demonstrate using virtual functions
    virtual void aFunc(int anInt) {
        cout << "In the base" << endl
            << "String: " << anInt << endl;
    }
};

class Derived : public Base {
public:
    //an override of the base class's virtual function
    void aFunc(int anInt) {
        cout << "In the derived class" << endl
        << "String: " << anInt << endl;
    }
};

class DerivedExtra : public Base {
public:
    //another override of the base class's virtual function
    void aFunc(int anInt) {
        cout << "In the derived w/ extras class" << endl
        << "String: " << anInt << endl;
    }
    
    //an extra function not in the base class meant to show
    // a base class pointer can't access functions not defined
    // in the base class
    void anotherFunc() {
        cout << "This function can't be accessed by a base class pointer"
        << endl;
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
    
    cout << "Creating & running a derived class w/ functions not in the base class" << endl;
    DerivedExtra derivedClassExtra;
    basePointer = &derivedClassExtra;
    /* this won't work, as baseClass doesn't have an equivalent function
    basePointer->anotherFunc();
    */
    cout << "The base pointer cannot access functions not defined in some form in it" << endl;
    
    cout << "Accessing added in extended class functions w/ the extended class itself" << endl;
    //using the extended class to access extra functions
    derivedClassExtra.anotherFunc();
    
    return 0;
}