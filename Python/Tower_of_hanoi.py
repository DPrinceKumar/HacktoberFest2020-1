```
Author: Ayushi
```
def tower_of_hanoi(n,a,b,c): #a-->source b-->target c-->helper
    #base case:
    if n==0:
        return
    
    #recursive case
    #move n-1 disks from a to b (source to helper)
    
    tower_of_hanoi(n-1,a,c,b)
    print(f'move disk no {n} from {a} to {b}')
    tower_of_hanoi(n-1,c,b,a)