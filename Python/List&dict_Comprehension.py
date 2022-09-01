list = [2,3,5,8,12]
list2 = [1,7,16]

# Performing mathematical operations on the entire list
squared_list = [x*x for x in list]

squared_dict = {x:x*x for x in list}

# Performing conditional filtering operations on the entire list
even_squared_list = [x*x for x in list if x%2==0]

even_squared_dict = {x:x*x for x in list if x%2==0}

# Combining multiple lists into one
added_list = [(x+y) for (x,y) in zip(list,list2)]
combined_list = [(x,y) for x in list for y in list2]

# Flattening a multi-dimensional list
matrix = [[1,2,3],[6,5,4]]
flattened_list = [x for temp in matrix for x in temp]

# Print
print(flattened_list)