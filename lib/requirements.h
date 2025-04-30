#pragma once

template<typename T>
concept Iterable = requires(T x)
{ x.begin(), x.end(); };


template<typename T>
concept Associative = Iterable<T> && requires(T x)
{ typename T::key_type; };