import os
import csv
import sys
import easygui  # pip install before usage
from easygui import *
from tkinter import filedialog
from tkinter import *


if ccbox(msg="𝙏𝙝𝙞𝙨 𝙥𝙧𝙤𝙜𝙧𝙖𝙢 𝙩𝙖𝙠𝙚𝙨 𝙖 𝙣𝙖𝙢𝙚𝙡𝙞𝙨𝙩 𝙛𝙧𝙤𝙢 𝙖 𝘾𝙎𝙑 𝙛𝙞𝙡𝙚 𝙖𝙣𝙙 𝙧𝙚𝙣𝙖𝙢𝙚𝙨 𝙖 𝙛𝙤𝙡𝙙𝙚𝙧",title="Bulk file Rename",choices=("Start Renaming", "Cancel"),default_choice='Continue', cancel_choice='Cancel'):  # show a Continue/Cancel dialog
    pass  # user chose Continue
else:  # user chose Cancel
    sys.exit(0)

# csv file name
filename = easygui.fileopenbox(msg="Select a csv file, with 'Name' column", title="Open CSV file")
namelist = []

# getting file namelist
with open(filename, 'r') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        current = (row['Name'])     # replace field_name with your required field
        namelist.append(current)
    print(namelist)
namelist.sort()                     # sorts the namelist alphabetically


# folder path goes here
root = Tk()
root.withdraw()
path = filedialog.askdirectory()
folder = os.listdir(path)

# check if the namelist and the no of files match
if (len(namelist) > len(folder)):
    easygui.msgbox("No. of files in the folder is greater than the csv namelist.", title="No. of Files mismatched")
elif (len(namelist) < len(folder)):
    easygui.msgbox("No. of files in the folder is lesser than the csv namelist.", title="No. of Files mismatched")
else:
    pass

nextrow = 0
counter = 0
file_count = 0

for file in folder:
    try:
        os.rename(
            f"{path}\{file}",
            f"{path}\{namelist[nextrow]}.pdf")
        nextrow += 1
        file_count += 1

        # handles the fileExists error by appending a counter number
    except FileExistsError:
        os.rename(
            f"{path}\{file}",
            f"{path}\{namelist[nextrow]}_{counter}.pdf")
        counter += 1
        nextrow += 1
        file_count += 1

print(f"Successfully renamed {file_count} files.")
