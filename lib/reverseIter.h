#pragma once
#include <iostream>

template<typename iterator>
class reverseAdapter {
public:
    explicit reverseAdapter(iterator begin, iterator end): begin_(begin), end_(end) {}

    auto begin() const {
        return std::reverse_iterator<iterator>(end_);
    }

    auto end() const {
        return std::reverse_iterator<iterator>(begin_);
    }

private:
    iterator begin_;
    iterator end_;
};
