class Computer:
    def __init__(self):         # Default Constructor
        self.name = "Acer Predator"

    def __init__(self,name):    # Parameterised Constructor
        self.name=name

    def config(self):
        print("It is a",self.name,"Laptop")

com1 = Computer()       # Create object
# com2 = Computer("Macbook pro")

Computer.config(com1)    # Calling specs method. The value passed for the argument "self" is the object.

# com2.config()            # Here the object name passed automatically.
