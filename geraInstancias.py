import random
def geraInstanciasCrescente(tam):
    txt = open("instancia_Crescente"+str(tam)+".txt","w")
    for item in range(tam):
        txt.write(str(item+1)+" ")
    txt.close()
def geraInstanciasDecrescente(tam):
    txt = open("instancia_Decrescente"+str(tam)+".txt","w")
    for item in range(tam):
        txt.write(str(item+1)+" ")
    txt.close()
def geraInstanciasCrescenteFimErrado(tam):
    txt = open("instancia_CrescenteFimErrado"+str(tam)+".txt","w")   
    for item in range(2,tam-1):
        txt.write(str(item)+" ")       
    txt.write(str(1))
    txt.close()
def geraInstanciasAleatoria(tam):  
    txt = open("instancia_Aleatoria"+str(tam)+".txt","w")   
    for item in range(tam):
        txt.write(str(int(random.randrange(tam+1)))+" ")    
    txt.close()
v = {10,100,1000,10000,100000}
for i in v:
    geraInstanciasCrescenteFimErrado(i)
    geraInstanciasAleatoria(i)
    geraInstanciasCrescente(i)
    geraInstanciasDecrescente(i)

