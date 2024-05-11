/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 *
 * This warmup task gives you practice with C++ expressions, control structures, and functions,
 * as well as testing and debugging your code.
 */

#include <iostream>
#include <cmath>
#include "console.h"
#include "SimpleTest.h"
#include "perfect.h"

using namespace std;

/*
 * Note: the C++ long type is a variant of int that allows for a
 * larger range of values. For all intents and purposes, you can
 * treat it like you would an int.
 */

/* The divisorSum function takes one argument `n` and calculates the
 * sum of proper divisors of `n` excluding itself. To find divisors
 * a loop iterates over all numbers from 1 to n-1, testing for a
 * zero remainder from the division using the modulus operator %
 */
long divisorSum(long n) {
    long total = 0;
    for (long divisor = 1; divisor < n; divisor ++ ) {
        if (n % divisor == 0) {
            total += divisor;
        }
    }
    return total;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 *
 * The smarterSum function takes one argument 'n' and
 * produces the same result as the original divisorSum
 * but uses the square root trick to tighten up the loop.
 * When it finishes executing, it returns the sum of the factors,
 * which is total + 1.
 */
long smarterSum(long n) {
    /* TODO: Fill in this function. */
    long total = 0;
    // edge condition 1: each number has a factor of 1.
    for (long divisor = 2; divisor <= sqrt(n); divisor ++ ){
        if (n % divisor == 0){
            if (divisor != n / divisor ){
                total += (divisor + n / divisor);
            } else{
                total += divisor;
            } // edge condtion 2: If sqrt(n) is an int, then divisor == n / divisor.
        }
    }
    return total + 1; // notice: remember add 1 to the ans.
}

/* The isPerfect function takes one argument `n` and returns a boolean
 * (true/false) value indicating whether or not `n` is perfect.
 * A perfect number is a non-zero positive number whose sum
 * of its proper divisors is equal to itself.
 */

// notice: a perfect number is a non-zero positive number.
bool isPerfect(long n) {
    return (n != 0) && (n == divisorSum(n));
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 *
 * The isPerfectSmarter takes one argument 'n' and returns a boolean
 * value indicating whether or not 'n' is perfect, and a perfect number
 * is a non-zero positve number whose sum of its proper divisors is equal
 * to itself.
 */
bool isPerfectSmarter(long n) {
    /* TODO: Fill in this function. */
    return (n != 0) && (n == smarterSum(n));
}

/* The findPerfects function takes one argument `stop` and performs
 * an exhaustive search for perfect numbers over the range 1 to `stop`.
 * Each perfect number found is printed to the console.
 */
void findPerfects(long stop) {
    for (long num = 1; num < stop; num ++ ) {
        if (isPerfect(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush; // progress bar
        /*
            Use "flush" to force the stream to be flushed, ensuring that all content
            in the buffer is immediately outputted rather than waiting for the buffer
            to fill up or encountering a newline character.
            Typically, content outputted to the standard output stream('cout') is first
            placed in a buffer, and it is only actually outputted when the buffer is
            full, the program ends, encounters a newline character '\n', or when 'flush'
            is used to force a flush. Using 'flush' ensures that content is immediately
            outputted even if the buffer is not full, without waiting for the program to
            end or encountering a newline character.
         */
    }
    cout << endl << "Done searching up to " << stop << endl;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 *
 * The findPerfectsSmarter function takes one argument 'stop' and use the
 * squart root trick to optimize the search process, over the range 1 to 'stop'.
 * And each perfect number found is printed to the console.
 */
void findPerfectsSmarter(long stop) {
     /* TODO: Fill in this function. */
    for (long num = 1; num < stop; num ++ ){
        if(isPerfectSmarter(num)){
            cout << "Found perfect number smartly: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush;
    }
    cout << endl << "Done searching up to " << stop << endl;
}

// Assume that all inputs(values of n) will be positive(that is, greater than 0).
// In particular, this means that you don't have to worry about negative values of
// n or the case where n is zero.

/* TODO: Replace this comment with a descriptive function
 * header comment.
 *
 * The findNthPerfectEuclid function takes an argument 'n'
 * and return the n-th perfect number by using the Euclid trick.
 */
long findNthPerfectEuclid(long n) {
    /* TODO: Fill in this function. */
    long idx = 0;
    long k = 1;
    while (idx < n){
        long m = pow(2, k ++ ) - 1;
        if (smarterSum(m) == 1) idx ++ ;
    }
    long ans = pow(2, k-1) * (pow(2, k) - 1);
    return ans;
}

/* * * * * * Test Cases * * * * * */

/*
// reversed(str) returns copy of str with characters in reverse order.
string reversed(string s)
{
    string result;
    for (int i = s.length() - 1; i >= 0; i-- ){
        result += s[i];
    }
    return result;
}
*/

/* * * * * * Test Cases * * * * * */

/*
    The string argument in parentheses describes the purpose
    of the test.
*/

/*
PROVIDED_TEST("Demonstrate different SimpleTest use cases"){
    /*
        And the code block that follows(enclosed in curly braces) defines
        the autual test behavior.
     */
/*
    EXPECT_EQUAL(reversed("but"), "tub");
    EXPECT_EQUAL(reversed("standford"), "drofnats");
}
*/

// TODO: add your STUDENT_TEST test cases here!

/*
    Selecting appropriate input sizes is a bit of an art form.
    If you choose a size that is too small, it can finish so quickly that
    the time is not measurable or gets lost in the noise of other activity.
    A size that is too large will have you impatiently waiting for it to complete.

    You are generally aiming for test cases that complete in 10-60 seconds.
    Note that a size that is just right for your friend's computer might be
    too small or too larger for yours, so you may need a bit of trial and error
    on your system to find a good range.
 */

/*
    Try different sizes to determine the largest size which your computer can
    complete in around 60 secs or so.

    Now edit your STUDENT_TEST to do four time trials on increasing sizes,
    doubling the size each time and ending with the final trial of that large
    size.

    The starter code includes some sample code showing how to use a loop to
    configure a series of time trials.
    This is a great technique to add to your repertoire!
 */

STUDENT_TEST("Look up what happens if isPerfect is given a negative input"){
    // The expected result of isPerfect for such inputs should be false.
    for (int i = 5; i; i -- ){
        EXPECT(!isPerfect(-i));
    }
}

// Tests for the Practice with TIME_OPERATION
/*
STUDENT_TEST("Check if the edge condition happens"){
    EXPECT_EQUAL(divisorSum(4), smarterSum(4));
}

STUDENT_TEST("Check if the edge condition happens"){
    EXPECT_EQUAL(divisorSum(9), smarterSum(9));
}

STUDENT_TEST("Check if the edge condition happens"){
    EXPECT_EQUAL(divisorSum(16), smarterSum(16));
}
*/


// Tests for the Turbo-charging with Euclid
STUDENT_TEST("Verify that your findNthPerfectEuclid works correctly"){
    EXPECT(isPerfectSmarter(findNthPerfectEuclid(1)));
}

STUDENT_TEST("Verify that your findNthPerfectEuclid works correctly"){
    EXPECT(isPerfectSmarter(findNthPerfectEuclid(2)));
}

// Why the following code is wrong? The number exceeds?
STUDENT_TEST("Verify that your findNthPerfectEuclid works correctly"){
    EXPECT(isPerfectSmarter(findNthPerfectEuclid(3)));
}

STUDENT_TEST("Verify that your findNthPerfectEuclid works correctly"){
    EXPECT(isPerfectSmarter(findNthPerfectEuclid(4)));
}


STUDENT_TEST("Check if A call to findNthPerfectEuclid(5) should near instantaneously return the fifth perfect number"){
    TIME_OPERATION(5, findNthPerfectEuclid(5));
}

/*
 * Here is sample test demonstrating how to use a loop to set the input sizes
 * for a sequence of time trials.
 */

/*
STUDENT_TEST("Multiple time trials of findPerfects on increasing input sizes") {
   int smallest = 64000, largest = 256000;
   for (int size = smallest; size <= largest; size *= 2) {
       TIME_OPERATION(size, findPerfects(size));
   }
}
*/

// Tests for the Streamlining and more testing
/*
STUDENT_TEST("See just how much improvement we've gained"){
    int smallest = pow(2, 12) * 1e3, largest = pow(2, 13) * 1e3;
    for (int size = smallest; size <= largest; size *= 2){
        TIME_OPERATION(size, findPerfectsSmarter(size));
    }
}
*/

/*
    Line 136 TIME_OPERATION findPerfects(size) (size =    64000) completed in    2.092 secs
    Line 136 TIME_OPERATION findPerfects(size) (size =   128000) completed in    8.206 secs
    Line 136 TIME_OPERATION findPerfects(size) (size =   256000) completed in   32.937 secs
    Line 136 TIME_OPERATION findPerfects(size) (size =   512000) completed in  133.967 secs
 */

/*
    Correct (STUDENT_TEST, line 180) See just how much improvement we've gained
    Line 183 TIME_OPERATION findPerfectsSmarter(size) (size =    64000) completed in    2.057 secs
    Line 183 TIME_OPERATION findPerfectsSmarter(size) (size =   128000) completed in    8.230 secs
    Line 183 TIME_OPERATION findPerfectsSmarter(size) (size =   256000) completed in   32.808 secs
 */

/*
    Correct (STUDENT_TEST, line 182) See just how much improvement we've gained
    Line 185 TIME_OPERATION findPerfectsSmarter(size) (size =  4096000) completed in   11.398 secs
    Line 185 TIME_OPERATION findPerfectsSmarter(size) (size =  8192000) completed in   31.603 secs
 */

/*
    Doubling the input size doesn't take simply twice the time;
    The time goes up by a factor of 4.
    There is a quadratic relationship between size and program execution time.
 */


/* Please not add/modify/remove the PROVIDED_TEST entries below.
 * Place your student tests cases above the provided tests.
 */

PROVIDED_TEST("Confirm divisorSum of small inputs") {
    EXPECT_EQUAL(divisorSum(1), 0);
    EXPECT_EQUAL(divisorSum(6), 6);
    EXPECT_EQUAL(divisorSum(12), 16);
}

PROVIDED_TEST("Confirm 6 and 28 are perfect") {
    EXPECT(isPerfect(6));
    EXPECT(isPerfect(28));
}

PROVIDED_TEST("Confirm 12 and 98765 are not perfect") {
    EXPECT(!isPerfect(12));
    EXPECT(!isPerfect(98765));
}

PROVIDED_TEST("Test oddballs: 0 and 1 are not perfect") {
    EXPECT(!isPerfect(0));
    EXPECT(!isPerfect(1));
}

PROVIDED_TEST("Confirm 33550336 is perfect") {
    EXPECT(isPerfect(33550336));
}

PROVIDED_TEST("Time trial of findPerfects on input size 1000") {
    TIME_OPERATION(1000, findPerfects(1000));
}
