## Exercise 1
By using MPI_Ssend und MPI_Recv by splitting the processes into 
even and odd, we can omit deadlocks. This solves the problem, because
the even processes send their ranks while the odd wait until they "send"
 are done,
then the odd receive the ranks from the even and add their ranks to the sum.

This solution, is not optimal since the process have to wait and don't do it all at once.
They lose a lot of speed by just waiting.

Blocking: return only when the buffer is ready to be reused. 
Non-blocking: return immediately. Buffering: data is kept until it is received.
Therefor Non-blocking is in our case faster than the blocking one.

#### Bonus
This exercise is solved in the bonus.c code

## Exercise 2
Approx pi computed: 3.14159265  
Pi: 3.14159265359...

## Exercise 3
#### 3.1.3 Bonus
Since I was not able to run the code I'm not sure if this works, I think it should
but the computation of poisson fails and therefor I was not able to test it

## Exercise 4
My code is not working, so I tried your executable but this also did not work.
So I was not able to perform the given questions

## Exercise 5
The line 21 and 22 which computes sqrt(dx * dx + dy * dy + dz * dz) and (1 / r * r * r) takes the most CPU, since
divisions with floating points are harder to be calculated. We can see that line 22 is most expensive,
but 21 not so much. This means that by computing the performance it sums the computation of both
together. 

#### Learning
We can see where the code is efficient and where not how we can improve the
computation and where to take care. So table 2 is in our case the most important,
but the others are also very nice for other usecases.


