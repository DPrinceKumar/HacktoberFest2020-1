# def postfix(s):
#     stack = []
#     exp = ["+", "-", "*", "/", "^"]
#     for i in s:
#         if i == "(":
#             stack.append(i)
#         elif i != "(" and i != ")" and i not in exp:
#             print(i, end="")
#         elif i != "(" and i in exp:
#             if len(stack) != 0 and stack[-1] != "(":
#                 if exp.index(stack[-1]) > exp.index(i):
#                     stack.append(i)
#                 else:
#                     print(stack.pop(), end="")
#             else:
#                 stack.append(i)
#         elif i == ")":
#             while stack[-1] != "(":
#                 print(stack.pop(), end="")
#             stack.pop()
#     if len(stack) != 0:
#         while stack[-1] != "(":
#             print(stack.pop(), end="")
#         stack.pop()


# s = "A+(B*C-(D/E^F)*G)*H"
# postfix(s)


# def fuc(i1, i2, i3, i4):
#     a = []
#     a.append(i1.index(i4))
#     a.append(i2.index(i4))
#     a.append(i3.index(i4))
#     a.sort()
#     return (a[2] - a[1]) + (a[2] - a[0])


# a = [10, 20, 30, 40, 60, 62, 30, 90, 20]
# b = [90, 20, 30, 80, 50, 10, 60, 22, 99]
# c = [10, 30, 20, 40, 50, 90, 88, 99, 88]
# d = 90
# print(fuc(a, b, c, d))

# for _ in range(int(input())):
#     a = list(input())
#     b = input()
#     a.sort()
#     op = ""
#     for i in b:
#         a.remove(i)
#     for i in range(len(a)):
#         if a[i] == b[0]:
#             op += a[i]
#     for i in op:
#         a.remove(i)
#     a.append(op)
#     a.append(b)
#     a.sort()
#     print("".join(a))

# for _ in range(int(input())):
#     f = int(input())
#     a = [int(x) for x in input().split()]
#     b=[0]*
#     for i in range(f):
#         op = 0
#         for j in range(i+1, f):
#             if(min)
#         print(op-1)


# def solve(queries, Q):
#     a = [
#         0,
#     ]
#     for i in range(Q):
#         if queries[i][0] == 1:
#             for j in range(len(a)):
#                 a[j] = a[j] ^ queries[i][1]
#         else:
#             a.append(queries[i][1])
#     a.sort()
#     return a


# Q = int(input())
# queries = [list(map(int, input().split())) for i in range(Q)]
# print(" ".join(str(x) for x in solve(queries, Q)))

# n = int(input())
# m = int(input())
# s = input()

# print(str(eval(str(n) + s[0] + str(m)))+str(eval(str(n) + s[1] + str(m)))+str(eval(str(n) + s[2] + str(m))))

# for _ in range(int(input())):
#     n, k = map(int, input().split())
#     s = input()
#     a = s.count("1")
#     b = s.count("0")
#     c = n // k
#     op1 = ""
#     op2 = ""
#     op = ""
#     if a % c != 0 or b % c != 0:
#         print("IMPOSSIBLE")
#     else:
#         if a != b:
#             op1 = "0" * (b // c) + "1" * (a // c)
#             op2 = "1" * (a // c) + "0" * (b // c)
#             if c % 2 == 0:
#                 op = (op1 + op2) * (c // 2)
#             else:
#                 op = ((op1 + op2) * (c // 2)) + op1
#         else:
#             if c % 2 == 0:
#                 op = (
#                     "0" * (b // c) + "1" * (a // c) + "1" * (a // c) + "0" * (b // c)
#                 ) * (c // 2)
#             else:
#                 op = (
#                     ("0" * (b // c) + "1" * (a // c) + "1" * (a // c) + "0" * (b // c))
#                     * (c // 2)
#                 ) + ("0" * (b // c) + "1" * (a // c))
#     print(op)

a = [["a"], ["b", "c"]]
print(a.index(["c
"]))
