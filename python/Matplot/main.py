import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

plt.figure(figsize=(5, 3), dpi=200)


def pltGraph():
    # plt.plot([1, 2, 3], [2, 4, 6])

    x = [0, 1, 2, 3, 4, 5]
    y = [0, 2, 4, 6, 8, 10]
    # plt.plot(x, y, label='2x', color='red', linewidth=2, linestyle='none', marker='.', markersize=10, markeredgecolor='orange')
    plt.plot(x, y, 'r.-', label='2x')

    x2 = np.arange(0, 4, 0.5)
    plt.plot(x2[:6], x2[:6]**2, 'b')
    plt.plot(x2[4:], x2[4:]**2, 'b--')

    plt.title('Our First Graph', fontdict={'fontname': 'Comic Sans MS', 'fontsize': 20})
    plt.xlabel('X Axis')
    plt.ylabel('Y Axis')
    plt.xticks(np.arange(1, 5, 1).tolist())
    plt.yticks(np.arange(1, 5, 1).tolist())
    plt.legend()

    # plt.savefig('mygraph.png', dpi=300)

    plt.show()

def pltBarChart():
    labels = ['A', 'B', 'C']
    values = [1, 4, 2]

    plt.bar(labels, values)

    bars = plt.bar(labels, values)

    bars[0].set_hatch('/')
    bars[1].set_hatch('O')
    bars[2].set_hatch('*')

    plt.show()

pltBarChart()