import sys
import re

class Document:
	def __init__(self):
		self.Unchange = 0
		self.New = 0
		self.Modified = 0	
		self.UpdateDate = ""
	# Collect 'Unchange' from all commits
	def Doc_AccumulateUnchanged(self, pValue):
		self.Unchange = self.Unchange + pValue
	# Collect 'New' from all commits 
	def Doc_AccumulateSetNew(self, pValue):
		self.New = self.New + pValue
	# Collect 'Modified' from all commits
	def Doc_AccumulateModified(self, pValue):
		self.Modified = self.Modified + pValue

class TestExecution:
	def __init__(self):
		self.TotalTestCase = 0
		self.UpdateData = ""
	# Collect total test cases executed from all commit
	def TstEx_AccumulateTotalTestCase(self, pValue):
		self.TotalTestCase = self.TotalTestCase + pValue
				

class Driver:
	def __init__(self, pName, pDevice):
		self.Drv_Name = pName
		self.Drv_Device = pDevice
		self.FD_Data  = Document()
		self.DD_Data  = Document()
		self.UM_Data  = Document()
		self.ITP_Data = ""
		self.UTP_Data = ""
		self.IT_Data  = TestExecution() 
		self.UT_Data  = TestExecution()

				

def Commit_Process(Commit):
	Module = ""
	Device = ""
	Phase = ""
	for index in range(len(Commit)):
		module_match = re.search('^\[(\w+)\]', Commit[index])
		if module_match:
			Module = module_match.group(1)
		device_match = re.search('^Device:\s((.)*)', Commit[index])
		if device_match:
			Device = device_match.group(1)
		phase_match = re.search('^Phase:\s(\w+)', Commit[index])
		if phase_match:
			Phase = phase_match.group(1)	
			if (Module == target_module) and \
                          (Device == target_device):
				Collect_Data(Phase, index)
			else:
				pass

def Collect_Data(pPhase, pIndex, pCommit):
	if pPhase == "DD":
		pUnchanged = Int(pCommit[Index + 2].replace('Unchanged: ', ''))	
		pNew = Int(pCommit[Index + 3].replace('New: ', ''))
		pModified = Init(pCommit[Index + 4].replace('Modified: ', ''))
		MCAL_Driver.FD_Data.Doc_AccumulateUnchaged(pUnchanged)
		MCAL_Driver.FD_Data.Doc_AccumulateNew(pNew)
		MCAL_Driver.FD_Data.Doc_AccumulateModified(pModified)
	elif pPhase == "DD":
		pUnchanged = Int(pCommit[Index + 2].replace('Unchanged: ', ''))	
		pNew = Int(pCommit[Index + 3].replace('New: ', ''))
		pModified = Init(pCommit[Index + 4].replace('Modified: ', ''))
		MCAL_Driver.DD_Data.Doc_AccumulateUnchaged(pUnchanged)
		MCAL_Driver.DD_Data.Doc_AccumulateNew(pNew)
		MCAL_Driver.DD_Data.Doc_AccumulateModified(pModified)
	elif pPhase == "UM":
		pUnchanged = Int(pCommit[Index + 2].replace('Unchanged: ', ''))	
		pNew = Int(pCommit[Index + 3].replace('New: ', ''))
		pModified = Init(pCommit[Index + 4].replace('Modified: ', ''))
		MCAL_Driver.UM_Data.Doc_AccumulateUnchaged(pUnchanged)
		MCAL_Driver.UM_Data.Doc_AccumulateNew(pNew)
		MCAL_Driver.UM_Data.Doc_AccumulateModified(pModified)
	elif pPhase == "IT":
		pTotalTestCase = \
		  Int(pCommit[Index + 2].replace('Executed test cases: ', ''))
		MCAL_Driver.IT_Data.TstEx_AccumulateTotalTestCase(pToTalTestCase)
	elif pPhase == "UT":
		pTotalTestCase = \
		  Int(pCommit[Index + 2].replace('Executed test cases: ', ''))
		MCAL_Driver.UT_Data.TstEx_AccumulateTotalTestCase(pToTalTestCase)
	else:
		# No action required
		pass


if __name__ == '__main__':
	target_module = sys.argv[1]
	target_device = sys.argv[2]
	MCAL_Driver = Driver(target_module, target_device)
	List_index = 0
	# Log Processing
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

#	for pStr in Commit_list:
#		print(pStr)

	for pCommit in Commit_list:
		Commit_Process(pCommit)
	#======================= Commit Process - DONE ========================
	print(MCAL_Driver.FD_Data.Unchange)
	print(MCAL_Driver.FD_Data.New)
	print(MCAL_Driver.FD_Data.Modified)
	
