#include <iostream>

template<typename iterator, size_t idx>
class position_iter {
public:
    using value_type = typename iterator::value_type;

    explicit position_iter(iterator at): at_(at), idx_(idx) {}

    bool operator==(const position_iter& other) const {
        return at_ == other.at_;
    }

    auto operator*() {
        return std::get<idx>(*at_);
    }

    position_iter& operator++() {
        ++at_;
        return *this;
    }

private:
    iterator at_;
    size_t idx_;
};



template<typename iterator, size_t pos>
class positionIter {
public:
    positionIter(iterator b, iterator e)
            : begin_(b)
            , end_(e)
            , pos_(pos) {
    }

    auto begin() const {
        return position_iter<iterator, pos>(begin_);
    }

    auto end() const {
        return position_iter<iterator, pos>(end_);
    }

private:
    iterator begin_;
    iterator end_;
    std::size_t pos_;
};
