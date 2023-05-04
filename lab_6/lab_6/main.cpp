//
//  main.cpp
//  lab_6
//
//  Created by Антон Прохоров on 04/05/2023.
//

#include <iostream>

template<typename InputIterator, typename Predicate>
bool all_of(InputIterator first, InputIterator last, Predicate pred){
    return std::all_of(first, last, pred);
}

template<typename InputIterator, typename Predicate>
bool one_of(InputIterator first, InputIterator last, Predicate pred){
    int count = 0;
    for (; first != last; ++first) {
        if (pred(*first)) {
            ++count;
            if (count > 1) return false;
        }
    }
    return count == 1;
}

template<typename InputIterator, typename T>
InputIterator find_not(InputIterator first, InputIterator last, const T& val){
    return std::find_if_not(first, last, [&val](const T& element){ return element == val; });
}
