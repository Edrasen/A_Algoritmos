#Ramos Mesas Edgar Alain
#Evaluación de raices complejas

import math

n = 0          		#Raiz n-esima
p = 0				#Grado del polinomio
z = 0+0j			#Raiz principal enesima
resP = 0+0j			#Resultado de evaluacion par
resI = 0+0j			#Resultado de evaluacion Impar
zA = []				#Arreglo de raices n-esimas
pP = []				#Arreglo de mitad de polinomio Par
pI = []				#Arreglo de mitad de polinomio Impar
resZ = []			#Resultado de evaluacion completa



def raizPrincipal():
    global n, z
    while not n >= 2:
        n = int(input("Ingrese un número, debe ser mayor o igual a 2: "))
    r = (2*math.pi)/n
    cos = float("{:.3f}".format(math.cos(r)))
    sen = float("{:.3f}".format(math.sin(r)))
    z = complex(cos, sen)
    print("\nRaiz principal: {} + i{}\n".format(cos,sen))

def resRaizP():
    global zA
    for j in range(n):
        z0 = z**j
        r = float("{:.3f}".format(z0.real))
        if(r == -0):
            r = 0
        i = float("{:.3f}".format(z0.imag))
        zf = complex(r, i)
        zA.append(zf)
        print("{}^{} = {}".format(z,j,complex(r,i)))
    print(zA)

def polinomio():
    global pP, pI, p
    p = int(input("\nEliga la K que sera la potencia de 2 y dara el grado del polinomio (n = 2^k): "))
    p = 2**p
    print("\nIngrese los coeficientes: ")
    for j in range(p):
        if(j%2 == 0):
            cP = input("a{} = ".format(j))
            pP.append(cP)
        else:
            cI = input("a{} = ".format(j))
            pI.append(cI)
    print("\nCoeficientes pares: ",pP)
    print("Coeficientes impares: ",pI)

def EvaluaPolinomio():
    global resP, resI, resZ
    print("\n")
    print("Evaluación del polinomio: ")
    for j in range(len(zA)):
        a = zA[j]
        resP = 0+0j
        resI = 0+0j
        for i in range(len(pP)):
            resP = complex(a**(i*2))*int(pP[i])+resP
        for i in range(len(pI)):
            resI = complex(a**(i*2+1))*int(pI[i])+resI
        print("A({}) = {}".format(zA[j], (resP+resI)))            
        resZ.append(resP+resI)
    

raizPrincipal()
resRaizP()
polinomio()
EvaluaPolinomio()

