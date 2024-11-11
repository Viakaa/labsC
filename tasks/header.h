#ifndef ARRAY_MACROS_H
#define ARRAY_MACROS_H
using namespace std;
#include <iostream>

#define INPUT_ARRAY(arr, n)         \
   for (int i = 0; i < n; ++i) {  \
       cout << "Enter element " << i + 1 << ": "; \
       cin >> arr[i];         \
   }

#define OUTPUT_ARRAY(arr, n)        \
   cout << "Array elements: "; \
   for (int i = 0; i < n; ++i) {   \
       cout << arr[i] << " ";  \
   }                                 \
   cout << endl;

#define PRODUCT_OF_EVEN_INDEX(arr, n)       \
   int product = 1;                         \
   for (int i = 0; i < n; i += 2) {        \
       product *= arr[i];                   \
   }

#define SUM_BETWEEN_ZEROES(arr, n, sum)       \
   sum = 0;                                   \
   int first_zero_index = -1;                 \
   int last_zero_index = -1;                  \
   for (int i = 0; i < n; ++i) {              \
       if (arr[i] == 0) {                     \
           if (first_zero_index == -1) {     \
               first_zero_index = i;          \
           }                                   \
           last_zero_index = i;               \
       }                                       \
   }                                           \
   if (first_zero_index != -1 && last_zero_index != -1 && first_zero_index != last_zero_index) { \
       for (int i = first_zero_index + 1; i < last_zero_index; ++i) { \
           sum += arr[i];                     \
       }                                       \
   }

#define REARRANGE_ARRAY(arr, n)         \
   int positiveIndex = 0;              \
   for (int i = 0; i < n; ++i) {       \
       if (arr[i] >= 0) {               \
          swap(arr[i], arr[positiveIndex]); \
           positiveIndex++;              \
       }                                  \
   }

#endif
