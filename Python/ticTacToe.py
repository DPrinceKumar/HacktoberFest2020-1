def pattern_not_formed(Player, Letter):
    '''Code to check winning condition
       Takes player and player character as input '''
    match = True
    for i in [0,3,6]:
        if a[i] == Letter and a[i+1] == Letter and a[i+2] == Letter:
            match = False
    for i in range(3):
        if a[i] == Letter and a[i+3] == Letter and a[i+6] == Letter:
            match = False
    if a[0] == Letter and a[4] == Letter and a[8] == Letter:
            match = False
    if a[2] == Letter and a[4] == Letter and a[6] == Letter:
        match = False
    if match == False :
        print(f"{Player} has won !!!/n Congratulations")
    return match

def run():
    ''' code to check stopping condition'''
    if not(free_space() and (pattern_not_formed("player 1", "X") and pattern_not_formed("player 2","O"))):
        if not(free_space()) and (pattern_not_formed("player 1", "X") and pattern_not_formed("player 2","O")):
            print("Tie between players")
        return False
    else:
        return True

def free_space():
    ''' Code to check if all spaces are occupied'''
    check = True
    for i in range(len(a)):
        if a[i] != ' ':
            check = False
        elif a[i] == ' ':
            check = True
            break
    return check

def occupancy(n):
    '''Code to check whether the given position is already occupied
       Takes the box number as input'''
    if a[n-1] != ' ':
        i = int(input("Position Occupied, Enter another number"))
        occupancy(i)
    else:
        return n

def matrix_print():
    '''TO print result after every turn'''
    for i in [0,3,6]:
        print(f'{a[i]} | {a[i+1]} | {a[i+2]}')

def matrix_input(player_ch):
    '''TO input box number
       Takes the player charater as input'''
    n= int(input("Enter the box number \n"))
    n = occupancy(n)
    a[n-1] = player_ch
    matrix_print()

def player_1():
    print("Player1 turn:")
    matrix_input('X')
    return

def player_2():
    print("Player2 turn:")
    matrix_input('O')
    return

def console():
    ''' Main function that handles essential calling of functions'''
    player_1()
    player_2()
    while(run()):
        player_1()
        if run() == True:
            player_2()
        else:
            break

print("Welcome to TIC TAC TOE")
ch=1
while ch != 2:
    print("=====================================================")
    ch = int(input('Enter 1 To play \nEnter 2 to exit \n'))
    print("=====================================================")
    if ch == 1:
        print("Sample Number Box:")
        print("1 | 2 | 3\n---------\n4 | 5 | 6\n---------\n7 | 8 | 9")
        print("=====================================================")
        print("Player 1 has X")
        print("Player 2 has O")
        print('=====================================================')
        a = [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']
        console()
    elif ch==2:
        print("Thank You!!  :)")
