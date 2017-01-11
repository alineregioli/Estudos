import os
import time
import string
import shutil
import filecmp
dir = os.path.dirname(os.path.abspath(__file__))
class CL:
	G = '\033[92m'
	B = '\033[94m'
	F = '\033[91m'
	E = '\033[0m'
	BO = '\033[1m' 
def clear():
	os.system("clear")
def printr(str):
		print CL.F + CL.BO + str + CL.E
def printb(str):
		print CL.B + CL.BO + str + CL.E
def printg(str):
		print CL.G + CL.BO + str + CL.E
def runx(x,y):
	os.system("cd "+x+" && g++ -std=c++11 "+x+".cpp && ./a.out < "+y+" > out")
def run(x):
	os.system("cd "+x+" && g++ -std=c++11 "+x+".cpp && ./a.out")

while(1):
	clear()
	printg("<=== FLECHA ===>")
	printb("1.Criar")
	printb("2.Testar")
	op = raw_input()
	clear()
	printb("Digite a nome da questao:")
	x = raw_input()
	direc = dir + "/" +x
	if op == "1":
		printb("Digite o numero de casos de teste:")
		y = raw_input()
		if not os.path.exists(direc):
			os.makedirs(direc)
			shutil.copy2(dir+"/header.cpp", direc+"/"+x+".cpp")
			for i in range(1,int(y)+1):
				open(direc+"/"+str(i),'w')
				open(direc+"/o"+str(i),'w')
			printg("Criado com sucesso!!!")
	elif op == "2":
		clear()
		printb("1.Executar")
		printb("2.Um Caso")
		printb("3.Todos os Casos")
		op = raw_input()
		if op == "1":
			while True:
				clear()
				run(x)
				printb("Testar novamente?(1-Sim,2-Nao)")
				y = raw_input()
				if y == "2": 
					break
		elif op == "2":
			printb("Digite o caso:")
			y = raw_input()
			clear()
			start_time = time.time()
			runx(x,y)
			start_time = time.time() - start_time
			if filecmp.cmp(direc+"/o"+y,direc+"/out") == True:
				printg("Passou!!!")
			else:
				printr("Minha Saida:")
				with open(direc+"/out", 'r') as f:
						print f.read()
				printg("Saida Correta:")
				with open(direc+"/o"+y, 'r') as f:
						print f.read()
			printb("Tempo: " + format(start_time,'.3f'))			
		else:
			while True:
				i = "1"
				clear()
				while os.path.exists(direc+"/"+i):
					y = i;
					start_time = time.time()
					runx(x,y)
					start_time = time.time() - start_time
					printb("Caso " + y)
					if filecmp.cmp(direc+"/o"+y,direc+"/out") == True:
						printg("Passou!!!")
					else:
						printr("Minha Saida:")
						with open(direc+"/out", 'r') as f:
							print f.read()
						printg("Saida Correta:")
						with open(direc+"/o"+y, 'r') as f:
							print f.read()
					printb("Tempo: " + format(start_time,'.3f'))
					print("")
					i = str(int(i)+1)
				printb("Testar novamente?(1-Sim,2-Nao)")
				y = raw_input()
				if y == "2": 
					break
	printg("FIM")	
	raw_input()

