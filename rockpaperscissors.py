import random
import re
print("Rock,Paper,Scissor, shoot!")
userchoice = input("choose your weapon [R]ock, [P]aper, [S]cissor :")
if not re.match("[SsRrPp]", userchoice):
    print ("Please choose a letter:")
    print ("[R]ock, [S]cissors or [P]aper.")
print("You chose:",userchoice)
choices=['S','R','P']
opponentchoice = random.choice(choices)
print("I chose:",opponentchoice)
if opponentchoice == userchoice:
    print("Tie!!!")
elif opponentchoice == 'R' and userchoice == 'S':
    print("Rock beats Scissors, YOU LOST :(")
elif opponentchoice == 'P' and userchoice == 'R':
    print("Paper beats Rock, YOU LOST :(")
elif opponentchoice == 'S' and userchoice == 'P':
    print("Sciccors beats Paper, YOY LOST :(")
elif opponentchoice == 'S' and userchoice == 'R':
    print("Rock beats Scissors, YOU WIN :)")
elif opponentchoice == 'R' and userchoice == 'P':
    print("Paper beats Rock, YOU WIN :)")
elif opponentchoice == 'P' and userchoice == 'S':
    print("Sciccors beats Paper, YOY WIN :)")
else:
    print("Enter valid weapon!")
