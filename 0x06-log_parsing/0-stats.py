#!/usr/bin/python3
from sys import stdin

if __name__ == "__main__":

    codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    size = 0

    def parse(line):
        """Parses the log line."""
        global size

        fields = line.rstrip().split(' ')
        size += int(fields[-1])

        if int(fields[-2]) in codes:
            codes[int(fields[-2])] += 1

    def printData():
        """Prints the computed data each 10 iteration and on quit."""
        print("File size: {}".format(size))
        for i in sorted(codes.keys()):
            if codes[i]:
                print("{}: {}".format(i, codes[i]))

    lineCount = 0

    try:
        for line in stdin:
            parse(line)
            if lineCount % 10 == 0:
                printData()
            lineCount += 1
    except KeyboardInterrupt:
        printData()
        raise
    printData()
