def fib(n, fib_dict = {}):
    if n in [0, 1]:
        return 1
    
    # if n in fib_dict:
    #     return fib_dict[0]
    # else:
    #     fib_dict[n] = fib(n-1, fib_dict) + fib_dict(n-1, fib_dict)

    if n not in fib_dict:
        fib_dict[n] = fib(n-1, fib_dict) + fib_dict(n-1, fib_dict)

    return fib_dict[n]

    #memoization:
    #store the result of the function call every time it happens
    #O(n)

#fib(n) ~ phi^n/sqrt(t5)
# the number of digits in fib(n) is log(fib(n)) = n log(phi) - log(5)/2
# the amount of space needed to sotre f(1)...f(n):
# log(phi) + (1 +2 + 3 + ... + n) - n log(5)/2 is O(n^2)
# (1 +2 + 3 + ... + n) = n(n_1)/2
##if we store in list rather than dictionary

# fib(1)  fib(0)
#     \  /
#     fib(2)  fib(1)
#         \  /
#         fib(3)  fib(2)
#             \  /
#             fib(4)
#shaoe of tree: full branch always going left, of size n
# branching out to branches to right, 1 step every time
#Total: 2n calls