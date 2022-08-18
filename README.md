
#           PUSHSWAP 42

The goal of this project is to sort in ascending order numbers with as few operations as possible.

> cvidon@student.42.fr<br>
> athirion@student.42.fr<br>
> yobougre@student.42.fr<br>

##  Index

**[Usage](#usage)**<br>
**[Step 1. Init](#Init)**<br>
**[Step 2. Pre-sort](#pre-sort)**<br>
**[Step 3. Sort](#sort)**<br>

##  Usage

Run `make` in the root of the projet and launch as follows:

    ./push_swap <numbers_to_sort>

Example: `./push_swap "5 3 9 2 7"`

***Makefile rules***

- `make` -- compiles philo.
- `make clean` -- deletes object files.
- `make fclean` -- deletes object files and philo.
- `make re` -- `fclean` + `make``.`

##  Init

Input: `./push_swap "5 3 9 2 7"`
    
Init the Stack_A.

    Stack_A
    5
    3
    9
    2
    7

##  Pre-sort

First we need to find the `median` so we sort a tab of integer, we
pick its middle element as the `median`.

    Tab
    9
    7
    5  ← median
    3
    2

We push from Stack_A to Stack_B all the elements that are smaller
than the median (by repeating `ra` and using `pb` when required).

    Stack_A             Stack_B
    7                   2
    9                   3
    5

We repeat the two previous steps until there are 2 elements left in
`Stack_A`.

    Tab 
    7
    9  ← new median
    5

    Stack_A             Stack_B 
    7                   5
    9                   2
                        3

##      Sort

Now the `pre-sort` is done. We need to find the `leader` and the
`cost` for each element, `pa` the one that has the cheapest cost and
repeat this process.

> The `cost` is the distance to perform to put a `Stack_B` Element in the right
> location of the `Stack_A`.

> The `leader` is the closest value (in terms of value, not distance) between an
> Element in one Stack and an Element in the other Stack.

    Stack_A             Stack_B  |cost|leader|
    7 ← leader          5        | 1  | 7    |
    9                   3        | 2  | 7    |
                        2        | 2  | 7    |

Move cheapest cost element to `Stack_A`.

    Stack_A             Stack_B  |cost|leader|
    5 ← leader          3        | 1  | 5    |
    7                   2        | 2  | 5    |
    9

Move cheapest cost element to `Stack_A`.

    Stack_A             Stack_B  |cost|leader|
    3  ← leader         2        | 1  | 3    |
    5
    7
    9

Move cheapest cost element to `Stack_A`.

Sort done

    Stack_A
    2
    3
    5
    7
    9
