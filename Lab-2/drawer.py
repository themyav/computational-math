import matplotlib.pyplot as plt
import numpy as np
import sys
from math import sin, cos, exp

def e1(x):
    return x*x*x - 2*x

def e2(x):
    return np.sin(x) + 2*np.cos(x)

def e3(x):
    return x*x*x + 2.84*x*x - 5.606*x - 14.766
def e4(x):
    return np.exp(x) + np.sin(x)
def sys1_1(x, y):
    return x*x + y*y - 4
def sys1_2(x, y):
    return -3*x*x + y

def sys2_1(x, y):
    return x*x*x + x*x - 6 + y
def sys2_2(x, y):
    return x*x -12*y + 7
def sys3_1(x, y):
    return y*y*y + x*x - 4
def sys3_2(x, y):
    return x*x + y*y - 2.68
def plot_system(f1, f2, a=-5, b=5):
    x = np.linspace(a, b, 100)
    y = np.linspace(a, b, 100)
    X, Y = np.meshgrid(x,y)
    F1 = f1(X, Y)
    F2 = f2(X, Y)
    plt.contour(X,Y,F1,[0])
    plt.contour(X,Y,F2,[0])
    plt.show()
def plot_graph(f, a=-5, b=5):


# 100 linearly spaced numbers
    x = np.linspace(a, b, 100)

# the function, which is y = x^2 here
    y = f(x)
# setting the axes at the centre
    fig = plt.figure()
    ax = fig.add_subplot(1, 1, 1)
    ax.spines['left'].set_position('center')
    ax.spines['bottom'].set_position('zero')
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')
    ax.xaxis.set_ticks_position('bottom')
    ax.yaxis.set_ticks_position('left')

# plot the function
    plt.plot(x, y, 'r')

# show the plot
    plt.show()


# system or equation
type = sys.argv[1] #int(input())
# number of system/eq
num = sys.argv[2] #int(input())
if type == "1":
    # interval borders
    a = sys.argv[3] #int(input())
    b = sys.argv[4] # int(input())
    plot_graph(eval('e' + str(num)), int(a), int(b))
else:
    plot_system(eval('sys' + str(num) + '_1'), eval('sys' + str(num) + '_2'))

# plot graph

'''
/*
* Уравнения
*/
static ld e1(ld x){
return x*x*x - 2*x;
}

static ld e2(ld x){
return sin(x) + 2*cos(x);
}

static ld e3(ld x){
return x*x*x + 2.84*x*x - 5.606*x - 14.766;
}

static ld e4(ld x){
return exp(x) + sin(x);
}

static ld e5(ld x){
return pow(x, 1/3) - 2*cos(x) + 1;
}
/*
* Системы уравнений
          */
          static ld sys1_1(ld x, ld y){
return x*x + y*y - 4;
}

static ld sys1_2(ld x, ld y){
return -3*x*x + y;
}
static ld sys2_1(ld x, ld y){
return x*x*x + x*x - 6 + y;
}
static ld sys2_2(ld x, ld y){
return x*x -12*y + 7;
}
static ld sys3_1(ld x, ld y){
return y*y*y + x*x - 4;
}
static ld sys3_2(ld x, ld y){
return x*x + y*y - 2.68;
}
plt.plot([1, 2, 3, 4])
plt.ylabel('some numbers')
'''
