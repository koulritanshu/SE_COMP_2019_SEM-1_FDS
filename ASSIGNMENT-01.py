# In second year computer engineering class, group A student’s 
# play cricket, group B students play badminton and group C 
# students play football. 
# Write a Python program using functions to compute 
# following: - a) List of students who play both cricket and 
# badminton b) List of students who play either cricket or 
# badminton but not both c) Number of students who play 
# neither cricket nor badminton d) Number of students who 
# play cricket and football but not badminton. (Note- While 
# realizing the group, duplicate entries should be avoided, Do 
# not use SET built-in functions)

class Set:
    def __init__(self,list1):
        self.list1 = list1

    def present(self,l1,ele):
        for i in l1:
            if i == ele:
                return -1

        return 1

    def intersection(self,list2):
        
        interse = []
        for i in self.list1:
            for j in list2:
                if i == j and self.present(interse,j) == 1:
                    interse.append(j) 
        return interse

    def union(self,list2):
        union = self.intersection(list2)
        for i in self.list1:
            if self.present(self.list1,i) == -1:
                union.append(i)
        for i in list2:
            if self.present(list2,i) == -1:
                union.append(i)
        return union

    def difference(self,list2):
        difference = []
        for i in self.list1:
            willWork = True
            for j in list2:
                if i == j:
                    willWork = False
                    break
            if willWork:
                difference.append(i)

        return difference

class Student:
    def __init__(self):
        self.n = 0
        self.list = []

    def present(self,l1,ele):
        for i in l1:
            if i == ele:
                return -1

        return 1

    def input(self):
        self.n = int(input("--> Enter the total number of students: "))
        while self.n <= 0:
            self.n = int(input("--> Invalid input. Give another value: "))
        self.list = []
        for i in range(self.n):
            ele = input("--> Enter the name of a student: ")
            while self.present(self.list,ele) == -1:
                ele = input("--> Invalid input. Make another input: ")
            self.list.append(ele)

        self.cricketn = int(input("--> Enter the number of people who play cricket: "))
        while self.cricketn > self.n or self.cricketn < 0:
            print("--> Invalid Input. Students playing cricket can't be more than total students.")
            self.cricketn = int(input("--> Give input again: "))
        self.cricket = []
        for i in range(self.cricketn):
            ele = input(f"--> Enter the name of student who plays cricket: ")
            while self.present(self.cricket,ele) == -1 or self.present(self.list,ele) != -1:
                ele = input(f"--> Again enter the name of student: ")

            self.cricket.append(ele)

        self.football = []
        self.footballn = int(input("--> Enter the number of students who play football: "))
        while self.footballn > self.n or self.footballn < 0:
            print("--> Invalid input. Number of students can't be greater than total number.")
            self.footballn = int(input("--> Give input again: "))
        
        for i in range(self.footballn):
            ele = input("--> Enter names of students playing football: ")
            while self.present(self.football,ele) == -1 or self.present(self.list,ele) != -1:
                ele = input(f"--> Again enter the name of student: ")

            self.football.append(ele)

        self.badminton = []
        self.badmintonn = int(input("--> Enter the number of students who play badminton: "))
        while self.n < self.badmintonn or self.badmintonn < 0:
            print("--> Invalid input.")
            self.badmintonn = int(input("--> Enter number of students again: "))
        for i in range(self.badmintonn):
            ele = input("--> Enter names of students playing badminton: ")
            while self.present(self.badminton,ele) == -1 or self.present(self.list,ele) != -1:
                ele = input("--> Invalid input. Enter name of student again: ")
            self.badminton.append(ele)

    def input2(self):
        while True:
            print("\n\n")
            print("1. Enter '1' to enter input.")
            print("2. Enter '2' to display students who play cricket.")
            print("3. Enter '3' to display students who play football.")
            print("4. Enter '4' to display students who play badminton.")
            print("5. Enter '5' to display students who play both cricket and badminton.")
            print("6. Enter '6' to display students who play either cricket or badminton.")
            print("7. Enter '7' to display students who play neither cricket nor badminton.")
            print("0. Enter any other key to escape.")
            choice = input("--> Make your choice: ")
            if choice == "1":
                self.input()
            elif choice == "2":
                print("--> Displaying students who play cricket.")
                print(self.cricket)
            elif choice == "3":
                print("--> Displaying students who play football.")
                print(self.football)
            elif choice == "4":
                print("--> Displaying students who play badminton.")
                print(self.badminton)
            elif choice == "5":
                print(f"--> Students who play cricket = {self.cricket}.")
                print(f"--> Students who play badminton = {self.badminton}.")
                obj = Set(self.cricket)
                answer = obj.intersection(self.badminton)
                print("--> Displaying students who play both cricket and badminton")
                print(answer)
            elif choice == "6":
                print(f"--> Students who play cricket = {self.cricket}.")
                print(f"--> Students who play badminton = {self.badminton}.")
                obj = Set(self.cricket)
                union = obj.union(self.badminton)
                intersection = obj.intersection(self.badminton)
                obj2 = Set(union)
                answer = obj2.difference(intersection)
                print("--> Displaying students who play either cricket or badminton but not both.")
                print(answer)
            elif choice == "7":
                print(f"Total Students = {self.list}")
                print(f"Students who play cricket = {self.cricket}")
                print(f"Students who play badminton = {self.badminton}")
                obj = Set(self.list)
                obj2 = Set(self.cricket)
                first = obj2.union(self.badminton)
                answer = obj.difference(first)
                print("--> Displaying the students who don't play cricket and badminton")
                print(answer)
            else:
                print("--> GoodBye!")
                break

s = Student()
s.input2()
