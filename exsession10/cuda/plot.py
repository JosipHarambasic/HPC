import matplotlib.pyplot as plt
plt.rcParams.update({'font.size': 5})
f = open("cuda_blocks.log", "r")

blocks = []
results = []
counter = 0
for i in f.readlines():
    a = i.split()
    counter += 1
    if counter <= 80:
        blocks.append(str((a[1],a[4])))
        results.append(float(a[11]))
fig1 = plt.gcf()
plt.bar(blocks,results)
plt.xticks(blocks, rotation='vertical')
plt.title("Plot Blocks and Threads performance")
plt.ylabel("Time in Seconds")
plt.xlabel("Block | Thread combination")
plt.show()
plt.draw()
fig1.savefig('plot.png', dpi=1200)