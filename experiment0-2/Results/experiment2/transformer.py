import os
import sys

saida = open('experiment1.csv', 'w')

saida.write('VERSION,SIZE,TIME\n')

for directory in os.listdir('.'):
	if os.path.isfile(directory):
		continue
	for file in os.listdir(directory):
		version = directory
		size = file[file.find('m') + 1: file.find('.tif')]
		aux = open(os.path.join(directory, file), 'r')
		for line in aux:
			if 'real' in line:
				time = line.split()[1].split('m')
				time = (float(time[0]) * 60) + (float(time[1][:-1]))
				time = str(time)
				saida.write(','.join([version, size, time + '\n']))
