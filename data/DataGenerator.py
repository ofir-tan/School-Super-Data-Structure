from numpy import random as rd
from enums import Worker
import pandas as pd

# static method's:
def string_of_int(min, max, n=1):
    return ' '.join(map(str, list(rd.randint(min, max, n))))

def string_of_data(data, size, c=' '):
    return c.join(list(rd.choice(data, size, replace=False)))

def rand_char(a, b):
    return chr(rd.randint(ord(a), ord(b) + 1))

# class implementation:
class DataGenerator:

    def __init__(self, path, dataset_path):
        self.path = path
        self.dataset_path = dataset_path

    def get_list_of_names(self):
        df = pd.read_csv(self.dataset_path)
        return df['name'][:].tolist()

    def generate_students(self, n, name="Students.txt", mode='w'):
        f = open(self.path + name, mode)
        names = self.get_list_of_names()

        for _ in range(n):
            f.write(f"{rd.choice(names)} {rd.choice(names)}\n")  # name
            f.write(string_of_int(0, 100, rd.randint(1, 6)) + '\n')  # grades
            f.write(f"{rand_char('a', 'f')} {rd.randint(1, 4)}\n")  # layer & class
        f.close()

    def generate_teachers(self, n, name="Teachers.txt", type=Worker.Teachers, mode='w'):

        f = open(self.path + name, mode)
        names = self.get_list_of_names()

        for _ in range(n):
            f.write(f"{rd.choice(names)} {rd.choice(names)}\n")
            f.write(string_of_int(1, 20, 2) + '\n')
            f.write(string_of_data(names, rd.randint(1, 5)) + '\n')
            if type == Worker.Tutors:
                f.write(f"{rand_char('a', 'f')} {rd.randint(1, 4)}\n")
            elif type == Worker.Managers:
                f.write(f"{rd.randint(100, 200)}\n")
        f.close()

    def generate_secretariat(self, n=1, name="Secretariat.txt", mode='w'):
        f = open(self.path + name, mode)
        names = self.get_list_of_names()

        for _ in range(n):
            f.write(f"{rd.choice(names)} {rd.choice(names)}\n")
            f.write(string_of_int(1, 20, 2) + '\n')
            f.write(f"{rd.randint(100, 200)}\n")
            f.write(f"{rd.randint(0, 5)}\n")
        f.close()

    def generate_tutors(self, n, name="Tutors.txt", mode='w'):
        self.generate_teachers(n, name, type=Worker.Tutors)

    def generate_manager(self, n=1, name="Manager.txt", mode='w'):
        self.generate_teachers(n, name, type=Worker.Managers)
