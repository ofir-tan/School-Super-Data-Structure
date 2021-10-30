from DataGenerator import DataGenerator

PATH = r"***" # destination path
DATASET = r"***"

def main():
    dg = DataGenerator(PATH, DATASET)

    dg.generate_students(10 ** 4)
    dg.generate_manager()
    dg.generate_tutors(5)
    dg.generate_teachers(10 ** 4)
    dg.generate_secretariat(3)

if __name__ == "__main__":
    main()
