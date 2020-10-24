#Example of Classes in python
#Class Creation

class Auto():
    def __init__(self, color, model, make, engine):
        self.color = color
        self.model = model
        self.make = make
        self.engine = engine
  
    def run(self):
       print(f"{self.color} car is running")

    def stop(self):
       print(f"{self.color} car is stopped")

# Object creation
car1 = Auto("white", "2020", "Suzuki", "1000") # constructor/ initializer
car2 = Auto("silver", "2019", "Honda", "1300")
car3 = Auto("black", "2018", "Toyota", "1299")

# Calling objects
car1.run()
car1.stop()
car3.run()
car3.stop()
Auto.run(car1)
