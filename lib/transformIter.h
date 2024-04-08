#pragma once

template<class iterator, class condition>
class transform_iter {
public:
    using value_type = typename iterator::value_type;

    transform_iter(iterator cur, condition foo)
            : cur_(cur)
            , function_(foo) {
    }

    bool operator==(const transform_iter& other) {
        return cur_ == other.cur_;
    }

    auto operator*() {
        return function_(*cur_);
    }


    transform_iter& operator++() {
        ++cur_;
        return *this;
    }

private:
    iterator cur_;
    condition function_;
};


template<typename iterator, class condition>
class transformAdapter {
public:
    explicit transformAdapter(condition f, iterator begin, iterator end): begin_(begin), end_(end), function_(f) {}

    auto begin() const {
        return transform_iter<iterator, condition>(begin_, function_);
    }

    auto end() const {
        return transform_iter<iterator, condition>(end_, function_);
    }

private:
    condition function_;
    iterator begin_;
    iterator end_;
};
