# Algorithm

Input:
    ./pushswap 5 3 9 2 7

0. Init the Stack_A.

    Stack_A:
    5
    3
    9
    2
    7

1. First we need to find the 'median' so we sort a tab of integer, we
pick its middle element as the 'median'.

    Tab:
    9
    7
    5  ← median
    3
    2

2. We push from Stack_A to Stack_B all the elements that are smaller
than the median (by repeating 'ra' and using 'pb' when required).

    Stack_A:            Stack_B:
    7                   2
    9                   3
    5

3. We repeat the steps 1. and 2. until there are only 2 elements left in Stack_A.

    Tab:
    7
    9  ← new median
    5

    Stack_A:            Stack_B:
    7                   5
    9                   2
                        3

4. Now the 'pre-sort' is done. We need to find the 'leader' and the
'cost' for each element, 'pa' the one that has the cheapest cost and
repeat this process.

'cost' = distance to perform to put a Stack B Element in the right
location of the Stack A.

'leader' = closest value (in terms of value, not distance) between an Element
in one Stack and an Element in the other Stack.

    Stack_A:            Stack_B: |cost|leader|
    7 ← leader          5        | 1  | 7    |
    9                   3        | 2  | 7    |
                        2        | 2  | 7    |

Move cheapest cost.

    Stack_A:            Stack_B: |cost|leader|
    5 ← leader          3        | 1  | 5    |
    7                   2        | 2  | 5    |
    9

Move cheapest cost.

    Stack_A:            Stack_B: |cost|leader|
    3  ← leader         2        | 1  | 3    |
    5
    7
    9

Move cheapest cost.

5. Sorted:

    Stack_A:
    2
    3
    5
    7
    9
