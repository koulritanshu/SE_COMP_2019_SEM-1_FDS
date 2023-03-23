# Write a Python program to compute following operations on 
# String: 
# a) To display word with the longest length 
# b) To determines the frequency of occurrence of particular 
# character in the string 
# c) To check whether given string is palindrome or not 
# d) To display index of first appearance of the substring 
# e) To count the occurrences of each word in a given string 
# (Do not use string built-in functions)

class String:
    def __init__(self):
        self.str = ""
        self.length = 0
    
    def changeLength(self):
        self.length = 0
        for i in self.str:
            self.length += 1

    def run(self):
        while True:
            print("\n\n")
            print("1. Enter '1' to enter a string.")
            print("2. Enter '2' to display the string.")
            print("3. Enter '3' to check the frequency of a character.")
            print("4. Enter '4' to check if the string is a palindrome.")
            print("5. Enter '5' to check count of each word.")
            print("6. Enter '6' to display the largest word.")
            print("7. Enter '7' to check for a subtring.")
            print("0. Enter any other key to escape.")
            choice = input("--> Make a choice: ")

            if choice == "1":
                self.input()
                self.changeLength()
            elif choice == "2":
                print("--> PRINTING THE STRING")
                if self.str == "":
                    print("--> The string is empty.")
                else:
                    print(self.str)
            elif choice == "3":
                self.frequency()
            elif choice == "4":
                self.palindrome()
            elif choice == "5":
                self.count()
            elif choice == "6":
                self.word()
            elif choice == "7":
                self.index()
            else:
                print("--> GoodBye!")
                break

    def frequency(self):
        inp = input("--> Enter the word whose frequency you wish to check: ")
        answer = 0
        for i in range(self.length):
            if self.str[i] == inp:
                answer += 1

        print(f"{inp} is present ==> {answer} <== times in the string.")

    def input(self):
        self.str = input("--> Enter a string: ")

    def palindrome(self):
        wordReversed = ""
        for i in range(self.length):
            wordReversed += self.str[self.length - i - 1]

        print(f"--> Original Word = {self.str}")
        print(f"--> Word Reversed = {wordReversed}")
        
        if self.str == wordReversed:
            print("--> The word is a palindrome.")
        else:
            print("--> The Word is not a palindrome.")

    def index(self):
        substr = input("--> Enter the substring: ")
        present = False
        for i in range(self.length):
            if self.str[i:i+len(substr)] == substr:
                print(f"--> Index found at {i}.")
                present = True
                break

        if not present:
            print("--> The Substring is not present.")

    def word(self):
        endi = 0
        maxi = 0
        curr = 0
        for i in range(self.length):
            if self.str[i] == " ":
                if maxi < curr:
                    endi = i-1
                    maxi = curr
                curr = 0
            else:
                curr += 1

        if maxi < curr:
                endi = self.length-1
                maxi = curr
                curr = 0

        maximumWord = ""
        for i in range((endi - maxi + 1),(endi+1)):
            maximumWord += self.str[i]

        print(f"Word with maximum length is {maximumWord}.")

    def count(self):
        dict = {}
        list = []
        currWord = ""
        for i in range(self.length):
            if self.str[i] == " ":
                list.append(currWord)
                currWord = ""
            else:
                currWord += self.str[i]

        list.append(currWord)
    
        for i in list:
            countofword = 0
            for j in list:
                if j == i:
                    countofword += 1
            dict[i] = countofword

        print("--> PRINTING THE COUNT OF ALL WORDS")
        print(dict)

obj = String()
obj.run()