import numpy as np

#a
##  OPT(n) = should be a for loop that calculates opt(n-c) and adds 1 each time
# opt is the number of iterations to go through

def make_change(coins, value):
    opt = []
    opt.append(0)
    for i in range(1, value+1):
        val = []
        for coin in coins:
            if (i - coin) >= 0:
                val.append(1+opt[i - coin])

        if (not val):
            opt.append(-1)
            continue
        else:
            opt.append(min(val))
        # a = val[0]
        # for options in val:
        #     if options < a:
        #         a = options
        # if (a == NULL):
        #     return -1
        # return a
    print(opt)


def used_change(coins, value):
    opt = []
    used = []
    used.append([None])
    opt.append(0)
    for i in range(1, value+1):
        vals = []
        possible = []
        for coin in coins:
            if (i - coin) >= 0:
                vals.append(1+opt[i - coin])
                possible.append([coin] + used[i - coin])
            else:
                possible.append([None] + [None])

        if (not vals or not possible):
            opt.append(-1)
            used.append([None])
            continue
        else:
            opt.append(min(vals))
            used.append(min(possible, key = len))
            
    used[value].pop()
    return used[value]


sol = dict() # value->[coin1, coin2, ...]

def top_down(coins, value):
    if value == 0:
        sol[0] = []
        return []
    if value < min(coins):
        sol[value] = None
        return None
    # value < 0: checked!
    if value in sol:
        return sol[value]
    num = value + 1 # a large number
    for coin in coins:
        if value >= coin:
            change = top_down(coins, value - coin)
            if change is None:
                continue
            if len(change) < num:
                num = len(change)
                sol[value] = change + [coin]
    if value in sol: 
        return sol[value] # not work for None
    else:
        sol[value] = None
        return None


coins = [1, 3, 8]
print(top_down(coins, 3))
print(used_change(coins, 5))

# coins = [2, 4, 5]
# used_change(coins, 98)
# print(top_down(coins, 98))

# for i in range(2, 100):
#     if top_down(coins, i) != used_change(coins, i):
#         print(f"{i=}")
#         print(f"{top_down(coins, i)=}")
#         print(f"{used_change(coins, i)=}")
