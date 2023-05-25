import nltk

from nltk.stem import PorterStemmer

p = PorterStemmer()

run = 1

while (run == 1):
    inp = input("Give me a english word to stem: Enter 0 to stop: ")
    if (inp == "0"):
        run = 0
    else:
        print(p.stem(inp))
