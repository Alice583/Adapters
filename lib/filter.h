#pragma once
#include "requirements.h"
#include "filterIter.h"


template<class T>
class filter {
public:
    explicit filter(const T& func): filter_func_(func) {}

    auto GetCondition() const {
        return filter_func_;
    }

private:
    T filter_func_;
};

template<Iterable container, class condition>
auto operator |(const container& c, const filter<condition>& filter_wrap) {
    return filterAdapter(filter_wrap.GetCondition(), c.begin(), c.end());
}

