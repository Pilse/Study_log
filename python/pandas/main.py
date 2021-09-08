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
import pandas

data = pandas.read_csv("2018_Central_Park_Squirrel_Census_-_Squirrel_Data.csv")
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

df = pandas.DataFrame(data_dict)
df.to_csv("squirrels_count")