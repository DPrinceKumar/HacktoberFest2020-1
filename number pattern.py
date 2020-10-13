# -*- coding: utf-8 -*-
"""
Created on Tue Oct  6 11:17:54 2020

@author: Gunashree C
"""


def numpattern(n): 
       
    num = 1
   
    for i in range(0, n): 
      
        num = 1
      
        for j in range(0, i+1): 
          
            print(num, end=" ") 
           
            num = num + 1
       
        print("\r") 
 
n = 7

numpattern(n)