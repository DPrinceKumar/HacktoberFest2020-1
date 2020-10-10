"""CONVENTIONS:
positions are done row-column from the bottom left and are both numbers. This corresponds to the alpha-number system in traditional chess while being computationally useful. they are specified as tuples
"""
import itertools
WHITE = "white"
BLACK = "black"







class Game:
    #ive decided since the number of pieces is capped but the type of pieces is not (pawn transformations), I've already coded much of the modularity to support just using a dictionary of pieces
    def __init__(self):
        self.playersturn = BLACK
        self.message = "this is where prompts will go"
        self.gameboard = {}
        self.placePieces()
        print("chess program. enter moves in algebraic notation separated by space")
        self.main()

        
    def placePieces(self):

        for i in range(0,8):
            self.gameboard[(i,1)] = Pawn(WHITE,uniDict[WHITE][Pawn],1)
            self.gameboard[(i,6)] = Pawn(BLACK,uniDict[BLACK][Pawn],-1)
            
        placers = [Rook,Knight,Bishop,Queen,King,Bishop,Knight,Rook]
        
        for i in range(0,8):
            self.gameboard[(i,0)] = placers[i](WHITE,uniDict[WHITE][placers[i]])
            self.gameboard[((7-i),7)] = placers[i](BLACK,uniDict[BLACK][placers[i]])
        placers.reverse()

        
    def main(self):
        
        while True:
            self.printBoard()
            print(self.message)
            self.message = ""
            startpos,endpos = self.parseInput()
            try:
                target = self.gameboard[startpos]
            except:
                self.message = "could not find piece; index probably out of range"
                target = None
                
            if target:
                print("found "+str(target))
                if target.Color != self.playersturn:
                    self.message = "you aren't allowed to move that piece this turn"
                    continue
                if target.isValid(startpos,endpos,target.Color,self.gameboard):
                    self.message = "that is a valid move"
                    self.gameboard[endpos] = self.gameboard[startpos]
                    del self.gameboard[startpos]
                    self.isCheck()
                    if self.playersturn == BLACK:
                        self.playersturn = WHITE
                    else : self.playersturn = BLACK
                else : 
                    self.message = "invalid move" + str(target.availableMoves(startpos[0],startpos[1],self.gameboard))
                    print(target.availableMoves(startpos[0],startpos[1],self.gameboard))
            else : self.message = "there is no piece in that space"
                    
    def isCheck(self):
        #ascertain where the kings are, check all pieces of opposing color against those kings, then if either get hit, check if its checkmate
        king = King
        kingDict = {}
        pieceDict = {BLACK : [], WHITE : []}
        for position,piece in self.gameboard.items():
            if type(piece) == King:
                kingDict[piece.Color] = position
            print(piece)
            pieceDict[piece.Color].append((piece,position))
        #white
        if self.canSeeKing(kingDict[WHITE],pieceDict[BLACK]):
            self.message = "White player is in check"
        if self.canSeeKing(kingDict[BLACK],pieceDict[WHITE]):
            self.message = "Black player is in check"
        
        
    def canSeeKing(self,kingpos,piecelist):
        #checks if any pieces in piece list (which is an array of (piece,position) tuples) can see the king in kingpos
        for piece,position in piecelist:
            if piece.isValid(position,kingpos,piece.Color,self.gameboard):
                return True
                
    def parseInput(self):
        try:
            a,b = input().split()
            a = ((ord(a[0])-97), int(a[1])-1)
            b = (ord(b[0])-97, int(b[1])-1)
            print(a,b)
            return (a,b)
        except:
            print("error decoding input. please try again")
            return((-1,-1),(-1,-1))
    
    """def validateInput(self, *kargs):
        for arg in kargs:
            if type(arg[0]) is not type(1) or type(arg[1]) is not type(1):
                return False
        return True"""
        
    def printBoard(self):
        print("  1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |")
        for i in range(0,8):
            print("-"*32)
            print(chr(i+97),end="|")
            for j in range(0,8):
                item = self.gameboard.get((i,j)," ")
                print(str(item)+' |', end = " ")
            print()
        print("-"*32)
            
           
        
    """game class. contains the following members and methods:
    two arrays of pieces for each player
    8x8 piece array with references to these pieces
    a parse function, which turns the input from the user into a list of two tuples denoting start and end points
    a checkmateExists function which checks if either players are in checkmate
    a checkExists function which checks if either players are in check (woah, I just got that nonsequitur)
    a main loop, which takes input, runs it through the parser, asks the piece if the move is valid, and moves the piece if it is. if the move conflicts with another piece, that piece is removed. ischeck(mate) is run, and if there is a checkmate, the game prints a message as to who wins
    """

class Piece:
    
    def __init__(self,color,name):
        self.name = name
        self.position = None
        self.Color = color
    def isValid(self,startpos,endpos,Color,gameboard):
        if endpos in self.availableMoves(startpos[0],startpos[1],gameboard, Color = Color):
            return True
        return False
    def __repr__(self):
        return self.name
    
    def __str__(self):
        return self.name
    
    def availableMoves(self,x,y,gameboard):
        print("ERROR: no movement for base class")
        
    def AdNauseum(self,x,y,gameboard, Color, intervals):
        """repeats the given interval until another piece is run into. 
        if that piece is not of the same color, that square is added and
         then the list is returned"""
        answers = []
        for xint,yint in intervals:
            xtemp,ytemp = x+xint,y+yint
            while self.isInBounds(xtemp,ytemp):
                #print(str((xtemp,ytemp))+"is in bounds")
                
                target = gameboard.get((xtemp,ytemp),None)
                if target is None: answers.append((xtemp,ytemp))
                elif target.Color != Color: 
                    answers.append((xtemp,ytemp))
                    break
                else:
                    break
                
                xtemp,ytemp = xtemp + xint,ytemp + yint
        return answers
                
    def isInBounds(self,x,y):
        "checks if a position is on the board"
        if x >= 0 and x < 8 and y >= 0 and y < 8:
            return True
        return False
    
    def noConflict(self,gameboard,initialColor,x,y):
        "checks if a single position poses no conflict to the rules of chess"
        if self.isInBounds(x,y) and (((x,y) not in gameboard) or gameboard[(x,y)].Color != initialColor) : return True
        return False
        
        
chessCardinals = [(1,0),(0,1),(-1,0),(0,-1)]
chessDiagonals = [(1,1),(-1,1),(1,-1),(-1,-1)]

def knightList(x,y,int1,int2):
    """sepcifically for the rook, permutes the values needed around a position for noConflict tests"""
    return [(x+int1,y+int2),(x-int1,y+int2),(x+int1,y-int2),(x-int1,y-int2),(x+int2,y+int1),(x-int2,y+int1),(x+int2,y-int1),(x-int2,y-int1)]
def kingList(x,y):
    return [(x+1,y),(x+1,y+1),(x+1,y-1),(x,y+1),(x,y-1),(x-1,y),(x-1,y+1),(x-1,y-1)]



class Knight(Piece):
    def availableMoves(self,x,y,gameboard, Color = None):
        if Color is None : Color = self.Color
        return [(xx,yy) for xx,yy in knightList(x,y,2,1) if self.noConflict(gameboard, Color, xx, yy)]
        
class Rook(Piece):
    def availableMoves(self,x,y,gameboard ,Color = None):
        if Color is None : Color = self.Color
        return self.AdNauseum(x, y, gameboard, Color, chessCardinals)
        
class Bishop(Piece):
    def availableMoves(self,x,y,gameboard, Color = None):
        if Color is None : Color = self.Color
        return self.AdNauseum(x, y, gameboard, Color, chessDiagonals)
        
class Queen(Piece):
    def availableMoves(self,x,y,gameboard, Color = None):
        if Color is None : Color = self.Color
        return self.AdNauseum(x, y, gameboard, Color, chessCardinals+chessDiagonals)
        
class King(Piece):
    def availableMoves(self,x,y,gameboard, Color = None):
        if Color is None : Color = self.Color
        return [(xx,yy) for xx,yy in kingList(x,y) if self.noConflict(gameboard, Color, xx, yy)]
        
class Pawn(Piece):
    def __init__(self,color,name,direction):
        self.name = name
        self.Color = color
        #of course, the smallest piece is the hardest to code. direction should be either 1 or -1, should be -1 if the pawn is traveling "backwards"
        self.direction = direction
    def availableMoves(self,x,y,gameboard, Color = None):
        if Color is None : Color = self.Color
        answers = []
        if (x+1,y+self.direction) in gameboard and self.noConflict(gameboard, Color, x+1, y+self.direction) : answers.append((x+1,y+self.direction))
        if (x-1,y+self.direction) in gameboard and self.noConflict(gameboard, Color, x-1, y+self.direction) : answers.append((x-1,y+self.direction))
        if (x,y+self.direction) not in gameboard and Color == self.Color : answers.append((x,y+self.direction))# the condition after the and is to make sure the non-capturing movement (the only fucking one in the game) is not used in the calculation of checkmate
        return answers

uniDict = {WHITE : {Pawn : "♙", Rook : "♖", Knight : "♘", Bishop : "♗", King : "♔", Queen : "♕" }, BLACK : {Pawn : "♟", Rook : "♜", Knight : "♞", Bishop : "♝", King : "♚", Queen : "♛" }}
        

        


Game()
@d3mon1231
d3mon1231 commented on Nov 24, 2017
pawn can moves two forward from their starting place. I dont think yours can

@MichaelGitHubHype
MichaelGitHubHype commented on Dec 8, 2017
Seems to always return error with input for me
You should probably make clearer instructions

@Kwame0
Kwame0 commented on May 4, 2018
why dont u guys just code it urselves if ur having problems lmao

@Menocha
Menocha commented on Aug 13, 2018
hey! I'm gonna try it. Any recommendations?

@ChessMast
ChessMast commented on Dec 6, 2018
The following are the issues that I found:
Boards sideways instead of up and down
Black and white are on the wrong side of the board
The white king and queen are in the wrong positions
It doesn't recognize checkmate
It lets you take into check
Pawns only move one square
No en passant
No castling
Crashes when you capture king
Not proper notation

@Shadowking1235
Shadowking1235 commented on Mar 8, 2019
Very educative, Thanks for the upload...

@JayTesla
JayTesla commented on Mar 8, 2019
This program run which complier

@Julius2005
Julius2005 commented on Mar 26, 2019
hi, i really like your chess program, but i have can not figure out how to move the pieces. I am trying to type e4 but it dont work, i have also tried e2 e4 but it doesnt work. Can you please tell me how the moving works?

@TheRealKinglogic
TheRealKinglogic commented on Mar 31, 2019
hi, i really like your chess program, but i have can not figure out how to move the pieces. I am trying to type e4 but it dont work, i have also tried e2 e4 but it doesnt work. Can you please tell me how the moving works?

Me too

@inigmati
inigmati commented on Apr 5, 2019
Start as a white player i.e. e7 e6

@mikelittle88
mikelittle88 commented on May 17, 2019
also its not put for first moving pawns to go 2 spaces

@martin5852
martin5852 commented on Aug 6, 2019
very exactly

@mcwaffles2003
mcwaffles2003 commented on Nov 1, 2019
"why dont u guys just code it urselves if ur having problems lmao"
I came ere to learn how to but how can I dissect code if I cant even interact with it to see how its working (if it even does)

@Ogrone
Ogrone commented on Nov 28, 2019
hi, i really like your chess program, but i have can not figure out how to move the pieces. I am trying to type e4 but it dont work, i have also tried e2 e4 but it doesnt work. Can you please tell me how the moving works?

Me too

i have the same problem

@rishisankhla
rishisankhla commented on Feb 22
hi, i really like your chess program, but i have can not figure out how to move the pieces. I am trying to type e4 but it dont work, i have also tried e2 e4 but it doesnt work. Can you please tell me how the moving works?

@ManzhouYang
ManzhouYang commented on Jun 23
I can't promote my pawn to a queen

@NicholasSager55
NicholasSager55 commented on Jul 6 • 
If you are having difficulties with the other code, I improved it with some minor fixes. If you want to know how to move your pieces, type a2-a4 as an example. Make sure to copy all of the code after this text:

"""CONVENTIONS:
positions are done row-column from the bottom left and are both numbers.
This corresponds to the alpha-number system in traditional chess while being computationally useful.
They are specified as tuples
"""
import itertools
import copy
import inspect
WHITE = "white"
BLACK = "black"
gameboard = None

def canSeeKing(kingpos,piecelist, overridegameboard = None):
global gameboard
overridegameboard = overridegameboard or gameboard
for piece,position in piecelist:
if piece.isValid(position,kingpos,piece.Color,overridegameboard):
return True

def isCheck(overridegameboard = None):
global gameboard
#ascertain where the kings are, check all pieces of opposing color against those kings,
# then if either get hit, check if its checkmate
overridegameboard = overridegameboard or gameboard
king = King
kingDict = {}
pieceDict = {BLACK : [], WHITE : []}
for position,piece in overridegameboard.items():
if type(piece) == king:
kingDict[piece.Color] = position
print(piece)
pieceDict[piece.Color].append((piece,position))
#white
if canSeeKing(kingDict[WHITE],pieceDict[BLACK], overridegameboard):
return WHITE
if canSeeKing(kingDict[BLACK],pieceDict[WHITE], overridegameboard):
return BLACK
return False

class Game:
def init(self):
global gameboard
self.playersturn = WHITE
self.message = "Input Your Move"
gameboard = self.gameboard = {}
self.placePieces()
print("Chess program. Enter moves in algebraic notation separated by space. Example: a2-a4")
self.main()

def placePieces(self):

    for i in range(0,8):
        self.gameboard[(i,1)] = Pawn(WHITE,uniDict[WHITE][Pawn],1)
        self.gameboard[(i,6)] = Pawn(BLACK,uniDict[BLACK][Pawn],-1)
        
    placers = [Rook, Knight, Bishop, Queen, King, Bishop, Knight, Rook]
    
    for i in range(0,8):
        self.gameboard[(i,0)] = placers[i](WHITE,uniDict[WHITE][placers[i]])
        self.gameboard[((7-i),7)] = placers[i](BLACK,uniDict[BLACK][placers[i]])
    placers.reverse()

    
def main(self):
    
    while True:
        self.printBoard()
        print(self.message)
        self.message = ""
        startpos,endpos = self.parseInput()
        try:
            target = self.gameboard[startpos]
        except:
            self.message = "could not find piece; index probably out of range"
            target = None
            
        if target:
            print("found "+str(target))
            if target.Color != self.playersturn:
                self.message = "This is Not Your Turn"
                continue
            if target.isValid(startpos,endpos,target.Color,self.gameboard):
                hasLegalMoves = False
                for position in self.gameboard:
                    piece = self.gameboard[position]
                    if (piece.Color == self.playersturn):
                        for move in piece.availableMoves(position[0], position[1], self.gameboard):
                            overridegameboard = copy.deepcopy(self.gameboard)
                            overridegameboard[move] = self.gameboard[position]
                            del overridegameboard[position]
                            if (isCheck(overridegameboard) != self.playersturn):
                                hasLegalMoves = True
                                break
                if (not hasLegalMoves):
                    if (isCheck() == self.playersturn) : print("You are in checkmate. " + ({WHITE: BLACK, BLACK: WHITE})[self.playersturn] + " wins!")
                    else : print("Stalemate. Nobody wins!")
                    return
                overridegameboard = copy.deepcopy(self.gameboard)
                overridegameboard[endpos] = self.gameboard[startpos]
                del overridegameboard[startpos]
                if (isCheck(overridegameboard) == self.playersturn) : self.message = "You are not allowed to put yourself in check!"
                else:
                    self.message = "That Move is Allowed"
                    self.gameboard[endpos] = self.gameboard[startpos]
                    del self.gameboard[startpos]
                    Check = isCheck()
                    if (Check):
                        self.message = "Player is in check"
                    if self.playersturn == BLACK:
                        self.playersturn = WHITE
                    else : self.playersturn = BLACK
            else : 
                self.message = "invalid move" + str(target.availableMoves(startpos[0],startpos[1],self.gameboard))
                print(target.availableMoves(startpos[0],startpos[1],self.gameboard))
        else : self.message = "There is no Piece in That Space"
            
def parseInput(self):
    try:
        a,b = input().split('-')
        a = ((ord(a[0])-97), int(a[1])-1)
        b = (ord(b[0])-97, int(b[1])-1)
        print(a,b)
        return (a,b)
    except:
        print("error decoding input. please try again")
        return((-1,-1),(-1,-1))

"""def validateInput(self, *kargs):
    for arg in kargs:
        if type(arg[0]) is not type(1) or type(arg[1]) is not type(1):
            return False
    return True"""
    
def printBoard(self):
    print("  1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |")
    for i in range(0,8):
        print("-"*32)
        print(chr(i+97),end="|")
        for j in range(0,8):
            item = self.gameboard.get((i,j)," ")
            print(str(item)+' |', end = " ")
        print()
    print("-"*32)
        
       
    
"""game class. contains the following members and methods:
two arrays of pieces for each player
8x8 piece array with references to these pieces
a parse function, which turns the input from the user into a list of two tuples denoting start and end points
a checkmateExists function which checks if either players are in checkmate
a checkExists function which checks if either players are in check
a main loop, which takes input, runs it through the parser, asks the piece if the move is valid, 
and moves the piece if it is.
If the move conflicts with another piece, that piece is removed. is check(mate) is run,
and if there is a checkmate, the game prints a message as to who wins.
"""
class Piece:

def __init__(self,color,name):
    self.name = name
    self.position = None
    self.Color = color
def isValid(self,startpos,endpos,Color,gameboard):
    if endpos in self.availableMoves(startpos[0],startpos[1],gameboard,Color):
        return True
    return False
def __repr__(self):
    return self.name

def __str__(self):
    return self.name

def availableMoves(self,x,y,gameboard,Color=None):
    print("ERROR: no movement for base class")
    
def AdNauseum(self,x,y,gameboard, Color, intervals):
    """Repeats the given interval until another piece is run into. 
    if that piece is not of the same color, that square is added and
     then the list is returned"""
    answers = []
    for xint,yint in intervals:
        xtemp,ytemp = x+xint,y+yint
        while self.noConflict(gameboard, Color, xtemp, ytemp):
            #print(str((xtemp,ytemp))+"is in bounds")
            
            target = gameboard.get((xtemp,ytemp),None)
            if target is None: answers.append((xtemp,ytemp))
            elif target.Color != Color: 
                answers.append((xtemp,ytemp))
                break
            else:
                break
            
            xtemp,ytemp = xtemp + xint,ytemp + yint
    return answers
            
def isInBounds(self,x,y):
    "Checks if a position is on the board"
    if x >= 0 and x < 8 and y >= 0 and y < 8:
        return True
    return False

def noConflict(self,gameboard,initialColor,x,y):
    "Checks if a single position poses no conflict to the rules of chess"
    if self.isInBounds(x,y) and (((x,y) not in gameboard) or gameboard[(x,y)].Color != initialColor) : return True
    return False
chessCardinals = [(1,0),(0,1),(-1,0),(0,-1)]
chessDiagonals = [(1,1),(-1,1),(1,-1),(-1,-1)]

def knightList(x,y,int1,int2):
"""Sepcifically for the rook, permutes the values needed around a position for noConflict tests"""
return [(x+int1,y+int2),(x-int1,y+int2),(x+int1,y-int2),(x-int1,y-int2),(x+int2,y+int1),(x-int2,y+int1),(x+int2,y-int1),(x-int2,y-int1)]
def kingList(x,y):
return [(x+1,y),(x+1,y+1),(x+1,y-1),(x,y+1),(x,y-1),(x-1,y),(x-1,y+1),(x-1,y-1)]

class Knight(Piece):
def availableMoves(self,x,y,gameboard, Color = None):
if Color is None : Color = self.Color
return [(xx,yy) for xx,yy in knightList(x,y,2,1) if self.noConflict(gameboard, Color, xx, yy)]

class Rook(Piece):
def availableMoves(self,x,y,gameboard ,Color = None):
if Color is None : Color = self.Color
return self.AdNauseum(x, y, gameboard, Color, chessCardinals)

class Bishop(Piece):
def availableMoves(self,x,y,gameboard, Color = None):
if Color is None : Color = self.Color
return self.AdNauseum(x, y, gameboard, Color, chessDiagonals)

class Queen(Piece):
def availableMoves(self,x,y,gameboard, Color = None):
if Color is None : Color = self.Color
return self.AdNauseum(x, y, gameboard, Color, chessCardinals+chessDiagonals)

class King(Piece):
def availableMoves(self,x,y,gameboard, Color = None):
if Color is None : Color = self.Color
return [(xx,yy) for xx,yy in kingList(x,y) if self.noConflict(gameboard, Color, xx, yy)]

class Pawn(Piece):
def init(self,color,name,direction):
self.name = name
self.Color = color
self.direction = direction
def availableMoves(self,x,y,gameboard, Color = None):
if Color is None : Color = self.Color
answers = []
if (x+1,y+self.direction) in gameboard and self.noConflict(gameboard, Color, x+1, y+self.direction) : answers.append((x+1,y+self.direction))
if (x-1,y+self.direction) in gameboard and self.noConflict(gameboard, Color, x-1, y+self.direction) : answers.append((x-1,y+self.direction))
if (x,y+self.direction) not in gameboard and Color == self.Color and self.noConflict(gameboard, Color, x, y+self.direction) : answers.append((x,y+self.direction))# the condition after the and is to make sure the non-0capturing movement is not used in the calculation of checkmate
if (x,y+self.direction2) not in gameboard and Color == self.Color and self.noConflict(gameboard, Color, x, y+self.direction2) : answers.append((x,y+self.direction*2))# the condition after the and is to make sure the non-0capturing movement is not used in the calculation of checkmate
return answers

uniDict = {WHITE : {Pawn : "♙", Rook : "♖", Knight : "♘", Bishop : "♗", King : "♔", Queen : "♕" }, BLACK : {Pawn : "♟", Rook : "♜", Knight : "♞", Bishop : "♝", King : "♚", Queen : "♛" }}

if (name == "main"):
input("Press the Enter Key to Exit")

Game()
