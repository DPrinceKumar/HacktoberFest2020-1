import re
def check_Email(email):
    if re.match('^([a-zA-Z-0-9_\-\.]+)@([a-zA-Z-0-9_\-\.]+)\.([a-zA-Z]{2,5})$',email):
        return 'Valid Email'
    else:
        return 'Invalid Email'
string=input('Enter Your String: ')
print(check_Email(string))
