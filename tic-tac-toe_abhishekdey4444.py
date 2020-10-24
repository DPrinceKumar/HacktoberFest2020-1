'''-----------------variable of chance(no. of moves)------------------'''
chance=0
global board
board=[[" " for i in range(3)] for j in range(3)]
'''-----------------:variables ends here:-----------------'''




'''-----------------functions needed---------------------'''

def board_show():
    print("\n\n")
    for show in board:
        print(show)
        
def details():
    print("\nPLAYER 1: Enter name below:- \n")
    global player1
    player1=input()
    print("\nPLAYER 2: Enter name below:- \n")
    global player2
    player2=input()
    
def symbolCheck():
    print("\n%s you are PLAYER 1 hence, you should decide your symbol first"%(player1))
    print("\n\nInput X or O (CAPITAL letters only :)\n")
    global symbol_name1
    global symbol_name2
    global winplayer_X
    global winplayer_O
    symbol_name1=input()
    if symbol_name1=="X":
        winplayer_X=player1
        winplayer_O=player2
        symbol_name2="O"
    else:
        symbol_name2="X"
        winplayer_O=player1
        winplayer_X=player2
        
def mark():
    print("\nInput as Ex- 1 2   [***here 1 2 represents the co-ordinates***]\n")
    co=list(map(int,input().split()))
    i=co[0]
    j=co[1]
    global symbol_name1
    global symbol_name2
    global chance
    if board[i][j]==symbol_name1 or board[i][j]==symbol_name2:
        print("You can't overwrite a block: Disqualified")
        exit()
    else:
        if chance%2==0:
            board[i][j]=symbol_name2
        else:
            board[i][j]=symbol_name1
        
def firstTurn():
        print("\n%s you are PLAYER 1"%(player1))
        
def wincheck_x():
    global winplayer_X
    if board[0][0]=="X" and board[0][1]=="X" and board[0][2]=="X":
        print("%s wins" %(winplayer_X))
        playagain()
    elif board[0][2]=="X" and board[1][2]=="X" and board[2][2]=="X":
        print("%s wins" %(winplayer_X))
        playagain()
    elif board[2][0]=="X" and board[2][1]=="X" and board[2][2]=="X":
        print("%s wins" %(winplayer_X))
        playagain()
    elif board[0][0]=="X" and board[1][0]=="X" and board[2][0]=="X":
        print("%s wins" %(winplayer_X))
        playagain()
    elif board[1][0]=="X" and board[1][1]=="X" and board[1][2]=="X":
        print("%s wins" %(winplayer_X))
        playagain()
    elif board[0][1]=="X" and board[1][1]=="X" and board[2][1]=="X":
        print("%s wins" %(winplayer_X))
        playagain()
    elif board[0][0]=="X" and board[1][1]=="X" and board[2][2]=="X":
        print("%s wins" %(winplayer_X))
        playagain()
    elif board[0][2]=="X" and board[1][1]=="X" and board[2][0]=="X":
        print("%s wins" %(winplayer_X))
        playagain()
    else:
        pass
    
def wincheck_o():
    global winplayer_O
    if board[0][0]=="O" and board[0][1]=="O" and board[0][2]=="O":
        print("%s wins" %(winplayer_O))
        playagain()
    elif board[0][2]=="O" and board[1][2]=="O" and board[2][2]=="O":
        print("%s wins" %(winplayer_O))
        playagain()
    elif board[2][0]=="O" and board[2][1]=="O" and board[2][2]=="O":
        print("%s wins" %(winplayer_O))
        playagain()
    elif board[0][0]=="O" and board[1][0]=="O" and board[2][0]=="O":
        print("%s wins" %(winplayer_O))
        playagain()
    elif board[1][0]=="O" and board[1][1]=="O" and board[1][2]=="O":
        print("%s wins" %(winplayer_O))
        playagain()
    elif board[0][1]=="O" and board[1][1]=="O" and board[2][1]=="O":
        print("%s wins" %(winplayer_O))
        playagain()
    elif board[0][0]=="O" and board[1][1]=="O" and board[2][2]=="O":
        print("%s wins" %(winplayer_O))
        playagain()
    elif board[0][2]=="O" and board[1][1]=="O" and board[2][0]=="O":
        print("%s wins" %(winplayer_O))
        playagain()
    else:
        pass
    
def p1():
    print("\n\nPLAYER 1 your turn")
    global chance
    chance+=1
    
def p2():
    global chance
    print("\n\nPLAYER 2 your turn")
    chance+=1
def playagain():
    print("\n\n\n\n Wanna play again?     [**type YES or NO**]\n\n")
    again=input()
    if again=="yes" or again=="YES" or again=="Yes":
        global board
        board=[[" " for i in range(3)] for j in range(3)]
        gameStart()
    elif again=="no" or again=="NO" or again=="No":
        exit()
    


def gameStart():
    print("\n\n\n-------------Welcome to the game of Tic-Tac-Toe-------------")
    details()
    firstTurn()
    symbolCheck()
    board_show()
    while True :
        p1()
        mark()
        board_show()
        if wincheck_x()==True or wincheck_o()==True:
            break
        p2()
        mark()
        board_show()
        if wincheck_x()==True or wincheck_o()==True:
            break
        if chance>=8:
            print("THE MATCH IS A DRAW")
            playagain()

'''-------------------------functions end here---------------------------'''




'''-------------------------commands------------------------------------'''
print("\n\n\n\n Wanna play?            [**TYPE YES or NO**]\n\n\n")
ques=input()
while True:
    if ques=="yes" or ques=="YES" or ques=="Yes":
        gameStart()
    elif ques=="no" or ques=="NO" or ques=="No":
        exit()
    else:
        continue
        
'''--------------------------commands end here---------------------------'''


    
    

    
    
    
