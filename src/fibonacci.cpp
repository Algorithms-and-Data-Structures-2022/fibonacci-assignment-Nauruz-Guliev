#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    return static_cast<int64_t>(round(pow((1 + sqrt(5)) / 2, n) / sqrt(5)));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;
    for (int i = 0; i<= n; i++) {
      fib_prev += fib_curr;
      fib_curr = fib_prev - fib_curr;
    }
    return fib_curr;
  }

  int64_t fib_recursive(int n) {

    // Напишите здесь свой код ...
      if (n<=1) {
        return n;
      } else {
        return fib_recursive(n-1) + fib_recursive(n-2);
      }
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      cache[n] = fib_recursive_memoization(n-1,cache) + fib_recursive_memoization(n-2, cache);
    }
    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    // Напишите здесь свой код ...

    // Tip: используйте реализованную функцию matrix_pow

    Matrix2x2 mtrx = {{{1,1}, {0,0}}};
    Matrix2x2 res = matrix_multiply(mtrx,matrix_power(mtrx, n-1));
    return res[0][0];
  }

}  // namespace assignment
