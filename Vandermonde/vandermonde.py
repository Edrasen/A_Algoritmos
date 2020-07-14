#Análisis de algoritmos
#Sesión 6. Matriz de Vandermonde
#Ramos Mesas Edgar Alain

import math

n = 0          		#Raiz n-esima
z = 0+0j			#Raiz principal enesima
zA = []				#Arreglo de raices n-esimas


mVand = []          #it saves all coefficient from roots
mVandInv = []       #inverse matrix from mVand
mComp = []          #by obtaining identity matrix we verify mVand is in fact inv matrix from mVand

def RaizPrincipal(n):
	global z
	r = (2*math.pi)/n
	cos = float("{:.2f}".format(math.cos(r)))
	sin = float("{:.2f}".format(math.sin(r)))
	z = complex(cos,sin)
	print("\nRaiz pricipal: {} + i{}\n".format(cos,sin))

def RaicesN():
	global zA
	for j in range(n):
		z0=z**j
		r=float("{:.3f}".format(z0.real))
		if(r==-0):r=0
		i=float("{:.3f}".format(z0.imag))
		zf = complex(r,i)
		zA.append(zf)                   #adding all roots to a list

def vandermonde():
	global mVand
	for i in range(n):                  #it creates roots coefficient matrix
		mVand.append([0]*n)             
	for i in range(n):
		for j in range(n):
			mVand[i][j]=zA[i]**j        #save al coef values on vandermore matrix

def impMatriz(m):
	for i in range(n):
		for j in range(n):
			print("{}".format(m[i][j]), end="")         #generic funtion to print matrix
		print("")

def mandermondeInv():
	global mVandInv
	for i in range(n):
		mVandInv.append([0]*n)
	for i in range(n):
		for j in range(n):
			mVandInv[i][j] = (1/n)*(1/mVand[i][j])      #calculate inv matrix 

def comprobacion():
	global mComp
	for i in range(n):
		mComp.append([0]*n)
	for i in range(n):
		for j in range(n):
			for k in range(n):
				mComp[i][k] = mVandInv[i][j]*mVand[j][k] + mComp[i][k]      #to multiply both, vandermonde

n = int(input("Introduzca una n mayor a 2: "))
while(not(n>=2)):
    	n = int(input("Introduzca una n mayor a 2: "))
RaizPrincipal(n)
RaicesN()
vandermonde()
print("Matriz de vandermore:")
impMatriz(mVand)
print("")
mandermondeInv()
print("Matriz de vandermore Inversa:")
impMatriz(mVandInv)
print("")
comprobacion()
print("Comprovacion de Inversa")
impMatriz(mComp)
