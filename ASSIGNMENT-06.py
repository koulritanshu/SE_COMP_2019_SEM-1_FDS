# Write a python program to store first year percentage of 
# students in array. Write function for sorting array of floating 
# point numbers in ascending order using quick sort and 
# display top five scores.

class Student:
    def __init__(self):
        self.percentage = []

    def run(self):
        sorted = False
        while True:
            print("1. Enter percentages of students.")
            print("2. Perform QuickSort.")
            print("3. Display top five scores.")
            choice = input(">> Make choice: ")
            
            if choice == "1":
                sorted = False
                self.input()

            elif choice == "2":
                sorted = True
                self.quickSort(0,self.n-1)
                print(f">> Sorted List is {self.percentage}")

            elif choice == "3":
                if sorted:
                    self.topFive()
                else:
                    print("Sort the list first.")

    def input(self):
        self.percentage = []
        self.n = int(input(">> Enter the number of students: "))
        for i in range(self.n):
            score = float(input(f">> Enter the percentage of student {i+1}: "))
            self.percentage.append(score)

    def partition(self,low,high):
        pivot = self.percentage[high]
        i = low - 1
        for j in range(low,high):
            if self.percentage[j] < pivot:
                i += 1
                temp = self.percentage[i]
                self.percentage[i] = self.percentage[j]
                self.percentage[j] = temp
        i += 1
        temp = self.percentage[high]
        self.percentage[high] = self.percentage[i]
        self.percentage[i] = temp
        return i

    def quickSort(self,start,end):
        if start < end:
            pi = self.partition(start,end)
            self.quickSort(start,pi-1)
            self.quickSort(pi+1,end)

    def topFive(self):
        answer = []
        for i in range(self.n):
            if i > 4:
                break
            answer.append(self.n - i - 1)
        print(answer)

obj = Student()
obj.run()