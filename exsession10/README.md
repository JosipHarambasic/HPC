## Exercise 1

We can see that the first computation takes longer than the other 4 compuations.
This is because the GPU needs to load the modules and the data. After that it is much faster for the other compuations.

## Exercise 3

We can see that every time we create a new block sizes that the computation takes a bit longer, and then
it starts to perform better. This is like all the computation in the GPU's where the first computation takes the most time
and then the real power shines afterwards. In the plot we can see the more Blocks and Threads we have the faster the computation,
but it has an asymptotic curve which seems to limit the speed. This means if we take even more GPU's the time does not go any lower
(not much more).






