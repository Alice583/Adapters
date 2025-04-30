#pragma once

template<class iterator, class condition>
class filter_iter {
public:
    using value_type = typename iterator::value_type;

    filter_iter(iterator cur, iterator begin, iterator end, condition foo): cur_(cur), begin_(begin), end_(end), condition_(foo) {}

    bool operator==(const filter_iter& other) {
        return cur_ == other.cur_;
    }

    value_type operator*() {
        return *cur_;
    }

    filter_iter& operator++() {
        ++cur_;
        while (!condition_(*cur_) && cur_ != end_) {
            ++cur_;
        }
        return *this;
    }

private:
    iterator cur_;
    iterator begin_;
    iterator end_;
    condition condition_;
};


template<typename iterator, class T>
class filterAdapter {
public:
    explicit filterAdapter(T f, iterator begin, iterator end) {
        function_ = f;
        begin_ = begin;
        end_ = end;

        while (!f(*begin_) && begin_ != end_) {
            ++begin_;
        }
    }

    auto begin() const {
        return filter_iter<iterator, T>(begin_, begin_, end_, function_);
    }

    auto end() const {
        return filter_iter<iterator, T>(end_, begin_, end_, function_);
    }

private:
    T function_;
    iterator begin_;
    iterator end_;
};
