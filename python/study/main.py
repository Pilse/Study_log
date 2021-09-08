# ==Day 26==
import random
import pandas

numbers = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
squared_numbers = [n ** 2 for n in numbers]
# print(squared_numbers)

even_numbers = [n for n in numbers if n % 2 == 0]
# print(even_numbers)

with open("file1.txt") as file1:
    file1_data = file1.readlines()
with open("file2.txt") as file2:
    file2_data = file2.readlines()
dup_numbers = [int(num) for num in file1_data if num in file2_data]
# print(dup_numbers)

students = ['Alex', 'Beth', 'Caroline', 'Dave', 'Eleanor', 'Freddie']
students_scores = {student: random.randint(1, 100) for student in students}
passed_students = {student: score for (student, score) in students_scores.items() if score > 50}

sentence = "what is the Airspeed Velocity of an Unladen Swallow?"
words = sentence.split()
words_cnt = {word: len(word) for word in words}
# print(words_cnt)

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
# print(weather_f)

student_dict = {
    "student": ["Angela", "James", "Lily"],
    "score": [56, 76, 98]
}
student_dataframe = pandas.DataFrame(student_dict)
for (index, row) in student_dataframe.iterrows():
    if(row.student == 'Angela'):
        print(row.score)

# ==Day 27==
