import numpy as np

def make_change(coins, amt):
    OPT = [np.inf] * (amp + 1)
    #OPT[v] = min( 1 + OPT[v - c], for c in coins)
    OPT[0] = 0

    OPT[j] = min(1 + OPT[j - c] for c in coins if j-c >= 0)

# suppose that we know that the number of coins needed for v is OPT(v)
# to make 11c, what coin should we definitely use?
# which is the smallest?
# opt(11-7)
# opt(11-5) <= we need to use a 5c coin
# opt(11-1)
    
#to make 6c, what coin should we use?
# opt(6-7)
# opt(6-5)   <= can use 5c coin
# opt(6-1)   <= can use 1c coin
    
#to make 1c, what coin should we def use?
# opt(1-7)
# opt(1-5)  
# opt(1-1)

make_change([1, 5, 7], 11) # 3