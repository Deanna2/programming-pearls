mySet = set()
with open('phonenumbers.txt') as f:
	line = f.readline()
	while line != '':
		mySet.add(int(line))
		line = f.readline()

sortedSet = sorted(mySet)
with open('sortedoutput.txt', 'w') as f:
	for l in sortedSet:
		f.write(str(l) + '\n')
