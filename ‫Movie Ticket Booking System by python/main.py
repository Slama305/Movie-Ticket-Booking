import os
class Movie:
    def __init__(self, code, name, date, time, price):
        self.code = code
        self.name = name
        self.date = date
        self.time = time
        self.price = price
class Book:
    def __init__(self, movie_name, user_name, phone, num_tick):
        self.movie_name = movie_name
        self.user_name = user_name
        self.phone = phone
        self.num_tick = num_tick

def is_found(check):
    with open('movie.txt', 'r') as file:
        for line in file:
            st = line.strip().split('\t')
            if st[1] == check:
                return True
    return False

def insert_movie():
    with open('movie.txt','a') as file :
        c = 'y'
        while c == 'y' :
            code    = input('Enter The movie code :')
            name  = input('Enter The movie name :')
            date  = input('Enter movie release date: ')
            time  = input('Enter movie time: ')
            price = input('Enter movie ticket price: ')
            file.write(code +'\t'+ name +'\t'+ date +'\t'+ time +'\t'+ price +'\n' )
            c = input ('Do You Want To Enter Records Again(y/n)?')
        print('Movie Saved Successfully')

def view_all_movie():
    with open('movie.txt','r') as file :
        print('Code\tName\tDate\t\tTime\tPrice \n')
        print('--------------------------------------')
        for line in file:
            print(line,end=' ')

def search():
    name = input('Enter The Name of The Movie You Search For:')
    with open('movie.txt','r') as file :
        flag= False
        for line in file:
            fields=line.split('\t')
            if fields[1]==name:
                flag=True
                print('Code \t Name \t Date \t Time \t Price \n ')
                print('-------------------------------------')
                print(line)
        if not flag:
            print('The Movie not Found')

def update():
    id = input('Enter The Code of The Movie You Want to Update:')
    file = open('movie.txt','r')
    tempfile= open('tempmovie.txt','w')
    flag = False
    for line in file:
        st = line.split('\t')
        if st[0] == id:
            flag = True
            while flag == True:
                print("Press 1 to edit code")
                print("Press 2 to edit name")
                print("Press 3 to edit date")
                print("Press 4 to edit time")
                print("Press 5 to edit price ticket")
                print("Press 6 to update all data")
                print("Press 0 to confirm changes")
                x = int(input())
                if x == 1:
                    code = input("Enter new code: ")
                    st[0] = code 
                elif x == 2:
                    name = input("Enter new name: ")
                    st[1] = name 
                elif x == 3:
                    date = input("Enter new date: ")
                    st[2] = date 
                elif x == 4:
                    time = input("Enter new time: ")
                    st[3] = time 
                elif x == 5:
                    price = input("Enter new price ticket: ")
                    st[4] = price 
                elif x == 6:
                    code = input("Enter new code: ")
                    name = input("Enter new name: ")
                    date = input("Enter new date: ")
                    time = input("Enter new time: ")
                    price = input("Enter new price ticket: ")
                    st[0] = code
                    st[1] = name
                    st[2] = date 
                    st[3] = time
                    st[4] = price
                elif x == 0:
                    break
            line =st[0]+'\t'+st[1]+'\t'+st[2]+'\t'+st[3]+'\t'+st[4]
        tempfile.write(line)
    file.close()
    tempfile.close()
    os.remove('movie.txt')
    os.rename('tempmovie.txt', 'movie.txt')
    if not flag:
        print('The Movie ID not Found ')
    else:
        print('Update Successfully')
    view_all_movie()

def delete():
    code = input('Enter The Code of The Movie You Want to Delete:')
    file =open('movie.txt','r')
    tempfile=open('tempmovie.txt','w')
    flag = False
    for line in file:
        st = line.split('\t')
        if st[0]==code:
            flag=True
        else:
            tempfile.write(line)
    file.close()
    tempfile.close()
    os.remove('movie.txt')
    os.rename('tempmovie.txt','movie.txt')
    if not flag:
        print('The Movie ID not Found ')
    else:
        print('Deleted Successfully')
    view_all_movie()

def delete_all_movies():
    with open("movie.txt", "w"):
        pass 
    print("Deleted successfully")

def insert_data():
    with open('data.txt', 'a') as user:
        movie_name = input("Enter movie name: ")
        if not is_found(movie_name): 
            print("\n\tThis movie is not found..!\n")
            print("___________________________________________________")
            return
        user_name = input("Enter your name: ")
        phone = input("Enter your phone number: ")
        num_tick = input("Enter number of tickets: ")
        user.write(movie_name + '\t' + user_name + '\t' + phone + '\t' + num_tick + '\n')
        print("Reservation successful")
        print("___________________________________________________")
    with open('movie.txt','r') as file :
        flag = False
        for line in file:
            line = line.strip().split('\t')
            if line[1] == movie_name:
                m = Movie(line[0], line[1], line[2], line[3], line[4])
                print(f"\n\t**** {m.name} Movie ****")
                print(f"\tName: {user_name}")
                print(f"\tPhone number: {phone}")
                print(f"\tMovie code: {m.code}")
                print(f"\tMovie name: {m.name}")
                print(f"\tDate: {m.date}")
                print(f"\tTime: {m.time}")
                print(f"\tprice: {m.price}")
                print(f"\tTotal seats: {int(num_tick)}")
                print(f"\tTotal amount: {int(num_tick) * int(m.price)} EGP\n")
                print("___________________________________________________")
                flag = True

        if not flag:
            print("\n\tThis movie is not found..!\n")
            print("___________________________________________________")

def view_booking():
    with open('data.txt', 'r') as user :
        print('movie_name\tuser_name\tphone\tnum_tick ')
        print('--------------------------------------')
        for line in user:
            print(line,end=' ')


def delete_booking():
    check = input("Please enter your name to delete bookings: ")
    file =open('data.txt','r')
    tempfile=open('tempdata.txt','w')
    flag = False
    for line in file:
        st = line.split('\t')
        if st[1] == check:
            flag = True
        else:
                tempfile.write(line)
    file.close()
    tempfile.close()
    os.remove('data.txt')
    os.rename('tempdata.txt','data.txt')
    if not flag:
        print("Name not found")
    else:
        print('Deleted Successfully')

def check_(function):
    print("\n__Press (0) Exit\n__Press (1) continue\n")
    q = int(input())
    print(" _________________________________________________\n")
    if q == 0:
        print("\t\t\tThank you !\n")
    else:
        function()

def management():    
    print("\t\t\t   Press (1) Insert Movie\n"
          "\t\t\t   Press (2) View All Movie\n"
          "\t\t\t   Press (3) Search Movie\n"
          "\t\t\t   Press (4) Update Movie\n"
          "\t\t\t   Press (5) Delete Movie\n"
          "\t\t\t   Press (6) Delete All Movies\n"
          "\t\t\t   Press (7) View All Movie\n"
          "\t\t\t   Press (8) HOME\n"
          "\t\t\t   Press (0) Exit\n\n")
    cases = int(input())
    if cases == 0:
        print("\t\t\tThank you !\n")
    elif cases == 1:
        insert_movie()
        check_(management)
    elif cases == 2:
        view_all_movie()
        check_(management)
    elif cases == 3:
        search()
        check_(management)
    elif cases == 4:
        update()
        check_(management)
    elif cases == 5:
        delete()
        check_(management)
    elif cases == 6:
        delete_all_movies()
        check_(management)
    elif cases == 7:
        view_booking()
        check_(management)
    elif cases == 8:
        home()
    else:
        print("this number is incorrect!\n")
        print(" _________________________________________________\n")

def viewer():    
    print("\t\t\t   Press (1) View All Movie\n"
          "\t\t\t   Press (2) Search Movie\n"
          "\t\t\t   Press (3) Book Ticket\n"
          "\t\t\t   Press (4) Delete Booking\n"
          "\t\t\t   Press (5) HOME\n"
          "\t\t\t   Press (0) Exit\n\n")
    cases = int(input())
    if cases == 0:
        print("\t\t\tThank you !\n")
    elif cases == 1:
        view_all_movie()
        check_(viewer)
    elif cases == 2:
        search()
        check_(viewer)
    elif cases == 3:
        insert_data()
        check_(viewer)
    elif cases == 4:
        delete_booking()
        check_(viewer)
    elif cases == 5:
        home()
    else:
        print("this number is incorrect!\n")
        print(" _________________________________________________\n")

def home():   
    print("\t\t\t******************************\n"
          "\t\t\t**                          **\n"
          "\t\t\t**   Movie Ticket booking   **\n"
          "\t\t\t**                          **\n"
          "\t\t\t******************************\n\n")
    print("\t\t______________________________________________\n")
    print("\n\t\t\t   What you want to open \n")
    print("\t\t______________________________________________\n")
    print("\n\t\t\t   1- Management System\n"
          "\n\t\t\t   2- Viewer System\n")
    print("\t\t______________________________________________\n")
    file = int(input())
    if file == 1:
        print("\n\t\t\t__please Enter password__\n")
        passw = int(input())
        if passw == 1234:
            management()
        else:
            print("\t\t______________________________________________\n")
            print("\n\t\t\t____This password incorrect____\n")
    elif file == 2:
        viewer()
home()
#insert_movie()
#view_all_movie()
#update()
#delete()
#delete_all_movies()
#insert_data()
#delete_booking()
#check()
