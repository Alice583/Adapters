#pragma once
#include "requirements.h"
#include "takeIter.h"

class take {
public:
    explicit take(const size_t& size) :n_(size) {}

    size_t GetIntoValue() const {
        return n_;
    }

private:
    const size_t n_;
};

template<Iterable container>
auto operator|(const container& c, const take& take_wrap) {
    return takeAdapter(take_wrap.GetIntoValue(), c.begin(), c.end());
}

