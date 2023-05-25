# // Naive bayes algorithm

noOfDataSet = int(input("How many days?"))
noOfPossibleValuesInEachData = int(input("How many possible values does each data set have?"))
varNames = []
print("Give names to each variable")

noOfYes = 0
noOfNo = 0

for x in range(noOfPossibleValuesInEachData):
    varNames.append(input(str(x) + "th variable name = "))
varNames.append("Bool")


print("---------------------")
for x in range(noOfPossibleValuesInEachData):
    print(str(x)+" - index = "+varNames[x])
print("---------------------")


data = []
for i in range(noOfDataSet):
    iData = []
    for j in range(noOfPossibleValuesInEachData):
        iData.append(input(str(varNames[j]) + " in day " + str(i) + ": "))
    yORn = input("Did you play tennis that day? Y|N or y|n or 1|0: ")
    if yORn in ("Y", "y", "1"):
        iData.append(1)
        # print("Yes")
        noOfYes += 1
    else:
        iData.append(0)
        # print("No")
        noOfNo += 1
    data.append(iData)
def printDataSet():
    for i in range(noOfDataSet):
        print("In day " + str(i))
        for j in range(noOfPossibleValuesInEachData + 1):
            print(str(varNames[j]) + "=" + str(data[i][j]))
        print("---------")
# printDataSet()
frequency = []
# Calculating frequency
for i in range(noOfPossibleValuesInEachData):
    frequency_table = {}
    for j in range(noOfDataSet):
        # if any(freq["name"] == data[j][i] for freq in frequency_table)
        if data[j][i] in frequency_table:
            if(data[j][noOfPossibleValuesInEachData] == 1):
                frequency_table[data[j][i]]["yes"] += 1
            else:
                frequency_table[data[j][i]]["no"] += 1
            # frequency_table[data[j][i]] += 1
        else:
            # frequency_table[data[j][i]] = 1
            if(data[j][noOfPossibleValuesInEachData] == 1):
                frequency_table[data[j][i]] = {"yes":1,"no":0}
            else:
                frequency_table[data[j][i]] = {"yes":0,"no":1}
    frequency.append(frequency_table)
    print("for"+str(varNames[i])+": ")
    print(frequency_table)
# print("ANS------------------")
# print(f"p(play = yes) = {noOfYes/noOfDataSet}, {noOfYes} ,{noOfDataSet}")
# print(f"p(play = no) = {noOfNo/noOfDataSet}, {noOfNo} ,{noOfDataSet}")

userInput = []
print("Give me condition of that day:")
for i in range(noOfPossibleValuesInEachData):
    temp = input(str(varNames[i])+": ")
    userInput.append(temp)

forYes = 1
forNo = 1

for i in range(noOfPossibleValuesInEachData):
    forYes *= frequency[i][userInput[i]]["yes"]/noOfYes
    forNo *= frequency[i][userInput[i]]["no"]/noOfNo

forYes *= noOfYes/noOfDataSet
forNo *= noOfNo/noOfDataSet

if(forYes > forNo):
    print(f"the answer is yes p(yes|x') =  {forYes} > p(no|x') = {forNo}")
else:
    print(f"the answer is no p(yes|x') =  {forYes} < p(no|x') = {forNo}")