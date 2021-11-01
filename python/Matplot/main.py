import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

plt.figure(figsize=(7, 7), dpi=100)


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

def pltGas():
    gas = pd.read_csv('gas_prices.csv')

    plt.title('Gas Prices over Time (in USD)', fontdict={'fontweight': 'bold', 'fontsize': 18})

    plt.plot(gas.Year, gas.Canada, 'r.-', label='Canada')
    plt.plot(gas.Year, gas['South Korea'], 'g.-', label='South Korea')
    plt.plot(gas.Year, gas.USA, 'b.-', label='USA')
    plt.plot(gas.Year, gas.Australia, 'y.-', label='Australia')

    plt.xticks(gas.Year[::3].tolist() + [2011])

    plt.xlabel('Year')
    plt.ylabel('US dollars')

    # for country in gas:
    #     if(country != 'Year'):
    #         plt.plot(gas.Year, gas[country], '.-', label=country)

    plt.legend()
    plt.show()

def pltFIFA():
    fifa = pd.read_csv('fifa_data.csv')

    bins = [30, 40, 50, 60, 70, 80, 90, 100]
    plt.hist(fifa.Overall, bins=bins, color='green')
    plt.xticks(bins)
    plt.yticks(np.arange(0, 100, 10))
    plt.ylabel('Number of Player')
    plt.xlabel('Skill Level')
    plt.title('Distribution of Player Skills in FIFA 2018')
    plt.show()

    left = fifa.loc[fifa['Preferred Foot'] == 'Left'].count()[0]
    right = fifa.loc[fifa['Preferred Foot'] == 'Right'].count()[0]
    labels = ['Left', 'Right']
    colors = ['#abcdff', '#aaddcc']
    plt.pie([left, right], labels=labels, colors=colors, autopct='%.2f %%')
    plt.title('Foot Preference of FIFA Players')
    plt.show()

    plt.style.use('ggplot')
    fifa.Weight = [int(x.strip('lbs')) if type(x) == str else x for x in fifa.Weight]
    light = fifa.loc[fifa.Weight < 125].count()[0]
    light_medium = fifa.loc[(fifa.Weight >= 125) & (fifa.Weight < 150)].count()[0]
    medium = fifa[(fifa.Weight >= 150) & (fifa.Weight < 175)].count()[0]
    medium_heavy = fifa[(fifa.Weight >= 175) & (fifa.Weight < 200)].count()[0]
    heavy = fifa[(fifa.Weight >= 200)].count()[0]
    weights = [light, light_medium, medium, medium_heavy, heavy]
    labels = ['Under 125', '125-150', '150-175', '175-200', 'Over 200']
    explode = (.4, .2, 0, .0, .4)
    plt.title('Weight Distribution of FIFA Players (in lbs)')
    plt.pie(weights, labels=labels, autopct='%.2f %%', pctdistance=0.5, explode=explode)
    plt.show()

    manUtd = fifa.loc[fifa.Club == 'Manchester United'].Overall
    manCity = fifa.loc[fifa.Club == 'Manchester City'].Overall
    liverpool = fifa.loc[fifa.Club == 'Liverpool'].Overall
    barcelona = fifa.loc[fifa.Club == 'FC Barcelona'].Overall
    realmadrid = fifa.loc[fifa.Club == 'Real Madrid'].Overall
    labels = ['Manchester United', 'Manchester City', 'Liverpool', 'FC Barcelona', 'Real Madrid']
    boxes = plt.boxplot([manUtd, manCity, liverpool, barcelona, realmadrid], labels=labels, patch_artist=True, medianprops={'linewidth': 2})
    for box in boxes['boxes']:
        box.set(color='#4286f4', linewidth=2)
        box.set(facecolor='#e0e0e0')
    plt.title('Professional Football team Comparison')
    plt.ylabel('FIFA Overall Rating')
    plt.show()

pltFIFA()