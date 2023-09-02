# push_swap_averager

This tester is called push_swap_averager because it is accurate and detailed in calculating the best case, worst case and the average case of your push_swap. However, it also tests sorting correctness, error handling and memory safety (with Valgrind) of both the mandatory and bonus projects.

## Basic Usage TL;DR (too long didn't read)

#### Make sure your push_swap makefiles are compiling with the O3 flag!
     $(CC) -O3 -Wall -Wex.... etc
#### Clone the tester inside of your push_swap directory:
     git clone https://github.com/Vinni-Cedraz/push_swap_averager
#### And this is how to use it from here:
     make -C push_swap_averager
#### And 
     make -C push_swap_averager bonus

###### You could also cd into the tester's directory and run just ```make``` and ```make bonus``` from there 
     
## Table of Contents

- [The Why](#Why)
- [Installation](#installation)
- [Usage](#usage)
- [How I did it](#Development)
- [Trivia](#trivia)

## Why

This tester is designed to try out a very broad range of combinations for the
5, 100, and 500 array sizes that your `push_swap` program is supposed to sort.

As you probably know by now, during your `push_swap` evaluation, your evaluator
will be asked to run your program a few times with random arrays of specific sizes
and then rank your project according to the results he finds in his tests.

There is a myth going around in the 42 community that says the evaluator is
asked by the ruler to take the average of the tests he has run, but that is not
what the ruler asks. The ruler only requires him to run "a couple of tests with
several permutations" and check it against the scores.]

This means that if your average case is not safely below the number of
operations allowed to get the grade, you'll have a very annoying chance that
the evaluator will incur precisely into a case where you're slightly above the
limit and you won't get the highest grade.

This could make or break your bonus project. Imagine
how insufficient it is to measure 5 cases out of 100 factorial:

It would be 5 samples out of:

93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000

For an array of size 500, the number is even more obscene:

1220136825991110068701238785423046926253574342803192842192413588385845373153881997605496447502203281863013616477148203584163378722078177200480785205159329285477907571939330603772960859086270429174547882424912726344305670173270769461062802310452644218878789465754777149863494367781037644274033827365397471386477878495438489595537537990423241061271326984327745715546309977202781014561081188373709531016356324432987029563896628911658974769572087926928871281780070265174507768410719624390394322536422605234945850129918571501248706961568141625359056693423813008856249246891564126775654481886506593847951775360894005745238940335798476363944905313062323749066445048824665075946735862074637925184200459369692981022263971952597190945217823331756934581508552332820762820023402626907898342451712006207714640979456116127629145951237229913340169552363850942885592018727433795173014586357570828355780158735432768888680120399882384702151467605445407663535984174430480128938313896881639487469658817504506926365338175055478128640000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

This is **why** the `push_swap-averager` was born: to give you a broader perspective
on your push_swap performance before you submit it for evaluation. And it does
that not only by taking precise averages but also by giving you the worst cases
it found so that if you want to be extremely safe, you can guide yourself by
the worst case instead.

## Installation
Just clone it inside of your push_swap directory:

`git clone https://github.com/Vinni-Cedraz/pushswap-averager.git`

## Usage
### basic usage

*First: it is **CRUCIAL** that you set your push_swap Makefiles to compile everything with the -O3 flag!*

Then, just do this from your push_swap root directory and your program will be
compiled and the tests will be run:

`make -C push_swap-averager`

The first tests will be error_management and identity_test which are based on
the first items in the guide for the evaluation of the project

The second test will be the basic_test, it tests if you are sorting the
arrays and accuses any memory leaks. It will do so with:
- all unsorted arrays of size 3 (checking the limit of 2 operations for size 3)
- one unsorted array of each size 5, 10, 15, 20, 50, 100, 500 and 1000
Then the tests for the averages will start.

If you passed on all of those and did the bonus part:
- Bonus

`make -C push_swap_averager bonus`

Error management is going to be the first test. Not only incorrect arguments to
the checker will be tested but also incorrect input such as "   pa  ". Then the
bonus rule will test the correctness of your checker against the official
checker_linux for "OK" cases and will accuse any memory leaks it finds.

### advanced features

- You can open the log files containing all array permutations that were tested
for each size and the number of operations push_swap took to sort it. You can
also use grep to figure out which and how many arrays scored a given number,
for example:

`cat push_swap_averager/log_files/test100.log | grep "operations: 600"`

- You can run parts of the test separately:

`make -C push_swap_averager test100`

`make -C push_swap_averager test500`

`make -C push_swap_averager averager`

## Development

Since the number of permutations and the computation can be intense, I decided
to take a multithreaded approach. I chose 8 to be the number of threads since
the 42 iMacs have 4 cores and support 2 threads per core, this way, true
parallelism can be achieved. I even tested subdividing the tasks into more than
8 threads but the performance did not improve and even started to go down. So I
stuck with 8 threads.

For this, I only had to use two functions from the C library `pthread.h`: 
`pthread_create` and `pthread_join`. I use a micro-managed subdivision of tasks to
avoid race conditions instead of mutexes, which would complexify and slow down
things in this context.

To test thousands of permutations in a semi-random pattern that would be as
representative as possible, I have divided the total number of permutations
of an N-sized array into N groups. Then, I pick up 12 random permutations
from each of these N groups to create the sample set of permutations that will
be tested as input for your `push_swap`. These permutations were initially
generated by a very simple implementation of the Fisher-Yates algorithm.

This means that for the 100 size, the `push_swap-averager` will be
executing your push_swap 1,200 times. It is still a small number compared to
the total. But because of the way the combinations are selected, the result is
a very consistent measurement of your average case and it can be finished
within 2 seconds on the 4 cores / 2 threads per core iMacs we have at the 42
school.

As it was, if I ran the `push_swap-averager` 30 times in a row, I would see a
slightly different result each time so I had to calculate the difference
between the highest and the lowest of the 30 averages to see check if the test
is reliable enough.

For example, out of 30 tests, my `push_swap` program ranked averages between
547 and 647. This is a "margin of error" of 100 operations, so I had to increase
the number of tests (up to 15,000) to get to an acceptable margin of 10. It was
taking 30 seconds now instead of 2, so I thought it was ok.

However, when I applied the same Fisher-Yates algorithm to randomize the 500
elements array, I realized the result (the measurement of the average) was not
consistent enough unless the test took 5 to 10 minutes, and that is too much time.

Then I've done some research on the basics of Pseudorandomness in computer
science and decided to implement the Mersenne-Twister algorithm to improve both
the consistency of the average-case calculations and the execution speed of the
program. 

The Mersenne Twister algorithm is a well-known and widely used algorithm for
generating high-quality pseudo-random numbers. It has been extensively tested
and shown to be very efficient and effective at generating well-distributed
permutations. It is commonly used in scientific simulations and other
applications that require high-quality random number generation. That is why I
chose it. You can find its implementation in the source file called
`mersenne_twister_algorithm.c`.

Now, with more well-distributed permutations the program takes 2 seconds to
calculate the average of the size 100 with a margin of error of 4 operations.
That is an improvement of 2400% in accuracy, without adding any extra time to the
program execution.

## Trivia
- The longest English word with all its letters in alphabetical order is
"aegilops," which is a type of plant.
- Scientists have discovered a set of snow crystals that may be the first
matching pair ever found, challenging the common belief that no two snowflakes
are alike. The crystals were collected on a glass plate during a research
flight over Wisconsin in 1986 and were found to have almost identical growth
histories. The discovery raises the possibility that more identical pairs of
snow crystals could be found in the future.
- The traditional method of shuffling playing cards, known as the riffle
shuffle, is not truly random. A study published in the Proceedings of the
National Academy of Sciences found that if someone knows the initial order of
the cards, they can predict the outcome of a riffle shuffle with high
accuracy.
