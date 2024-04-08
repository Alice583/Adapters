#pragma once
#include "positionIter.h"
#include "requirements.h"

template<std::size_t idx>
class position {
public:
    position() {
        idx_ = idx;
    }

    size_t GetPos() const {
        return idx_;
    }

private:
    std::size_t idx_;
};

template<Associative container, std::size_t pos>
auto operator|(const container& c, const position<pos>&) {
    return positionIter<decltype(c.begin()), pos>(c.begin(), c.end());
}

