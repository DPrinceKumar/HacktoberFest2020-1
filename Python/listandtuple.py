def ListandTuple():
  l = []#This is a empty list (mutable)
  t = ()#This is a empty tuple (its not mutable)
  #now we are taking input from user and adding that input to list and tuples(as we know tuple is not mutable so we are converting that list into tuple by typecasting)
  print("Please Enter Element of list like ex. 1 23 4 5 ")
  user = list(map(int,input()))
  print(user)#This will print list of entered element
  print(tuple(user))#This will print tuple 
ListandTuple()#Calling above function
