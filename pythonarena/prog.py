from myalgo import *
ncr=[[0 for i in range(51)] for j in range(51)]
def computecnr():
    ncr[0][0] = 1
    for i in range(1, 51):
        ncr[i][0] = 1
        for j in range(1, i):
            ncr[i][j] = ncr[i-1][j-1]+ncr[i-1][j]
        ncr[i][i] = 1
def solve():
    n = int(raw_input())
    for 