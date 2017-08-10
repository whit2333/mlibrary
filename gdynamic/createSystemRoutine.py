#!/usr/bin/python -B            # -B prevents writing compiled bytecode files. Otherwise python writes .pyc compiled versions of each module

import sys

print('Arguments:', len(sys.argv))
print('List:', str(sys.argv))


filename = sys.argv[1]
print('Filename:', filename)

text_file = open('output.txt', 'w')
text_file.write('my string i want to put in  a file')
text_file.close()
