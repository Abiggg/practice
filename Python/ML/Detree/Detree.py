from math import log

def calcShannonEnt(DataSet):
    numEntries = len(DataSet)
    labelCounts = {}
    for featVec in DataSet:
        currentLable = featVec[-1]
        if currentLable not in labelCounts.keys():
            labelCounts[currentLable] = 0
    labelCounts[currentLable] += 1
    shannonEnt = 0.0
    for key in labelCounts:
        probe = float(labelCounts[key]) / numEntries
        shannonEnt -= probe * log(probe,2)
    return shannonEnt

def splitDataSet(dataSet, axis, value):
    retDateSet = []
    for featVec in dataSet:
        reduceFeatVec = featVec[:axis]
        reduceFeatVec.extend(featVec[axis+1:])
        retDateSet.append(reduceFeatVec)
