#include <stdio.h>

int iterative_sum(int n);
int recursive_sum(int n);

/**
 * We have a problem where we want to sum up numbers 
 * between 1 and `n` up (inclusive).
 * 
 * Example:
 *     n = 3
 *     sum(3) = 0 + 1 + 2 + 3
 *            = 6
 * 
 *     n = 5
 *     sum(5) = 0 + 1 + 2 + 3 + 4 + 5 
 *            = 15
 * 
 * Iterative solutions to problems use iteration i.e. a loop looping multiple 
 * times until a condition is met to help produce their results.
 * 
 * Recursive solutions to problems use recursion i.e. a function calling itself
 * multiple times until a "base case" is reached to help produce their results.
 * 
 * All solutions to problems can be solved iteratively and recursively.
 */
int main(int argc, char *argv[]) {
        int n;
        printf("Enter a number: ");
        scanf("%d", &n);

        int iterative_result = iterative_sum(n);
        int recursive_result = recursive_sum(n);
        printf("Sum of all numbers up to %d using:", n);
        printf("\tIteration: %d\n", iterative_result);
        printf("\tRecursion: %d\n", recursive_result);

        return 0;
}

/**
 * When iteratively solving the problem, we start at 0 and iterate towards
 * `n` via a counter (iterator).
 * 
 * When we walk through the loop step by step, we are adding the value of `i`
 * each time.
 * 
 * If n = 5, then:
 *     result = i + i + i + i + i + i
 * Where `i` starts as 0 (int i = 0) and is incremented each time (i++) until
 * the condition is false and we stop.
 *     result += 1
 *     result += 2
 *     result += 3
 *     result += 4
 *     result += 5
 */
int iterative_sum(int n) {
    int result = 0;
    int i = 0;  // starting value
    while (i <= n) {  // when the loop should continue (loop should stop when i > n)
        result += i;  // computing the intermediary result

        i++;  // stepping the loop, to the next number to be added
    }
    return result;
}

/**
 * To convert an iterative solution into a recursive one, 
 * we need to understand that recusive solutions are usually are 
 * solved backwards compared to iterative ones.
 * 
 * So if iteration computes the sum as     0 + 1 + 2 + 3 + 4 + 5
 * Then recusion should compute it as      5 + 4 + 3 + 2 + 1 + 0
 * 
 * If we were to walk through the function execution step by step, 
 * we are adding the value of what the function returns each time.
 * 
 * If n = 5, then:
 *     result = fn(5) + fn(4) + fn(3) + fn(2) + fn(1) + fn(0)
 * Since each time fn() is called, if `n` isn't 0, it will call fn() again
 * minusing 1 from the `n`. 
 * Once the base case is reached, we no longer call the function again and we
 * start to calculate the result starting from the latest function call backwards.
 *     result = fn(5) + fn(4) + fn(3) + fn(2) + fn(1) + 0
 *     result = fn(5) + fn(4) + fn(3) + fn(2) + 1
 *     result = fn(5) + fn(4) + fn(3) + 3
 *     result = fn(5) + fn(4) + 6
 *     result = fn(5) + 10
 *     result = 15
 */
int recursive_sum(int n) {
    if (n == 0) {  // base case, when the function should stop (continues when n > 0)
        return 0;
    }

    return n + recursive_sum(n - 1);  // recurses on itself first
                                      // passing the next number to be added
                                      // and then computes the intermediary result
}