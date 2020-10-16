import smtplib, ssl

MAIL = input('Enter email you would like to use: ')
PASS = input('Enter password')

id= input('Enter id to which you want to send email:')
p = input('press no. of mails to send')

msg=f"\
        Subject:{(input('Enter subject:'))}\n\nDid you get spam mailed?"

context = ssl.create_default_context()
for i in range(1,int(input(p+1):
    s = smtplib.SMTP('smtp.gmail.com', 587)
    s.starttls(context= context)
    s.login(MAIL, PASS)
    try:
        s.sendmail("archimedesmailbot@gmail.com", id, msg)
        print(f'success')
    except:
        print(f'failed')
    s.quit()

def spam(id):
    s = smtplib.SMTP('smtp.gmail.com', 587)
    s.starttls(context= context)
    s.login(MAIL, PASS)
    for i in range(1, int(input('Bot sends in batches of 10, select no. of batches:'))+1):
        for j in range(1,11):
        try:
            s.sendmail("archimedesmailbot@gmail.com", id, msg)
            print(f'success #{i}.{j}')
        except:
            print(f'failed #{i}.{j}')
        s.quit()

