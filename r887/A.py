# Read in number of test cases, and for each, number of list items,
# then the list items. Example:
#
# 4
# 2
# 1 1
# 4
# 1 8 10 13
# 3
# 1 3 2
# 3
# 1 9 14

for _ in range(int(input())):
    input() # get rid of number of list items

    # Input line in form of "1 8 10 13" and make it a list of ints
    lst = list(map(int, input().split()))

    # The list should be monotonically increasing
    diff = min(j-i for i,j in zip(lst, lst[1:]))

    print(max(0, diff//2 + 1))