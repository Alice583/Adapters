#pragma once
#include <iostream>

template<typename iterator>
class takeAdapter {
public:
    explicit takeAdapter(size_t n, iterator begin, iterator end): n_(n), begin_(begin), end_(end) {
        iterator at = begin_;
        for (int i = 0; i < n; ++i) {
            ++at;
            if (at == end_) {
                break;
            }
        }
        end_ = at;
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
