import numpy as np
import statistics as est
import scipy.stats


#find T valor crítico

x=[-25,-9,12,-14,-27,18]

n = len(x)
md = np.mean(x) # media
print("media:",md)
sd = est.stdev(x) # desviacion estandar 
print("desviacion estandar:",sd)


