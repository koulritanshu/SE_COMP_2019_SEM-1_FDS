# Write a python program to store second year percentage of 
# students in array. Write function for sorting array of floating point numbers in ascending order using a) Insertion sort 
# b) Shell Sort and display top five scores

class Student:
    def __init__(self):
        self.percentage = []
    
    def input(self):
        self.n = int(input("Enter the total number of students: "))
        if self.n <= 0:
            print("Entered invalid input. Please try again.")
            return
        
        for i in range(self.n):
            percentage = float(input(f"Enter the percentage of student {i+1}: "))
            self.percentage.append(percentage)

    def run(self):
        sorted = False
        while True:
            print("1. Enter '1' to add names of students.")
            print("2. Enter '2' to perform insertion sort.")
            print("3. Enter '3' to perform quicksort.")
            print("4. Display top five scores.")
            print("0. Enter any other key to escape.")
            choice = input("Make your choice: ")

            if choice == "1":
                sorted = False
                self.input()
            elif choice == "2":
                self.insertionSort()
                print(f"The Sorted List is {self.percentage}")
                sorted = True
            elif choice == "3":
                self.shellSort()
                print(f"The sorted list is {self.percentage}")
                sorted = True
            elif choice == "4":
                if not sorted:
                    print("Sort the list first.")
                else:
                    self.topFive()
            else:
                print("GoodBye!")
                break
            print()
            print()
    def insertionSort(self):
        for i in range(1, self.n):
            key = self.percentage[i]
            j = i - 1

            while j >= 0 and self.percentage[j] > key:
                self.percentage[j+1] = self.percentage[j]
                j = j - 1

            self.percentage[j+1] = key


    def topFive(self):
        answer = []
        for i in range(self.n):
            if i > 4:
                break
            answer.append(self.percentage[self.n - i  - 1])

        print(f"Top five scores are {answer}")

    def shellSort(self):
        gap = self.n//2

        while gap > 0:
            for i in range(gap,self.n):
                key = self.percentage[i]
                j = i

                while j >= gap and self.percentage[j-gap] > key:
                    self.percentage[j] = self.percentage[j-gap]
                    j -= gap

                self.percentage[j] = key

            gap = gap // 2

obj = Student()
obj.run()
