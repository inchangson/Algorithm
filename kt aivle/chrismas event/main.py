# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
import random
import numpy as np

class bColors:
    LEAF    = '\033[38;5;22m'   #DarkGreen
    BRANCH  = '\033[38;5;88m'   #DarkRed
    STAR    = '\033[38;5;226m'  #Yellow1
    RESET   = '\033[0m'         #RESET
    ACC     = ['\033[38;5;231m',#GREY100
               '\033[38;5;33m', #DodgerBlue1
               '\033[38;5;124m',#Red3
               '\033[38;5;177m',#Violet
               '\033[38;5;76m', #Chartreuse3
               '\033[38;5;130m' #DarkOrange3
               ]

def printCenter(halfWidth, targetColor, targetContent):
    print(' ' * (halfWidth - int(len(targetContent)/2)) + targetColor + targetContent + bColors.RESET)

if __name__ == '__main__':
    size = 4
    width  = 41 * size
    height = 16 * size
    halfWidth = int(width / 2)
    accStr = "*7o%+@" #accessary
    blockHeight = 4
    removeSize = 1
    blockCnt = 0
    rsltR = 0
    print('\n' * (size**2))
    #star
    printCenter(halfWidth, bColors.STAR, 'K T')
    printCenter(halfWidth, bColors.STAR, 'AIVLE')
    printCenter(halfWidth, bColors.STAR, '▲')
    for r in range(0, height):
        accCnt = random.randint(0, r)
        startIdx = halfWidth - r
        endIdx = halfWidth + r
        accArr = [np.random.randint(startIdx, endIdx) for _ in range(accCnt)]

        blockCnt += 1
        if blockCnt % blockHeight:
            if(r != 0):
                rsltR += 1
        else:
            rsltR -= removeSize
            removeSize += 1
            blockHeight += 2
            blockCnt = 0

        for c in range(0, width):
            #blank
            if halfWidth > rsltR + c:
                print(' ', end = '')
                continue
            if halfWidth < c - rsltR:
                break
            #acc
            if c in accArr:
                accColorIdx = np.random.randint(0, len(bColors.ACC))
                accShapeIdx = np.random.randint(0, len(accStr))
                print(bColors.ACC[accColorIdx] + accStr[accShapeIdx] + bColors.RESET, end='')
            #leaf
            else:
                print(bColors.LEAF + '#' + bColors.RESET, end = '')
        print()
    # branch
    branchWidth = 2*size
    branchHeight = size
    for i in range(0, branchHeight):
        printCenter(halfWidth, bColors.BRANCH, ('▒' * branchWidth))
    print(bColors.RESET + ('-' * width + '\n') * 3 +'\n\n')
