import matplotlib.pyplot as plt 
plt.bar([0], [0.8],label='ent. 1 (1000)', color = 'green')
plt.bar([1], [3],label='ent. 2 (10000)', color = 'blue')
plt.bar([2], [5],label='ent. 3 (10000)', color = 'red')
plt.bar([3], [14],label='ent. 4 (25000)', color = 'orange')
plt.bar([4], [43],label='ent. 5 (75000)', color = 'black')
plt.xlabel('Vetor')
plt.ylabel('Tempo Seg.')
plt.title('Gráfico tempo de execução Vetor Buscar')
plt.xticks([])
plt.ylim(0, 45)
plt.legend()
plt.savefig('../Imgs/graph6.png')

