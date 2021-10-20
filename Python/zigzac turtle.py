from turtle import *
from random import *
title('ROHAN Graphics')
def star():
    addshape('star',((6.00,0.00), (1.15,-3.53), (3.00,2.18), (4.85,-3.53), (-0.00,-0.00), (6.00,0.00)))
def heart():
    addshape('heart',((-2.0, -1.9), (-3.8, -1.4), (-5.4, 0.5), (-6.4, 3.9), (-6.3, 6.1), (-5.0, 7.5), (-2.7, 7.5), (-1.6, 6.2), (-1.3, 5.4), (-1.3, 4.1), (-0.7, 5.8), (0.4, 7.0), (1.5, 7.3), (3.5, 6.9), (4.2, 5.2), (4.2, 1.7), (0.3, -1.5)))

star()
heart()
t=Turtle()
t.speed(0)
t.shape('heart')
t.color('red')
t.pencolor('darkred')
t.shapesize(2,2,2)
pencolor("red")
l1=['50']*3
l=['blue','yellow','orange','pink','green','maroon','brown','black','violet','grey','magenta','white','purple','red']
s=['arrow', 'turtle', 'circle', 'square', 'triangle', 'classic','star','heart']
setup(1.0,1.0)
speed(0)
ht()
q=0
width(5)
stamp()
stamp()
stamp()
stamp()
stamp()

while 1:
    n=randrange(1,8)
    m=randrange(0,360,20)    
    pencolor(choice(l))
    r=randrange(3)
    val=int(l1[r])
    val+=randrange(-40,40)
    if val>99:val=80
    elif  val<10:val=30
    l1[r]=str(val)
    bgcolor('#'+''.join(l1))
    q=q+1
    t.rt(20)
    if q==10:
        q=0
        shape(choice(s))
        shapesize(16,16,16)
        tilt(randrange(30,300))
        st()
        stamp()
        ht()
        clearstamps(1)
        color(choice(l))
    rt(m)
    fd(n*30)
    if abs(xcor())>640:
        pu()
        setx(0)
        pd()
    if abs(ycor())>380:
        pu()
        sety(0)
        pd()
      
    

    
