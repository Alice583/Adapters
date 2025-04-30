#pragma once
#include <iostream>

template<typename iterator>
class dropAdapter {
public:
    explicit dropAdapter(size_t n, iterator begin, iterator end): n_(n), begin_(begin), end_(end) {
        iterator at = begin_;
        for (int i = 0; i < n_; ++i) {
            ++at;
            if (at == end_) {
                break;
            }
        }
        begin_ = at;
    }

    auto begin() const {
        return begin_;
    }

    auto end() const {
        return end_;
    }

private:
    size_t n_;
    iterator begin_;
    iterator end_;
};
