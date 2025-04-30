#pragma once
#include "dropIter.h"
#include "requirements.h"

class drop {
public:
    explicit drop(const size_t& size): n_(size) {}

    size_t GetInpValue() const {
        return n_;
    }

private:
    const size_t n_;
};

template<Iterable container>
auto operator|(const container& c, const drop& drop_wrap) {
    return dropAdapter(drop_wrap.GetInpValue(), c.begin(), c.end());
}

