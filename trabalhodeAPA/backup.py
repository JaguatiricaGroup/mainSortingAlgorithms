import os
import sys,shutil
import time
import subprocess
from subprocess import Popen,PIPE, STDOUT
import glob
import pandas as pd

def geraTabela(execu,algoritmo,i1,i2,i3,i4):
    import pandas as pd
    df = pd.DataFrame({"a":algoritmo , "b":i1, "c":i2, "d":i3, "e":i4 })
    with open("saida/my_table_"+str(execu)+".tex", "w") as f:
        f.write("\\begin{longtable}{" + " | ".join(["c"] * len(df.columns)) + "}\n")
        f.write(str(execu)+" & Ordenado & Semiordenado & Aleatorio & Ordenado Inversamente \\\\\n")
        #print("\\begin{tabular}{" + " | ".join(["c"] * len(df.columns)) + "}\n")
        for i, row in df.iterrows():
            f.write(" & ".join([str(x) for x in row.values]) + " \\\\\n")
      #      print((" & ".join([str(x) for x in row.values]) + " \\\\\n"))
        f.write("\\end{longtable}")
        f.close()



for j in range(1):              
        tempos = list()
        algoritmo =list()
        algoritmo.append("bubbleSort")
        algoritmo.append("insertionSort")
        algoritmo.append("selectionSort")
        algoritmo.append("quickSort")
        algoritmo.append("heapSort")
        algoritmo.append("mergeSort")
        for i in range(4):
                tempos.append(list())
        # ordenado= list()
        # semiordenado= list()
        # aleatorio=list()
        # ordInv=list()
        # k=
        execu = {sys.argv[2]}
        for filename in execu:
                # print(filename)
                saidaComando = subprocess.check_output([sys.argv[1],str(filename)])
                saida = saidaComando.decode("utf-8")
                # print(saida)
                # info = list()
                # i=0
                saidaAux = saida.split('\n')
                for i in range(len(saidaAux)):
                    if(i%3==2):                        
                        if(saidaAux[(i-1)] == "ORDENADOS"):
                            tempos[0].append(saidaAux[i])
                            # print(saidaAux[(i-1)]+" "+saidaAux[i])
                        elif(saidaAux[(i-1)] == "SEMIORDENADOS"):
                            tempos[1].append(saidaAux[i])                            
                        elif(saidaAux[(i-1)] == "ALEATORIOS"):
                            tempos[2].append(saidaAux[i])                                                    
                        elif(saidaAux[(i-1)] == "ORDENADOS INVERSAMENTE"):
                            tempos[3].append(saidaAux[i])
                    # if(i%3==2):
                for l in tempos:
                    print(l)
                        # print(saidaAux[i])

                        # print(saidaAux[((i)+j)])
                       # for j in range(6):      
                        # # algoritmo[j] = saidaAux[i*j]
                            # tipo[i].append(saidaAux[(i*j)+1])
                            # tempos[i].append(saidaAux[(i*j)+2])
                            #ORDENADOS
                geraTabela(filename,algoritmo,tempos[0],tempos[1],tempos[2],tempos[3])
# 
# ORDENADOS
# 
# SEMIORDENADOS
# SEMIORDENADOS
# SEMIORDENADOS
# SEMIORDENADOS
# SEMIORDENADOS
# 
# ALEATORIOS
# ALEATORIOS
# ALEATORIOS
# ALEATORIOS
# ALEATORIOS
# 
# ORDENADOS INVERSAMENTE
# ORDENADOS INVERSAMENTE

