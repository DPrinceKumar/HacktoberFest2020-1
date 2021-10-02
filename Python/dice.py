import random

roll_again = "yes"

while roll_again == "yes" or roll_again == "y":
    print('Rolling dices...')
    print('You got :')

# generating values from range for first 
    print(random.randrange(1,6))
# generating values from range for second 
    print(random.randrange(1,6))
    
    roll_again = input('Do you need to roll again(y/n)? :')