#!/usr/bin/env python
# coding: utf-8

# In[9]:


import turtle

wn=turtle.Screen()

bob=turtle.Turtle()

dist=100
angle=90
for i in range(60):
    bob.forward(dist)
    bob.left(angle)
    dist+=1
    angle-=1
wn.exitonclick()
