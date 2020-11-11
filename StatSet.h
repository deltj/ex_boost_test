#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <set>

/**
 * A class that calculates some simple statistics about a set of samples.
 *
 * This class is meant to be used as an example for unit testing, and isn't 
 * intended to be complete or correct for all cases.
 */
template <typename T>
class StatSet : public std::multiset<T> {
public:

    /**
     * Add the specified sample to the set
     *
     * @param sample The sample to add
     */
    void addSample(const T &sample)
    {
        std::multiset<T>::insert(sample);
    };

    /**
     * Compute the arithmetic mean of samples in the set
     *
     * @see https://en.wikipedia.org/wiki/Arithmetic_mean
     *
     * @throws runtime_error of the set is empty
     * @returns The arithmetic mean of samples in the set
     */
    T getArithmeticMean() const
    {
        const typename std::multiset<T>::size_type n = std::multiset<T>::size();

        if(n == 0)
        {
            throw std::runtime_error("empty set");
        }

        T mean = 0;
        for(typename std::multiset<T>::const_iterator it=std::multiset<T>::begin();
            it!=std::multiset<T>::end(); ++it)
        {
            mean += *it / n;
        }

        return mean;
    }

    /**
     * Find the median value in the set
     *
     * @see https://en.wikipedia.org/wiki/Median
     *
     * @throws runtime_error of the set is empty
     * @returns The median value in the set
     */
    double getMedian() const
    {
        const typename std::multiset<T>::size_type n = std::multiset<T>::size();
        const typename std::multiset<T>::size_type midpoint = n / 2;

        if(n == 0)
        {
            throw std::runtime_error("empty set");
        }

        double median;
        typename std::multiset<T>::const_iterator it=std::multiset<T>::begin();
        if(n % 2 == 0)
        {
            //  even number of elements, average the middle two
            std::advance(it, midpoint - 1);
            double element_m = *it;

            std::advance(it, 1);
            double element_n = *it;

            median = (element_m + element_n) / 2;
        }
        else
        {
            //  odd number of elements, use the midpoint
            std::advance(it, midpoint);

            median = *it;
        }

        return median;
    }

    /**
     * Find the mode of the samples in the set
     *
     * @see https://en.wikipedia.org/wiki/Mode_(statistics)
     *
     * @throws runtime_error of the set is empty
     * @returns The mode of the set
     */
    T getMode() const
    {
        const typename std::multiset<T>::size_type n = std::multiset<T>::size();

        if(n == 0)
        {
            throw std::runtime_error("empty set");
        }

        T mode = *(std::multiset<T>::begin());
        for(typename std::multiset<T>::const_iterator it=std::multiset<T>::begin();
            it!=std::multiset<T>::end(); ++it)
        {
            if(std::multiset<T>::count(*it) > std::multiset<T>::count(mode))
            {
                mode = *it;
            }
        }

        return mode;
    }
};
