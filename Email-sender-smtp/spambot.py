import smtplib, ssl
def mail():
    print('....1- Send 1 mail to 1 recipient\n\
....2- Send 1 mail to multiple recipients.\n\
....3- Send multiple mails to 1 recipient.\n\
....4- Send multiple mails to multiple recipients\n\
....5- SPAM 1 person.\n\
....6- SPAM multiple people.\n\
....7- PING the MailBot')
    opt=int(input('Enter the Action you would like to perform:'))
    if opt==1:
        m1()
    elif opt==2:
        m2()
    elif opt==3:
        m3()
    elif opt==4:
        m4()
    elif opt==5:
        m5()
    elif opt==6:
        m6()
    elif opt==7:
        ping()
    else:
        print('ERROR!- Value entered isn\'t corresponding to menu options.')
mail()







msg=f"\
        Subject:{(input('Enter subject:'))}\n\nDid you get spam mailed?"
context = ssl.create_default_context()
id= input('Enter id to which you want to send email:')
for i in range(1,int(input('This program sends emails in batches of 10.\nEnter no. of batches:'))+1):
    s = smtplib.SMTP('smtp.gmail.com', 587)
    s.starttls(context= context)
    s.login("archimedesmailbot@gmail.com", "@rchimedes")
    for j in range(1,11):
        try: 
            s.sendmail("archimedesmailbot@gmail.com", id, msg)
            print(f'success #{i}.{j}')
        except:
            print(f'failed #{i}.{j}') 
    s.quit()

