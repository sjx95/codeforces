# Codeforces Round 854 by cybercats (Div. 1 + Div. 2)

> Date: Feb. 27, 2023  
> Announcement: https://codeforces.com/blog/entry/113235  
> Problem Set: https://codeforces.com/contest/1799  
> Official Solution: https://codeforces.com/blog/entry/113321  

After one year of gapping, I'm back but in a very poor status.
To keep myself sharp, I decided to finish 2 - 3 contests per month from now on,
and write something after that.

Unfortunately, I only solved problem A plus B in this contest, and C + D after that.
Problem A "Recent Actions" could be very difficult but indeed really simple with the assumption,
one action could not be in the initial recent actions field and todo list,
which means every un-repeated operation in the todo list will crowd out one initial element in order.
Problem B we can simply select the top 2 elements as (i, j) in a heap,
with the succeeding condition that the current min value is equal to max,
and the failing condition that the value of i did not change after (i, j).

For Problem C, my first solution is to push front then back in order,
but it's wrong because "bab" is of course better than "bba".
After reading the official solution, I found it's better to build the answer from edge to center. After sorting there are 3 situations:
1. current symbol is the same as the next, so just drop it into prefix and suffix; 
2. else, if the next symbol is the same as the last, drop this symbol in central and drop others into prefix and suffix, then stopping;  
*for example, "abbb" -> "bb|ab"*
3. else, drop current to suffix and others to prefix in order.  
*for example, "abcc" - > "bcc|a"*

Problem D is obviously a DP problem.
I wrote the status function in the contest but failed to complete my program for D1.
In my view f(i, j) means the min elapses when "task i" is finished, and "program j" is cached on another processor.
The initial status is +inf, except (0, 0) is 0, with 2 operations:
1. use the last CPU to execute "task i", so status f(i-1, j) moves to f(i, j);
2. use another CPU to execute "task i", so status f(i-1, *) moves to f(i, a[i-1]).

It's O(nk) so should be enough for D1, but too slow for D2.
After reading the official solution I noticed that operation 1 is a "vector operation",
which add hot[a[i]] or cold[a[i]] to f(i-1, *) as f(i, *),
while operation 2 only overwrite f(i, a[i-1]).
So we can split f(i, j) to bias(i) + offset(i, j),
thus operation 1 becomes an O(1) operation, making the total complexity become O(n).

**By the way in my program `iostream` will cause TLE, `ios::sync_with_stdio` should be disabled.**

Problems E, F, G, and H could be too difficult for me, hope I'll be ready to challenge myself on that one day. :dizzy_face:
