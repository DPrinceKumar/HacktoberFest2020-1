from matplotlib.patches import Rectangle
import matplotlib.pyplot as plt
import random
import matplotlib
matplotlib.use('TkAgg')


# tromino methods

# auxilary functions to draw trominoes


def draw_L1(x, y):
    plt.plot([x, x+2], [y+2, y+2], 'k-')
    plt.plot([x, x+1], [y+1, y+1], 'k-')
    plt.plot([x+1, x+2], [y, y], 'k-')
    plt.plot([x, x], [y+1, y+2], 'k-')
    plt.plot([x+1, x+1], [y, y+1], 'k-')
    plt.plot([x+2, x+2], [y, y+2], 'k-')


def draw_L2(x, y):
    plt.plot([x, x+2], [y+2, y+2], 'k-')
    plt.plot([x, x+1], [y, y], 'k-')
    plt.plot([x+1, x+2], [y+1, y+1], 'k-')
    plt.plot([x, x], [y, y+2], 'k-')
    plt.plot([x+1, x+1], [y, y+1], 'k-')
    plt.plot([x+2, x+2], [y+1, y+2], 'k-')


def draw_L3(x, y):
    plt.plot([x, x+2], [y, y], 'k-')
    plt.plot([x, x+1], [y+1, y+1], 'k-')
    plt.plot([x+1, x+2], [y+2, y+2], 'k-')
    plt.plot([x, x], [y, y+1], 'k-')
    plt.plot([x+1, x+1], [y+1, y+2], 'k-')
    plt.plot([x+2, x+2], [y, y+2], 'k-')


def draw_L4(x, y):
    plt.plot([x, x+2], [y, y], 'k-')
    plt.plot([x, x+1], [y+2, y+2], 'k-')
    plt.plot([x+1, x+2], [y+1, y+1], 'k-')
    plt.plot([x, x], [y, y+2], 'k-')
    plt.plot([x+1, x+1], [y+1, y+1], 'k-')
    plt.plot([x+2, x+2], [y, y+1], 'k-')


# recursive methods for drawing trominoes

# {bottom-left(x,y),size of board(n),loc of hole(p,q)}
def trominoes(x, y, n, p, q):
    if n == 2:
        if y == q:  # hole in bottom tiles
            if x == p:
                draw_L1(x, y)
            else:
                draw_L2(x, y)
        else:  # hole in top tiles
            if x == p:
                draw_L3(x, y)
            else:
                draw_L4(x, y)

    else:
        mid_x = x+n//2
        mid_y = y+n//2

        if q < mid_y:

            if p < mid_x:
                draw_L1(mid_x-1, mid_y-1)
                trominoes(x, y, n//2, p, q)
                trominoes(x, mid_y, n//2, mid_x-1, mid_y)
                trominoes(mid_x, y, n//2, mid_x, mid_y-1)
                trominoes(mid_x, mid_y, n//2, mid_x, mid_y)
            else:
                draw_L2(mid_x - 1, mid_y - 1)
                trominoes(x, y, n // 2, mid_x - 1, mid_y - 1)
                trominoes(x, mid_y, n // 2, mid_x - 1, mid_y)
                trominoes(mid_x, y, n // 2, p, q)
                trominoes(mid_x, mid_y, n // 2, mid_x, mid_y)

        else:
            if p < mid_x:
                draw_L3(mid_x - 1, mid_y - 1)
                trominoes(x, y, n // 2, mid_x - 1, mid_y - 1)
                trominoes(x, mid_y, n // 2, p, q)
                trominoes(mid_x, y, n // 2, mid_x, mid_y - 1)
                trominoes(mid_x, mid_y, n // 2, mid_x, mid_y)
            else:
                draw_L4(mid_x - 1, mid_y - 1)
                trominoes(x, y, n // 2, mid_x - 1, mid_y - 1)
                trominoes(x, mid_y, n // 2, mid_x - 1, mid_y)
                trominoes(mid_x, y, n // 2, mid_x, mid_y - 1)
                trominoes(mid_x, mid_y, n // 2, p, q)


# implement

fig = plt.figure()  # creates figure
fig.patch.set_facecolor('white')  # sets backgrnd color to white
ax = plt.gca()  # captures axes of fig
n = 16
p = random.choice([i for i in range(n)])
q = random.choice([i for i in range(n)])
ax.add_patch(Rectangle((p, q), 1, 1, facecolor=(0.5, 0.5, 0.5)))  # hole drawn
trominoes(0, 0, n, p, q)

plt.axis('equal')  # to avoid scaling factor
plt.axis('off')  # to eliminate axes in final img
plt.show()  # to draw
