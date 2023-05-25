# Word tokenization
import string

s = input("Enter your sentence: ")

words = s.split()
print("Your tokenized words are: ")
for word in words:
    output = ""
    for letter in word:
        if (letter not in string.punctuation):
            output += letter
    print(output)
