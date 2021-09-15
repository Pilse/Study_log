# ==Day 26==
import random
import pandas
import requests


def day26():
    numbers = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
    squared_numbers = [n ** 2 for n in numbers]
    print(squared_numbers)

    even_numbers = [n for n in numbers if n % 2 == 0]
    print(even_numbers)

    with open("file1.txt") as file1:
        file1_data = file1.readlines()
    with open("file2.txt") as file2:
        file2_data = file2.readlines()
    dup_numbers = [int(num) for num in file1_data if num in file2_data]
    print(dup_numbers)

    students = ['Alex', 'Beth', 'Caroline', 'Dave', 'Eleanor', 'Freddie']
    students_scores = {student: random.randint(1, 100) for student in students}
    passed_students = {student: score for (student, score) in students_scores.items() if score > 50}

    sentence = "what is the Airspeed Velocity of an Unladen Swallow?"
    words = sentence.split()
    words_cnt = {word: len(word) for word in words}
    print(words_cnt)

    weather_c = {
        "Monday": 12,
        "Tuesday": 14,
        "Wednesday": 15,
        "Thursday": 14,
        "Friday": 21,
        "Saturday": 22,
        "Sunday": 24
    }
    weather_f = {day: (temp_c * 9/5) + 32 for (day, temp_c) in weather_c.items()}
    print(weather_f)

    student_dict = {
        "student": ["Angela", "James", "Lily"],
        "score": [56, 76, 98]
    }
    student_dataframe = pandas.DataFrame(student_dict)
    for (index, row) in student_dataframe.iterrows():
        if(row.student == 'Angela'):
            score = row.score

# ==Day 30==

def day30():
    # FileNotFound
    # with open("a_file.txt") as file:
    #     file.read()

    # KeyError
    # a_dictionary = {"key": "value"}
    # value = a_dictionary["non_existent_key"]

    # IndexError
    # fruit_list = ["Apple", "Banana", "Pear"]
    # fruit = fruit_list[3]

    # TypeError
    # text = "abc"
    # print(text + 5)

    try:
        file = open("a_file.txt")
        a_dictionary = {"key": "value"}
        # print(a_dictionary["sss"])
    except FileNotFoundError:
        file = open("a_file.txt", "w")
        # file.write("Something")
    except KeyError as error_message:
        error = error_message
    else:
        content = file.read()
        # print(content)
    finally:
        file.close()

    height = float(input("Height: "))
    weight = int(input("Weight: "))

    if height > 3:
        raise ValueError("Human Height should not be over 3 meters")
    bmi = weight / height ** 2

    print(bmi)

    fruits = ["Apple", "Pear", "Orange"]

    def make_pie(index):
        try:
            fruit = fruits[index]
        except IndexError:
            print("Fruit pie")
        else:
            print(fruit + "pie")
    make_pie(4)

    facebook_posts = [
        {'Likes': 21, 'Comments': 2},
        {'Likes': 13, 'Comments': 2, 'Shares': 1},
        {'Likes': 33, 'Comments': 8, 'Shares': 3},
        {'Comments': 4, 'Shares': 2},
        {'Comments': 1, 'Shares': 1},
        {'Likes': 19, 'Comments': 3}
    ]
    total_likes = 0

    for post in facebook_posts:
        try:
            total_likes = total_likes + post['Likes']
        except KeyError:
            total_likes += 0

    print(total_likes)

# ==Day 33==

def day33():
    response = requests.get(url="https://pypi.org/project/requests/")
    response.raise_for_status()

    data = response.json()

    longitude = data["iss_position"]["longitude"]
    latitude = data["iss_position"]["latitude"]