#pragma once

#include "requirements.h"

template<class T>
class transform {
public:
    explicit transform(const T& f) : filter_func_(f) {}

    auto GetFunc() const {
        return filter_func_;
    }

private:
    T filter_func_;
};

template<Iterable container, class condition>
auto operator |(const container& c, const transform<condition>& transform_wrap) {
    return transform_view(transform_wrap.GetFunc(), c.begin(), c.end());
}