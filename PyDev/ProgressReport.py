import sys
import re

class Document:
	__init__(self):
		Unchange = 0
		New = 0
		Modified = 0	
		UpdateDate = ""
	# Collect 'Unchange' from all commits
	def Doc_AccumulateUnchanged(self, pValue):
		Unchange = Unchange+ pValue
	# Collect 'New' from all commits 
	def Doc_AccumulateSetNew(self, pValue)
		New = New + pValue
	# Collect 'Modified' from all commits
	def Doc_AccumulateModified(self, pValue)
		Modified = Modified+ pValue

class TestExecution:
	__init__(self):
		TotalTestCase = 0
		UpdateData = ""
	# Collect total test cases executed from all commit
	def TstEx_AccumulateTotalTestCase(self, pValue):
		TotalTestCase = TotalTestCase + pValue
				

class Drvier:
	__init__(self, pName, pDevice):
		Drv_Name = pName
		Drv_Device = pDevice
		FD_Data  = Document()
		DD_Data  = Document()
		UM_Data  = Document()
		ITP_Data = ""
		UTP_Data = ""
		IT_Data  = TestExecution() 
		UT_Data  = TestExecution()

#	# Get data of Function Design Phase
#	def Get_FD_Data(self):
#		return FD_Data
#	# Get data of detail design phase
#	def Get_DD_Data(self):
#		return DD_Data
#	# Get data of IT Preparation phase
#	def Get_ITP_Data(self):
#		return ITP_Data
#	# Get data of UT preparation phase
#	def Get_UTP_Data(self):
#		return UTP_Data
#	# Get data of IT execution phase
#	def Get_IT_Data(self):
#		return IT_Data
#	# Get data of UT execution phase
#	def Get_UT_Data(self):
#		return UT_Data
#	# Get data of User Manual phase
#	def Get_UM_Data(self):
#		return UM_Data
#	# Collect function design data
#	def FD_Colelct_Data(self, Commit):
				

def Commit_Process(Commit);
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
		phase_match = re.search('^Phase:\s(\w+)')
		if phase_match:
			Phase = phase_match.group(1)	
			if (Module == target_module) and 
                          (Device = target_device):
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
	else if pPhase == "DD":
		pUnchanged = Int(pCommit[Index + 2].replace('Unchanged: ', ''))	
		pNew = Int(pCommit[Index + 3].replace('New: ', ''))
		pModified = Init(pCommit[Index + 4].replace('Modified: ', ''))
		MCAL_Driver.DD_Data.Doc_AccumulateUnchaged(pUnchanged)
		MCAL_Driver.DD_Data.Doc_AccumulateNew(pNew)
		MCAL_Driver.DD_Data.Doc_AccumulateModified(pModified)
	else if pPhase == "UM":
		pUnchanged = Int(pCommit[Index + 2].replace('Unchanged: ', ''))	
		pNew = Int(pCommit[Index + 3].replace('New: ', ''))
		pModified = Init(pCommit[Index + 4].replace('Modified: ', ''))
		MCAL_Driver.UM_Data.Doc_AccumulateUnchaged(pUnchanged)
		MCAL_Driver.UM_Data.Doc_AccumulateNew(pNew)
		MCAL_Driver.UM_Data.Doc_AccumulateModified(pModified)
	else if pPhase == "IT":
		pTotalTestCase = Int(pCommit[Index + 2].replace('Executed test cases: ', '')
		MCAL_Driver.IT_Data.TstEx_AccumulateTotalTestCase(pToTalTestCase)


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

	for pStr in Commit_list:
		print(pStr)

	for pCommit in Commit_list:
