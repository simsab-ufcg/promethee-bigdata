import os
import sys

saida = open('experiment1.csv', 'w')

saida.write('VERSION,SIZE,TIME\n')

for directory in os.listdir('.'):
	if os.path.isfile(directory):
		continue
	for file in os.listdir(directory):
		version = file[: file.find('.')]
		size = '2GB'
		aux = open(os.path.join(directory, file), 'r')
		for line in aux:
			if 'Process' in line:
				time = line.split()[1]
				saida.write(','.join([version, size, time + '\n']))
