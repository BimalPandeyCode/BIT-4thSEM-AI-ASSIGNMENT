import nltk
from nltk.stem import WordNetLemmatizer
nltk.download("wordnet")

l = WordNetLemmatizer()

run = 1

while (run == 1):
    inp = input("Give me a english word to lemmatize: Enter 0 to stop: ")
    if (inp == "0"):
        run = 0
    else:
        print(l.lemmatize(inp))
