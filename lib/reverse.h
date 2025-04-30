#pragma once
#include "requirements.h"
#include "reverseIter.h"


class reverse {};

template<Iterable container>
auto operator|(const container& c, const reverse&) {
    return reverseAdapter(c.begin(), c.end());
}
