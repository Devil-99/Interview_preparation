class Computer:
    def __init__(self,name):    # Parameterised Constructor
        self.name=name

    def about(self):
        print("It is a",self.name,"Laptop")

comp = Computer("Macbook pro")       # Create object
# Computer.about(comp)    # Calling about() method. The value passed for the argument "self" is the object name.
# com2.about()            # Here the object name is been passed automatically.


# Example of Single Inheritance
class Configuration(Computer):      # This is the child class of Computer class.So it consists of all the characteristics of the parent
    def __init__(self,name,price):
        # Computer.name=name        # we can access parent variable through this.
        super(Configuration,self).__init__(name)        # or through this.
        self.price=price

    def config(self):
        print(self.name,"consists of intel core i5 8th gen processor with 8gb RAM and 1TB HardDrive")

    def cost(self):
        print("The price is",self.price)

obj=Configuration("Acer Predator",46000)
obj.about()
obj.config()
obj.cost()


# protected members
_computer_name = "Predator"     # start with a single underscore prefix
# privtae members
__company_name = "Acer"         # start with a double underscore prefix
