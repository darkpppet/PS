import sys
from math import *

full_text = sys.stdin.readlines()
n_s_list = [[int(x) for x in line.split()] for line in full_text]

for n, s in n_s_list:
    print(floor(s / (n+1)))
