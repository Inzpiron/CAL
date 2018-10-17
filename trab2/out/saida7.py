import matplotlib.pyplot as plt 
plt.bar([0], [101.433],label='(N) Ins.', color = 'blue')
plt.bar([1], [80.9275],label='(N) Bus.', color = 'darkblue')

plt.bar([2], [120.254],label='Log(N) Ins.', color = 'red')
plt.bar([3], [109.65],label='Log(N) Bus.', color = 'darkred')

plt.bar([4], [116.093],label='Raiz(N) Ins.', color = 'green')
plt.bar([5], [97.4388],label='Raiz(N) Bus.', color = 'darkgreen')

plt.xlabel('Hash')
plt.ylabel('Tempo Ms')
plt.title('Tamanho do Hash (N) vs Log(N) vs Raiz(N) | Entrada-5.txt')
plt.xticks([])
plt.ylim(0, 200)
plt.legend()
plt.savefig('../Imgs/graph7.png')

