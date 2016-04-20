//
//  templateClass.cpp
//  tests
//
//  Created by Stan Slupecki on 4/19/16.
//  Copyright © 2016 Stan Slupecki. All rights reserved.
//

#include <iostream>

using namespace std;

//DataType is just a placeholder for the type of data
// the template is made with
// often it is something like T or Ttype
const int SIZE = 100;

template <class DataType> class queue {
public:
    queue() { sloc = rloc = 0; }
    void qput(DataType i);
    DataType qget();
    
private:
    DataType q[SIZE];
    int sloc, rloc;
};

//put an object into the queue
//note how you treat the definition like a normal function
//  the only difference is the addition of a generic data, and
//  and the definition of the generic type w/ a template before the
//  function definition
template <class DataType> void queue<DataType>::qput(DataType i){
    if(sloc == SIZE) {
        cout << "Queue is full";
    }
    
    sloc++;
    q[sloc] = i;
}

template <class DataType> DataType queue<DataType>::qget() {
    if ( rloc == sloc ) {
        cout << "Queue Underflow";
        return 0;
    }
    rloc++;
    return q[rloc];
}
