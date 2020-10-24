class MyError(BaseException):
    def __init__(self, value):
        self.value = value
        def __str__(self):
            return(repr(self.value))
try:
    l = int(input("Enter the number:"))
    if l<0:
        raise(MyError(l))
    else:
        print("No Error occures!!!")
except MyError as error:
    print('A New Exception occured value is less than zero: ',error.value)
