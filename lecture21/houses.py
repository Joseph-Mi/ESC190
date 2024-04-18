################################################################################
# Using Dynamic Programming to optimize the cost of painting houses
# a row of N houses, can be painted either green, red or blue
# but no two adjacent houses can be painted with the same color
# divide the prob lem into subproblems - the cost of painting each house

# number of houses
N = 6

# cost[i][j] is the cost of painting the j-th house with the i-th color
houses = [[7, 6, 7, 8, 9, 20],
          [3, 8, 9, 22, 12, 8],
          [16, 10, 4, 2, 5, 7]]

cost = [[0] * N,
        [0] * N,
        [0] * N]

# cost[0][j] is R(j+1)
# cost[1][j] is G(j+1)
# cost[2][j] is B(j+1)

cost[0][0] = houses[0][0]  # R(1)
cost[1][0] = houses[1][0]  # G(1)
cost[2][0] = houses[2][0]  # B(1)

# R(k) = cost(k, "red") + // the cost of painting house k red
#      + min(G(k-1), B(k-1))  // the main cost of painting the first k-1 houses
#                             // either paint k-1 green or blue, whichever is associated with the smaller total cost
# cost[0][k-1] = houses[0][k-1] + min(cost[1][k-2], cost[2][k-2])
# cost[1][k-1] = houses[0][k-1] + min(cost[0][k-2], cost[2][k-2])
# cost[2][k-1] = houses[0][k-1] + min(cost[0][k-2], cost[1][k-2])


for i in range(1, N):
    # the min cost to paint the first i houses, with the i-th being painted red
    cost[0][i] = houses[0][i] + min(cost[1][i-1], cost[2][i-1])

    # the min cost to paint the first i houses, with the i-th being painted green
    cost[1][i] = houses[1][i] + min(cost[0][i-1], cost[2][i-1])

    # the min cost to paint the first i houses, with the i-th being painted blue
    cost[2][i] = houses[2][i] + min(cost[0][i-1], cost[1][i-1])

min(cost[0][5], cost[1][5], cost[2][5]) # the minimal cost of painting the first 6 houses

import numpy as np
np.argmin([cost[0][5], cost[1][5], cost[2][5]]) # the color of the 6th house
                                                # np.argmin for a 1-d array/list
                                                # returns the index of the smallest element

# the colour of house number 5 (starting from 0) is n.argmin([cost[0][5], cost[1][5], cost[2][5]])
# if i know that house number 5 is colour 1,
# house number 4 will be np.argmin([cost[0][4], cost[2][4]])
# (either colour 0 or colour 2, whichever is associated with the smaller total cost)

# L = [cost[0][5], cost[1][5], cost[2][5]]
# L[i]
# want the i s.t. L[i] is the smallest <-- argmin

# ^what argmin does:
# f(x), finds x that minimizes f(x)

cols = [0] * N
i = N-1
# paint the last house
# same as the argmin code
if cost[0][N-1] <= min(cost[1][N-1], cost[2][N-1]):
    cols[N-1] = 0
elif cost[1][N-1] <= min(cost[0][N-1], cost[2][N-1]):
    cols[N-1] = 1
else:
    cols[N-1] = 2

for i in range(N-2, -1, -1):
    cur_min = 10000
    cur_min_col = -1
    for col in [0, 1, 2]:
        if col == cols[i+1]:
            continue
        if cost[col][i] < cur_min:
            cur_min = cost[col][i]
            cur_min_col = col
    cols[i] = cur_min_col



# recursive version
def paint_house_cost(houses, col, i):
    '''Return the cost of painting houses
    0, 1, 2, ,,, i, with the i-th houses painted col
    and the total cost minimized'''
    # same as cost[col][i]
    if i == 0:
        return houses[col][i]

    cur_min = sum(sum(costs) for costs in houses) # summing up the cost of every row of houses
    # cur_sum = 0
    # 
    # for cost in houses:
    # cur_cur_sum = 0
    # for c in cost:
    #   cur_cur_sum += c
    # cur_sum += cur_cur_sum
    # sum of every element in the list of lists houses
    # want to find an upper bound for what the minimal cost for anything could possibly be
    # this is an upper boudn because I'm painting every hosue in all of RGB
    # (but in the solution, for every hosue, would just pay for one colour)
    cur_min_col = -1
    for color in [0, 1, 2]:
        if color == col:
            continue # skip the current color if it's the same as the previous one
        cost_color_i = paint_house_cost(houses, color, i-1)
        if cost_color_i < cur_min:
            cur_min = cost_color_i
            cur_min_col = color
    return houses[col][i] + cur_min


# Analogy to scheduling:
# A course cannot have two assessments scheduled in the same week
# Instructor's have "costs" associated with every deadline during every week
# Task: minimize the total cost of scheduling all assessments

# Colors: week number 0, ..., 13
# Houses: assessments 0, ..., 5



