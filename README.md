# pushswap-averager

# STILL IN CONSTRUCTION (to be finished by the 28th of April)

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Trivia](#trivia)

## Introduction (or, Why bother?)

Buckle up for a long ride!

This tester is designed to try out a very broad range of combinations for the
5, 100, and 500 array sizes that your `push_swap` program is supposed to sort.

As you probably know by now, during your `push_swap` evaluation, your evaluator
will be asked to take the average case of your program and then rank your
project according to this average case for each array size.

However, evaluations where the average case is measured with some accuracy have
been very hard to find. This is because the number of permutations that can be
generated from an N sized array is N!, which is an astronomical number. And I
mean, it is a number so big that it couldn't fit in a million `size_t` variables,
even if we divided it by a billion.

So, for any case beyond the array 5 elements, it is impossible for the
evaluator to calculate the exact average case of your `push_swap` algorithm. But
this is not an excuse to simply test your program with 5 or 10 random arrays of
size 100 and 500 and draw conclusions out of it!

This is so much of a big deal that it could make or break your project! Imagine
how insufficient it is to measure 10 cases out of 100! The average of those ten
could be really far from the truth. It would be 10 random cases out of:

93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000

For an array of size 500 the number is even more obscene:

1220136825991110068701238785423046926253574342803192842192413588385845373153881997605496447502203281863013616477148203584163378722078177200480785205159329285477907571939330603772960859086270429174547882424912726344305670173270769461062802310452644218878789465754777149863494367781037644274033827365397471386477878495438489595537537990423241061271326984327745715546309977202781014561081188373709531016356324432987029563896628911658974769572087926928871281780070265174507768410719624390394322536422605234945850129918571501248706961568141625359056693423813008856249246891564126775654481886506593847951775360894005745238940335798476363944905313062323749066445048824665075946735862074637925184200459369692981022263971952597190945217823331756934581508552332820762820023402626907898342451712006207714640979456116127629145951237229913340169552363850942885592018727433795173014586357570828355780158735432768888680120399882384702151467605445407663535984174430480128938313896881639487469658817504506926365338175055478128640000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

This is why the `push_swap-averager` was born

To test thousands of permutations in a semi-random pattern that would be as
representative as possible, I have divided the total number of permutations
of an N-sized array into N groups. Then, I pick up (8 * N) random permutations
from each of these N groups to create the sample set of permutations that will
be tested as input for your `push_swap`.

This means that for the 100 size case, I will be executing your push_swap 80,000
times. The result is a surprisingly reliable measurement of your average case!
To "test the tester," you can take it several times in a row and you'll see what I'm
talking about: each time the test is taken, the count of the average case will
be slightly different but only by a very small deviation. For example, out of 10
tests, my `push_swap` program ranked averages that oscillated between 583 and 586!

I know I could have done it with a `Bash` script, and it would make for a shorter
code and a simpler program. In fact, I had...

The issue was that it was taking three and a half hours to test 60,000 combinations!
This is why I decided to build this tester in `C` instead and then speed it up
further with a multithreaded approach. Now it should take 5 minutes to test
80,000 combinations of size 100 and analyze them for you.

So this is why I bothered to make this test.

## Installation
This is the installation section.

## Usage
This is the usage section.

## Trivia
This is the trivia section.
