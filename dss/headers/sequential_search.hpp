template <typename T, typename N>
const N findTermIndex(const T bucket[], const T term[], const N bucketlen,
    const N termlen);
/*
    findTermIndex() searches for a term which is termlen elements long which resides
    within a larger sequence of elements called bucket() which is bucketlen elements
    long, then returns an index to where the term resides.
    If the term was not found, -1 is returned.
    
    Example:
    #include <iostream>
    #include "findTermIndex.hpp"
    int main()
    {
        char array[1024];
        array[1022] = 'M';
        array[1023] = 'M';
        
        auto n = findTermIndex(array, "MM", 1024, 2);
        
        std::cout << "The sequence MM resides at index: " << n << std::endl;
        // The sequence MM resides at index: 1022
    }
*/

template <typename T, typename N>
const T* findTermAddress(const T bucket[], const T term[], const N bucketlen,
    const N termlen);
/*
    findTermAddress() is the same as findTermIndex, except it
    returns the address to the found term, instead of the index.
    
    returns nullptr if the term was not found.
*/