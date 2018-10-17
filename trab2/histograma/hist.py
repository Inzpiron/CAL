import matplotlib.pyplot as plt 
import sys

data = [int(x) for x in input().split('|')]
n, bins, patches = plt.hist(data, 100, facecolor='g')

plt.title('Lotação Hash tamanho Log(N) (Entrada-' + sys.argv[1] + '.txt)')
plt.legend()
plt.savefig('hist-log'+ sys.argv[1] + '.png')

