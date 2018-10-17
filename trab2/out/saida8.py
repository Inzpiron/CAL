import matplotlib.pyplot as plt 
plt.bar([1], [22.7492 + 45011.4],label='vector', color = 'green')
plt.bar([0], [107.029 + 79.9929],label='hash', color = 'blue')
plt.bar([2], [138.146 + 125.221],label='Map', color = 'red')
plt.xlabel('Estruturas')
plt.ylabel('Tempo MS')
plt.title('Tempo total Entrada-5 (100000x75000)')
plt.xticks([])
plt.ylim(0, 500)
plt.legend()
plt.savefig('../Imgs/graph8.png')

