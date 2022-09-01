Souvik = {
    'name': 'Souvik Maji',
    'age': 23,
    'stream': 'CSE'
}
Soumya = {
    'name':'Soumya Maji',
    'age':28,
    'stream':'CE'
}

db={}
db['Souvik']=Souvik
db['Soumya']=Soumya

import pickle

d=pickle.dumps(db)

data=pickle.loads(d)
print(data)