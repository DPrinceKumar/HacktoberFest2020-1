
#1st Assignment by Qausain Manzoor

print("Addition")
a = int(input("Enter 1st number "))
b = int(input("Enter 2nd number "))
print(a + b)

print("Multiplication")
a = int(input("Enter 1st number "))
b = int(input("Enter 2nd number "))
print(a * b)

print("Subtraction")
a = int(input("Enter 1st number "))
b = int(input("Enter 2nd number "))
print(a - b)

print("Division")
a = int(input("Enter 1st number "))
b = int(input("Enter 2nd number "))
print(a / b)


from tkinter import *


window = Tk()
window.geometry("360x610")
window.config(bg="grey")
window.title("Calculator")
window.wm_iconbitmap("calculator.ico")
window.resizable(0, 0)


# functions
def click(event):
    global value
    calc = event.widget.cget("text")
    if calc == "=":
        if value.get().isdigit():
            calculation = int(value.get())

        else:
            try:
                calculation = eval(text.get())

            except Exception as e:
                print(e)
                calculation = "Error!"

        value.set(calculation)
        text.update()

    elif calc == "C":
        value.set("")
        text.update()

    elif calc == "Del":
        value.set(value.get()[:-1])
        text.update()

    else:
        value.set(value.get()+calc)
        text.update()


value = StringVar()
value.set("")

# textarea
text = Entry(textvar=value, width=10, bg="cyan", font="None 40")
text.pack(pady=5)

# key_area
# edits
f = Frame(window, bg="grey", pady=5)

b = Button(f, text="C", font="old_english 36", padx=5)
b.pack(side=LEFT, padx=5)
b.bind("<Button-1>", click)

b = Button(f, text="Del", font="old_english 26", pady=15)
b.pack(side=LEFT, padx=5)
b.bind("<Button-1>", click)


# numbers

f1 = Frame(window, bg="grey", padx=10, pady=5)
for i in range(1, 4):

    b = Button(f1, text=str(i), font="old_english 36")
    b.pack(side=LEFT)
    b.bind("<Button-1>", click)

f2 = Frame(window, bg="grey", padx=10, pady=5)
for i in range(4, 7):

    b = Button(f2, text=str(i), font="old_english 36")
    b.pack(side=LEFT)
    b.bind("<Button-1>", click)

f3 = Frame(window, bg="grey", padx=10, pady=5)
for i in range(7, 10):

    b = Button(f3, text=str(i), font="old_english 36")
    b.pack(side=LEFT)
    b.bind("<Button-1>", click)

f4 = Frame(window, bg="grey", padx=10, pady=5)
b = Button(f4, text="0", font="old_english 36")
b.pack(side=LEFT)
b.bind("<Button-1>", click)

b = Button(f4, text="00", font="old_english 26", pady=14)
b.pack(side=LEFT)
b.bind("<Button-1>", click)

# operators

b = Button(f4, text="=", font="old_english 36")
b.pack(side=LEFT)
b.bind("<Button-1>", click)

b = Button(f1, text="*", font="old_english 36")
b.pack(side=LEFT, padx=5)
b.bind("<Button-1>", click)

b = Button(f2, text="/", font="old_english 36", padx=3)
b.pack(side=LEFT, padx=5)
b.bind("<Button-1>", click)

b = Button(f3, text="-", font="old_english 36")
b.pack(side=LEFT, padx=5)
b.bind("<Button-1>", click)

b = Button(f4, text="+", font="old_english 30", pady=9)
b.pack(side=LEFT, padx=5)
b.bind("<Button-1>", click)

b = Button(f, text="%", font="old_english 36")
b.pack(side=LEFT, padx=5)
b.bind("<Button-1>", click)


f.pack()
f1.pack()
f2.pack()
f3.pack()
f4.pack()

window.mainloop()
=======
from kivy.uix.button import Button
from kivy.uix.label import Label
from kivy.uix.scrollview import ScrollView

from kivy.uix.boxlayout import BoxLayout
from kivy.uix.gridlayout import GridLayout

from kivy.config import Config
Config.set('graphics', 'resizable', 0)
Config.set('graphics', 'width', 400)
Config.set('graphics', 'height', 500)

class MainApp(App):
	font_size = 75
	
	def add_simvol(self, instance):
		text = self.label.text
		if len(text) <= 25:
			text = text + instance.text
			self.label.text = text
		
	def check_char(self, instance):
		text = self.label.text
		if text != "":
			if len(text) <= 25:
				if text[-1] in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]:
					self.label.text = self.label.text + instance.text
	
	def return_result(self, instance):
		if self.label.text != "":
			try:
				text = self.label.text
				if "×" in text:
					text = text.replace("×", "*")
				if "÷" in text:
					text = text.replace("÷", "/")
				if "^" in text:
					text = text.replace("^", "**")
				if "√" in text:
					text = text.replace("√", "**(1/2)")
					
				text = eval(text)
				self.label.text = str(text)
			except Exception:
				pass
				self.label.text = "Error"
		
	def clean(self, instance):
		self.label.text = ""
		
	def del_last_simvol(self, instance):
		text = self.label.text
		self.label.text = text[:-1]
	
	def build(self):
		
		main = BoxLayout(orientation = 'vertical')
		
		######Control##########
		control = GridLayout(cols = 4, 
		size_hint = [1, .2])
		
		control.add_widget(Button(text = "C", 
		font_size = self.font_size,
		on_press = self.clean))
		
		control.add_widget(Button(text = "<×", 
		font_size = self.font_size,
		on_press = self.del_last_simvol))
		
		control.add_widget(Button(text = "√", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		control.add_widget(Button(text = "^", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		
		panel = BoxLayout(orientation = 'horizontal')
		
		####Keyboard#########
		keyboard = GridLayout(cols = 3, size_hint = [.6, 1],)
		
		keyboard.add_widget(Button(
		text = "7", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "8", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "9", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "4", 
		font_size = self.font_size,
		on_press = self.add_simvol))	
			
		keyboard.add_widget(Button(
		text = "5", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "6", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		
		keyboard.add_widget(Button(
		text = "1", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "2",
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = "3", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		keyboard.add_widget(Button(
		text = ".", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		keyboard.add_widget(Button(
		text = "0", 
		font_size = self.font_size,
		on_press = self.add_simvol
		))
		
		keyboard.add_widget(Button(
		text = "=", 
		font_size = self.font_size,
		on_press = self.return_result))
		
		#####Math operation######
		math = GridLayout(cols = 1, size_hint = [.2, 1],)
		
		math.add_widget(Button(
		text = "÷", 
		font_size = self.font_size,
		on_press = self.check_char
		))
		
		math.add_widget(Button(
		text = "×", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		math.add_widget(Button(
		text = "-", 
		font_size = self.font_size,
		on_press = self.add_simvol))
		
		math.add_widget(Button(
		text = "+", 
		font_size = self.font_size,
		on_press = self.check_char))
		
		panel.add_widget(keyboard)
		panel.add_widget(math)
		
		display = ScrollView(size_hint_y = .3, do_scroll = True)
		self.label = Label(text = "", 
		font_size = 70,
		size_hint_y = 1)
		
		display.add_widget(self.label)
		
		main.add_widget(display)
		main.add_widget(control)
		main.add_widget(panel)
		return main
		
if __name__ == '__main__':
	MainApp().run()

