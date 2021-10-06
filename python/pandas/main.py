# ==V1==
# with open("2018_Central_Park_Squirrel_Census_-_Squirrel_Data.csv") as data_file:
#     data = data_file.readlines()


# ==V2==
# import csv
#
# with open("2018_Central_Park_Squirrel_Census_-_Squirrel_Data.csv") as data_file:
#     data = csv.reader(data_file)
#     name = []
#     for row in data:
#         if row[1] != "name":
#             name.append(row[1])
#
#     name = list(set(name))

# ==WITH PANDAS==
import pandas as pd

# 1. squirrels data
def make_squirrel_count() :
    data = pd.read_csv("2018_Central_Park_Squirrel_Census_-_Squirrel_Data.csv")
    gray_squirrels_count = len(data[data["Primary Fur Color"] == "Gray"])
    red_squirrels_count = len(data[data["Primary Fur Color"] == "Cinnamon"])
    black_squirrels_count = len(data[data["Primary Fur Color"] == "Black"])

    print(gray_squirrels_count)
    print(red_squirrels_count)
    print(black_squirrels_count)

    data_dict = {
        "Fur Color": ["Gray", "Red", "Blck"],
        "Count": [gray_squirrels_count, red_squirrels_count, black_squirrels_count]
    }

    df = pd.DataFrame(data_dict)
    df.to_csv("squirrels_count")

# 2. pokemon
def pokemon() :
    df = pd.read_csv('pokemon_data.csv')

    # - Get column names in dataframe
    # df.columns, df['NAME']
    df[['Name', 'Type 1']]

    # - Get Row in dataframe
    # (iloc)index of location
    df.iloc[2]['Name']

    for index, row in df.iterrows():
        index, row['Name']

    df[df['Type 1'] == 'Fire']

    # - Get specific location (R, C)
    df.iloc[2, 1]

    # - describe()
    df.describe()['HP']['mean']

    # - sort()
    df.sort_values(['Name', 'HP'], ascending=[1, 0])

    # - head()
    # df['Total'] = df['HP'] + df['Attack'] + df['Defense'] + df['Sp. Atk'] + df['Sp. Def'] + df['Speed']
    df['Total'] = df.iloc[:, 4:10].sum(axis=1)
    # df.head(5)

    # - drop()
    # df.drop(columns=['Total'])

    cols = list(df.columns.values)
    df = df[cols[0:4] + [cols[-1]] + cols[4:12]]
    # df[cols[0], cols[1], cols[2], cols[3]]

    df[(df['Type 1'] == 'Grass') & (df['Type 2'] == 'Poison') & (df['HP'] > 70)]

    # df.loc[df['Name'].str.contains('Mega')]
    # df.loc[~df['Name'].str.contains('Mega')]

    #- regex
    import re
    df[df['Type1'].str.contains('Fire|grass', flags=re.I, regex=True)]
    # df[df['Name'].str.contains('pi[a-z]*', flags=re.I, regex=True)]

    # df.loc[df['Type 1'] == 'Fire', 'Type 1']

    df.loc[df['Attack'] > 50, ['Generation', 'Legendary']] = ['Test 1', 'Test 2']
    # df

    #- groupby()
    df.groupby(['Type 1']).mean().sort_values('Defense', ascending=False)
    df.groupby(['Type 1']).sum()
    df.groupby(['Type 1']).count()
    df.groupby(['Type 1', 'Type 2']).count()

    new_df = pd.DataFrame(columns=df.columns)
    print(new_df)
pokemon()