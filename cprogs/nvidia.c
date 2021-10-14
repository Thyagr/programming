#include <stdio.h>

#define EVAL(x) (((x) > 0) ? 1: ((x)==0) ? 0 : -1)

int main(void)
{
    int i;
    int k = 0;
    for (k = -5 ; k < 3; k++)
        printf("\n %d EVAL() = %d", i, EVAL(i++));
    for (int j=0; j<5; j++)
        printf("%d %d\n", k++, ++k); //order of evaluation is undefined? no
    /*
    printf - pushed into stack left to right
    evaluated and printed - so right to left
    */

    printf("\nEVAL -5: %d", EVAL(-5));
    printf("\nEVAL 5: %d", EVAL(5));
    printf("\nEVAL 0: %d", EVAL(0));
    return 0;
}

/*
1. memcopy implementation
use int* instead of char* so larger chunks copied, optimize for non-divisible chunks
max efficiency = machine cycle theoretical calc
2. compare and swap for addition cmp(int* v, int exp, int addnum) multi threaded
3. add 2 64 bit unsigned integers
4. input strings, can we construct one string from another?
5a. find intersection, union
sort, find shortest and then do operations
5b. color fill problem
hint: detect boundary if color is different, do recursively
*/


/* Soln 2
Compare and swap function
old_reg_val is always returned, but it can be tested following the compare_and_swap operation
to see if it matches oldval, as it may be different, meaning that another process has managed
to succeed in a competing compare_and_swap to change the reg value from oldval
*/
int compare_and_swap(int* reg, int oldval, int newval)
{
  // ATOMIC(); must be atomic lock
  int old_reg_val = *reg;
  if (old_reg_val == oldval)
     *reg = newval;
  // END_ATOMIC(); // release lock
  return old_reg_val;
}
/*
//Similar idea for addition, basically do-while compare and swap

Example1
The solution is to atomically snapshot the current value, and then use atomic<T>::compare_and_swap to update it.
Retry until the compare_and_swap succeeds. In some cases it may be possible to exit before the compare_and_swap
succeeds because the current value meets some condition.

The template below does the update x=f(x) atomically.
// Atomically perform x=f(x).
template<typename F, typename T>
void AtomicUpdate( atomic<T>& x, F f ) {
   int o;
   do {
       // Take a snapshot
       o = x;
       // Attempt to install new value computed from snapshot
   } while( x.compare_and_swap(f(o),o)!=o );
}

Example2
uint32_t atomicDecrementOrHalveWithLimit(std::atomic<uint32_t>& shared)
{
    uint32_t oldValue = shared.load();
    uint32_t newValue;
    do
    {
        if (oldValue % 2 == 1)
            newValue = oldValue - 1;
        else
            newValue = oldValue / 2;
        if (newValue < 10)
            break;
    }
    while (!shared.compare_exchange_weak(oldValue, newValue));
    return oldValue;
}
It’s the same idea as before: If compare_exchange_weak fails – usually due to a modification performed
by another thread – oldValue is updated with a more recent value, and the loop tries again.
*/
