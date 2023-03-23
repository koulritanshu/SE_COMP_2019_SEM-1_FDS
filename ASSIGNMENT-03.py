# Write a python program to compute following computation on 
# matrix: 
#  a) Addition of two matrices 
#  b) Subtraction of two matrices 
#  c) Multiplication of two matrices 
#  d) Transpose of a matrix

class Matrix:
    def __init__(self):
        self.row1 = 0
        self.column1 = 0
        self.row2 = 0
        self.column2 = 0
        self.matrix1 = []
        self.matrix2 = []

    def run(self):
        while True:
            print("1. Enter '1' to take input.")
            print("2. Enter '2' to print the two matrices.")
            print("3. Enter '3' to add the two matrices.")
            print("4. Enter '4' to perform subtraction.")
            print("5. Enter '5' to multiply the two matrices.")
            print("6. Enter '6' to know the transpose of the two matrices.")
            choice = input("-> Make your choice: ")
            if choice == "1":
                self.input()
            elif choice == "2":
                print("a. Print the first matrix.")
                print("b. Print the second matrix.")
                choice = input("-> Make choice: ")
                if choice == "a":
                    for i in range(self.row1):
                        for j in range(self.column1):
                            print(self.matrix1[i][j], end = " ")
                        print()
                elif choice == "b":
                    for i in range(self.row2):
                        for j in range(self.column2):
                            print(self.matrix2[i][j], end = " ")
                        print()
                else:
                    print("-> Invalid Option.")
            elif choice == "3":
                if self.row1 != self.row2 or self.column2 != self.column2:
                    print("-> The two matrices cannot be added.")
                else:
                    print("-> Adding the two matrices")
                    self.addMatrices()
            elif choice == "4":
                self.subTractMatrices()
            elif choice == "5":
                self.multiply()
            elif choice == "6":
                self.transpose()
            else:
                print("-> GoodBye!")
                break
            print()
    def input(self):
        self.row1 = int(input("-> Enter the number of rows in the first matrix: "))
        self.column1 = int(input("-> Enter the number of columns in the first matrix: "))

        self.matrix1 = [[0 for i in range(self.column1)] for j in range(self.row1)]

        for i in range(self.row1):
            for j in range(self.column1):
                elementToInsert = int(input(f"-> Enter element at {i+1} row and {j+1} column: "))
                self.matrix1[i][j] = elementToInsert
                for x in range(self.row1):
                    for y in range(self.column1):
                        print(self.matrix1[x][y], end = " ")
                    print()

        self.row2 = int(input("-> Enter the number of rows in the second matrix: "))
        self.column2 = int(input("-> Enter the number of columns in the second matrix: "))

        self.matrix2 = [[0 for i in range(self.column2)] for j in range(self.row2)]

        for i in range(self.row2):
            for j in range(self.column2):
                elementToInsert = int(input(f"-> Enter element at {i+1} row and {j+1} column: "))
                self.matrix2[i][j] = elementToInsert
                for x in range(self.row2):
                    for y in range(self.column2):
                        print(self.matrix2[x][y], end = " ")
                    print()
        
    def addMatrices(self):
        print("PRINTING MATRIX 1")
        for i in range(self.row1):
            for j in range(self.column1):
                print(self.matrix1[i][j], end = " ")
            print()
        print("PRINTING MATRIX 2")
        for i in range(self.row2):
            for j in range(self.column2):
                print(self.matrix2[i][j], end = " ")
            print()
        print("PRINTING THE ADDITION")
        for i in range(self.row1):
            for j in range(self.column1):
                print(self.matrix1[i][j] + self.matrix2[i][j], end = " ")
            print()
    def subTractMatrices(self):
        if self.row1 != self.row2 or self.column1 != self.column2:
            print("-> The two matrices cannot be subtracted.")

        else:
            print("PRINTING MATRIX 1")
            for i in range(self.row1):
                for j in range(self.column1):
                    print(self.matrix1[i][j], end = " ")
                print()
            print("PRINTING MATRIX 2")
            for i in range(self.row2):
                for j in range(self.column2):
                    print(self.matrix2[i][j], end = " ")
                print()
            print("a. Subtract first from second.")
            print("b. Subtract second from first.")
            choice = input("-> Make choice: ")
            if choice == "a":
                print("PRINTING THE RESULT")
                for i in range(self.row1):
                    for j in range(self.column1):
                        print(self.matrix2[i][j] - self.matrix1[i][j], end = " ")
                    print()
            elif choice == "b":
                for i in range(self.row1):
                    for j in range(self.column1):
                        print(self.matrix1[i][j] - self.matrix2[i][j], end = " ")
                    print()

            else:
                print("-> Invalid choice.")
    def transpose(self):
        print("a. Transpose of matrix 1")
        print("b. Transpose of matrix 2")
        choice = input("-> Make choice: ")
        if choice == "a":
            print("PRINTING THE ORIGINAL MATRIX")
            for i in range(self.row1):
                for j in range(self.column1):
                    print(self.matrix1[i][j], end = " ")
                print()
            print("PRINTING THE TRANSPOSE")
            for i in range(self.column1):
                for j in range(self.row1):
                    print(self.matrix1[j][i], end = " ")
                print()
        elif choice == "b":
            print("PRINTING THE ORIGINAL MATRIX")
            for i in range(self.row2):
                for j in range(self.column2):
                    print(self.matrix2[i][j], end = " ")
                print()
            print("PRINTING THE TRANSPOSE")
            for i in range(self.column2):
                for j in range(self.row2):
                    print(self.matrix2[j][i], end = " ")
                print()
        else:
            print("-> Invalid Choice.")
    def multiply(self):
        print("a. Multiply 1*2")
        print("b. Multiply 2*1")
        print("PRINTING MATRIX 1")
        for i in range(self.row1):
            for j in range(self.column1):
                print(self.matrix1[i][j], end = " ")
            print()
        print("PRINTING MATRIX 2")
        for i in range(self.row2):
            for j in range(self.column2):
                print(self.matrix2[i][j], end = " ")
            print()
        choice = input("-> Make choice: ")
        if choice == "a":
            if self.column1 != self.row2:
                print("-> The two matrices can't be multiplied.")
            else:
                multiplied = [[0 for i in range(self.column2)] for j in range(self.row1)]
                for i in range(self.row1):
                    for j in range(self.column2):
                        for k in range(self.column1):
                            multiplied[i][j] += self.matrix1[i][k] * self.matrix2[k][j]
                print("PRINTING THE MULTIPLICATION MATRIX")
                for i in range(self.row1):
                    for j in range(self.column2):
                        print(multiplied[i][j], end = " ")
                    print()
        elif choice == "b":
            if self.column2 != self.row1:
                print("-> Matrices can't be multiplied.")
            else:
                multiplied = [[0 for i in range(self.column1)] for j in range(self.row2)]
                for i in range(self.row2):
                    for j in range(self.column1):
                        for k in range(self.column2):
                            multiplied[i][j] += self.matrix2[i][k] * self.matrix1[k][j]
                print("PRINTING THE MULTPLICATION MATRIX")
                for i in range(self.row2):
                    for j in range(self.column1):
                        print(multiplied[i][j], end = " ")
                    print()
        else:
            print("-> Invalid Input.")
    

obj = Matrix()
obj.run()

# r1 = int(input())

# c1 = int(input())

# m1 = [[0 for i in range(c1)] for j in range(r1)]

# for i in range(r1):
#     for j in range(c1):
#         m1[i][j] = int(input())

# r2 = int(input())

# c2 = int(input())

# m2 = [[0 for i in range(c2)] for j in range(r2)]

# for i in range(r2):
#     for j in range(c2):
#         m2[i][j] = int(input())

# ans = [[0 for i in range(c2)] for j in range(r1)]

# for i in range(r1):
#     for j in range(c1):
#         print(m1[i][j], end = " ")
#     print()

# print("\n\n")

# for i in range(r2):
#     for j in range(c2):
#         print(m2[i][j], end = " ")
#     print()
# print("\n\n")
# for i in range(r1):
#     for j in range(c2):
#         for k in range(c1):
#             ans[i][j] += m1[i][k] * m2[k][j]

# for i in range(r1):
#     for j in range(c2):
#         if i == j:
#             ans[i][j] = m1[i][i] * m2[i][i]

# for i in range(r1):
#     for j in range(c2):
#         print(ans[i][j], end = " ")
#     print()
