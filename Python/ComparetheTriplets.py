#code by @Code_Sujith
#!/bin/python

import math
import os
import random
import re
import sys

# Complete the compareTriplets function below.
def compareTriplets(a, b):
    c=[0,0]
    for i in range(3):
        if a[i]>b[i]:
            c[0]=c[0]+1
        elif a[i]==b[i]:
            pass
        else:
            c[1]=c[1]+1
    return c


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = map(int, raw_input().rstrip().split())

    b = map(int, raw_input().rstrip().split())

    result = compareTriplets(a, b)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
