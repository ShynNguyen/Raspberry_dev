import os
import sys
import re

	

def GetPhase(pfile):
	pass

if __name__ == '__main__':
	List_index = 0
	MCAL_Driver = ["ICCOM", "ETH", "CAN"]
	pfile = open('SVN_Template.txt', 'r')
	file_line = pfile.readlines()
	Commit_list = []
	String_list = [[] for _ in range(len(file_line))]
	for index in range(len(file_line)):
		match = re.search('^====*', file_line[index])
		if match:
			Commit_list.append(String_list[List_index])
			List_index = List_index + 1
			continue
		String_list[List_index].append(file_line[index])

	for pStr in Commit_list:
		print(pStr)
