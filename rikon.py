def create_bank(key,val):
    bank={'Souvik':10000,'Rikon':15000,'Soumya':20000,'Riya':8000,'Nilesh':12000}
    if type(key)==str:
        name=key.strip()
    if(val==None):
        return bank
    if name in bank:
        bank[name]+=val
    else:
        bank[name]=val
    return bank

def Valid(password):
    if (any(x.isupper() for x in password) and any(x.islower() for x in password) and any(x.isdigit() for x in password) and len(password) >= 8):
        return True
    else:
        return False

def signup(user_accounts, log_in, username, password):
    if Valid(password) and (username in user_accounts) and username!=password:
        return True
    else:
        return False
    
def login(user_accounts, log_in, username, password):
    if (username not in user_accounts) and not Valid(password):
        return False
    else:
        log_in[username]=True
        return True

def import_and_create_accounts(username,password):
    accounts={}
    login={}
    password=password.strip()
    if signup(accounts,login,username,password):
        accounts[username]=password
        login[username]=True
    return accounts,login

def update(dictionary, log_in, username, amount):
    if log_in[username]:
        dictionary[username]=amount
    elif username not in dictionary:
        dictionary[username]=amount
    else:
        return True



if __name__=="__main__":
    name=input()
    val=int(input())
    dictionary = create_bank(name,val)
    print(dictionary)

    username=input()
    password=input()
    accnts=import_and_create_accounts(username,password)
    if not bool(accnts):
        print("Empty")
    else:
        print(accnts)