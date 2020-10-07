//
// Created by Matt Perry on 10/6/2020.
//

#ifndef CONTIGSUM_HPP
#define CONTIGSUM_HPP
#include <iterator>
#include <algorithm>
#include <numeric>

struct GCS_Values
{
    int GreatestContigSum, GreatestPossibleSumFirst, GreatestPossibleSumLast, SumOverAll;
};

template<typename RAIter>
GCS_Values contig_worker(RAIter first, RAIter last, std::size_t size){
    if(size < 2) return GCS_Values{*first, *first, *first , *first};
    else {
        auto mid = std::next(first, size/2u);
        auto left = contig_worker(first, mid, std::distance(first, mid));
        auto right = contig_worker(mid, last, std::distance(mid, last));
        return GCS_Values{
                std::max(left.GreatestContigSum,
                         std::max(right.GreatestContigSum,
                                  (left.GreatestPossibleSumLast + right.GreatestPossibleSumFirst))),
                std::max(left.GreatestPossibleSumFirst, (left.SumOverAll + right.GreatestPossibleSumFirst)),
                std::max(right.GreatestPossibleSumLast, (left.GreatestPossibleSumLast + right.SumOverAll)),
                left.SumOverAll + right.SumOverAll
        };
    }
}

template<typename RAIter>
int contigSum(RAIter first, RAIter last){
    std::size_t size = std::distance(first, last);
    return (size < 1) ? 0 : std::max(contig_worker(first, last, size).GreatestContigSum, 0);
}

#endif //CONTIGSUM_HPP