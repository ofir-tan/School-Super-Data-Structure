#include "School.h"

School *School::BGU = nullptr;

School::School(quantity numberOfLayers, quantity numberOfClasses) {
    vector<char> layerName = {'a', 'b', 'c', 'd', 'e', 'f'};
    for (int i = 0; i < numberOfLayers; i++) {
        layers.push_back(new Layer(layerName[i]));
        for (int j = 0; j < numberOfClasses; j++)
            layers[i]->addClass(new Class(layerName[i], j));
    }
}

School::~School() {
    for (auto &layer: layers)
        delete layer;
    delete BGU;
}

School *School::getInstance(quantity numberOfLayers, quantity numberOfClasses) {
    if (!BGU)
        BGU = new School(numberOfLayers, numberOfClasses);
    else
        cout << "It is not possible to add more than one school." << endl;
    return BGU;
}

bool School::importStudents(const string &path) {

    ifstream file;
    file.open(path);
    if (!file.is_open()) return false;

    string firstName, lastName, grade;
    vector<double> grades;
    char layer;
    short classNumber;

    while (file >> firstName) {
        file >> lastName;
        file >> grade;
        while (isNumber(grade)) {
            grades.push_back(stoi(grade));
            file >> grade;
        }
        layer = grade[0];
        file >> classNumber;
        students += new Student(firstName, lastName, grades, layer, classNumber);
        grades.clear();
    }
    return true;
}

bool School::importWorkers(const string &path, jobs job) {
    // open file:
    ifstream file;
    file.open(path);
    if (!file.is_open()) return false;

    string firstName, lastName;
    int yearsOfTeach, yearsOfManage;
    vector<string> courses;

    while (file >> firstName) {
        // get common values:
        file >> lastName;
        file >> yearsOfTeach;
        file >> yearsOfManage;

        if (job == Secretariat) {
            int numOfChildren;
            string office;
            file >> office;
            file >> numOfChildren;
            workers += new Secretary(firstName, lastName, yearsOfTeach, yearsOfManage, office, numOfChildren);
        } else {
            string stringOfCourses;
            file.get(); // remove '\n';
            getline(file, stringOfCourses);
            courses = stringToWords(stringOfCourses, ' ');

            if (job == Teachers)
                workers += new Teacher(firstName, lastName, yearsOfTeach, yearsOfManage, courses);
            else if (job == Tutors) {
                char layer;
                int classNum;
                file >> layer;
                file >> classNum;
                Class *tutorClass = layers[layer - 'a']->getClass(classNum - 1);
                workers += new Tutor(firstName, lastName, yearsOfTeach, yearsOfManage, courses,
                                     tutorClass);
            } else {
                string office;
                file >> office;
                workers += Manager::getInstance(firstName, lastName, yearsOfTeach, yearsOfManage, courses, office);
            }
        }
    }
    return true;
}

bool School::importWorkers(const string &path) {
    bool a = importWorkers(path + "Tutors.txt", Tutors);
    bool b = importWorkers(path + "Manager.txt", Managers);
    bool c = importWorkers(path + "Teachers.txt", Teachers);
    bool d = importWorkers(path + "Secretariat.txt", Secretariat);
    return a && b && c && d;
}

void School::printWorkers() {
    cout << "\tWorkers List:" << endl;
    workers.print();
}

void School::printStudents() {
    cout << "\tStudents List:" << endl;
    students.print();
}

void School::info() {
    cout << "****************************************" << endl;
    cout << "\tSTATISTICS OF THE SCHOOL:" << endl;
    cout << "Number Of Employees: " << workersSize() << endl;
    cout << "Average Salary: " << meanSalary() << " $" << endl;
    cout << "Median Salary: " << medianSalary() << " $" << endl;
    cout << "Top Worker:" << endl;
    if (topWorker()) topWorker()->info();
    cout << "----------------------------------------" << endl;
    cout << "Number Of Students: " << studentsSize() << endl;
    cout << "Average Grade: " << meanGPA() << endl;
    cout << "Median Grade: " << medianGPA() << endl;
    cout << "Top Student:" << endl;
    if (topStudent()) topStudent()->info();
    cout << "****************************************" << endl;
}


