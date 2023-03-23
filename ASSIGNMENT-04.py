# a) Write a Python program to store roll numbers of student in 
# array who attended training program in random order. Write 
# function for searching whether particular student attended 
# training program or not, using Linear search and Sentinel 
# search.
# b) Write a Python program to store roll numbers of student 
# array who attended training program in sorted order. Write 
# function for searching whether particular student attended 
# training program or not, using Binary search and Fibonacci 
# search.

class Student:
    def __init__(self):
        self.students = []
        self.n = 0
    def run(self):
        while True:
            print("1. Enter '1' to add roll number of students.")
            print("2. Enter '2' to perform linear search.")
            print("3. Enter '3' to perform sentinel search.")
            print("4. Enter '4' to perform binary search.")
            print("5. Enter '5' to perform fibonacci search.") 
            print("0. Enter any other key to escape.")
            choice = input("-> Make choice: ")

            if choice == "1":
                self.n = int(input("-> Enter the number of students: "))
                while self.n <= 0:
                    self.n = int(input("-> Invalid input. Try Again: "))
                for i in range(self.n):
                    rollNumber = int(input("-> Enter the roll number of the students: "))
                    while rollNumber <= 0:
                        rollNumber = int(input("-> Invalid input. Try Again: "))
                    self.students.append(rollNumber)
            
            elif choice == "2":
                if self.n > 0:
                    self.linear_search()
                else:
                    print("-> You have not added student data. Please give input first.")

            elif choice == "3":
                if self.n <= 0:
                    print("-> Give input first.")
                else:
                    self.sentinel_search()

            elif choice == "4":
                if self.n <= 0:
                    print("-> Give input first.")
                else:
                    self.binary_search()

            elif choice == "5":
                self.fibonacci_search()

            else:
                print("-> GoodBye!")
                break

            print()

    def linear_search(self):
        print("PRINTING THE LIST OF STUDENTS")
        print(self.students)
        roll = int(input("-> Enter the roll number you wish to search: "))
        present = False
        for i in range(self.n):
            if roll == self.students[i]:
                print("-> Student attended the training program.")
                print(f"-> Student found at index {i}.")
                present = True
                break
        
        if not present:
            print("-> Student did not attend the training program.")
    
    def sentinel_search(self):
        print("PRINTING THE LIST OF STUDENTS")
        print(self.students)
        roll = int(input("-> Enter the roll number you wish to search: "))
        lastElement = self.students[self.n-1]
        self.students[self.n-1] = roll
        i = 0
        while i < self.n - 1:
            if self.students[i] == roll:
                print(f"-> Student found at index {i}.")
                print("-> Student attended the training program")
                break
            i += 1
        
        if i == self.n - 1 and lastElement == roll:
            print(f"-> Student found at index {self.n-1}.")
            print("Student attended the training program.")
        elif i == self.n-1 and lastElement != roll:
            print("-> Student did not attend the training program.") 

        self.students[self.n-1] = lastElement

    def sortList(self):
        for i in range(self.n):
            for j in range(i,self.n):
                if self.students[i] > self.students[j]:
                    temp = self.students[i]
                    self.students[i] = self.students[j]
                    self.students[j] = temp

    def binary_search(self):
        self.sortList()
        print("PRINTING THE LIST OF STUDENTS")
        print(self.students)
        roll = int(input("-> Enter roll number you wish to search: "))

        start = 0
        end = self.n-1

        while start <= end:
            mid = start + (end-start)//2
            present = False
            if self.students[mid] == roll:
                print(f"-> Student attended the training progam.")
                print(f"-> Student found at index {mid}.")
                present = True
                break
        
            elif self.students[mid] > roll:
                end = mid - 1
            
            else:
                start = mid + 1

        if not present:
            print("-> Student did not attend the training program.")

    

    def fibonacci_search(self):
        self.sortList()
        print("PRINTING THE LIST OF STUDENTS")
        print(self.students)
        key = int(input("-> Enter roll number you wish to search: "))
        fib2 = 0
        fib1 = 1
        fib = fib1 + fib2

        while fib < self.n:
            fib2 = fib1
            fib1 = fib
            fib = fib1 + fib2

        offset = -1
        present = 0
        while fib > 1:
            i = min(offset+fib2, self.n - 1)

            if self.students[i] == key:
                print(f"-> Student found at index {i}.")
                present = 1
                break
                
            elif self.students[i] < key:
                fib = fib1 
                fib1 = fib2
                fib2 = fib - fib1
                offset = i

            else:
                fib = fib2
                fib1 = fib1 - fib2
                fib2 = fib - fib1

        if present == 0 and self.students[offset+1] == key:
            print(f"-> Student found at index {offset+1}.")
        
        elif present == 0:
            print("-> Student did not attend the training program.")



obj = Student()
obj.run()