#!/usr/bin/python -B   # -B prevents writing .pyc compiled versions of each module

import sys, getopt

def printHelp():
	print ''
	print 'test.py -s <systemName> routineNames'
	print 'Possible routine names:'


def parseSystem(argv):
	try:
		opts, args = getopt.getopt(argv,"hs:")
	except getopt.GetoptError:
		printHelp()
		sys.exit(2)
	for opt, arg in opts:
		if opt == '-h':
			printHelp()
			sys.exit()
		elif opt == "-s":
			sysName = arg
       		return sysName

def parseRoutines(argv):
	try:
		opts, args = getopt.getopt(argv,"hr:")
	except getopt.GetoptError:
		printHelp()
		sys.exit(2)
	for opt, arg in opts:
		if opt == '-h':
			printHelp()
			sys.exit()
		elif opt == "-r":
			rNames = arg
       		return rNames


def writeHeader(systemName):
	sum = x + y
	return sum




# print('Arguments:', len(sys.argv))
# print('List:', str(sys.argv))


systemName = parseSystem(sys.argv[1:])
routines   = parseRoutines(sys.argv[1:])

print 'systemName:', systemName, ' routines: ', routines

text_file = open('output.txt', 'w')
text_file.write('my string i want to put in  a file')
text_file.close()




