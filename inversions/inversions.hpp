//
// Created by Matt Perry on 10/7/2020.
// stableMerge and mergeSort taken from Dr. Chappell's Stable Merge Sort example,
// added functionality of counting inversions. cleaned up using statements to better align with hpp files.
//

#ifndef INVERSIONS_HPP
#define INVERSIONS_HPP
#include <cstddef>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename FDIter>
std::size_t stableMerge(FDIter first, FDIter middle, FDIter last)
{
    std::size_t inversions = 0;
    std::vector<typename std::iterator_traits<FDIter>::value_type> buffer(std::distance(first, last));
    // Buffer for temporary copy of data
    auto in1 = first;         // Read location in 1st half
    auto in2 = middle;        // Read location in 2nd half
    auto out = buffer.begin();  // Write location in buffer
    // ** auto! That *is* better than vector<Value>::iterator

    // Merge two sorted lists into a single list in buff.
    while (in1 != middle && in2 != last)
    {
        if (*in2 < *in1){// Must do comparison this way, to be stable.
            *out++ = *in2++;
            inversions += std::distance(in1, middle);
        }
        else
            *out++ = *in1++;
    }

    // Copy remainder of original sequence to buffer.
    // Only one of the following two copy calls will do anything, since
    //  the other is given an empty source range.
    std::copy(in1, middle, out);
    std::copy(in2, last, out);

    // Copy buffer contents back to original sequence location.
    std::copy(buffer.begin(), buffer.end(), first);
    return inversions;
}

template <typename FDIter>
std::size_t mergeSort(FDIter first, FDIter last)
{
    std::size_t inversions = 0;
    // Compute size of sequence
    std::size_t size = std::distance(first, last);

    // BASE CASE
    if (size <= 1)
        return 0;

    // RECURSIVE CASE
    auto middle = std::next(first, size/2u);
    // Recursively sort the two lists
    inversions += mergeSort(first, middle);
    inversions += mergeSort(middle, last);

    // And merge them
    inversions += stableMerge(first, middle, last);
    return inversions;
}

template<typename RAIter>
std::size_t inversions(RAIter first, RAIter last){
    return (std::distance(first, last) < 1) ? 0 : mergeSort(first,last);
}

#endif //INVERSIONS_HPP
