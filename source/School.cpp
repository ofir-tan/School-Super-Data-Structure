#include "School.h"

School::School(quantity numberOfLayers, quantity numberOfClasses) {
    vector<char> layerName = {'a', 'b', 'c', 'd', 'e', 'f'};
    for (int i = 0; i < numberOfLayers; i++) {
        layers.push_back(new Layer(layerName[i]));
        for (int j = 0; j < numberOfClasses; j++)
            layers[i]->addClass(new Class(layerName[i], j));
    }
}

School::~School() {
    cout << "~School" << endl;
    for (auto &layer: layers)
        delete layer;
}

School &School::getInstance(quantity numberOfLayers, quantity numberOfClasses) {

    static School bgu(numberOfLayers, numberOfClasses);
    return bgu;
}

void School::importStudents(const string &path) {

    ifstream file;
    file.open(path);

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
}

void School::importWorkers(const string &path, enum jobs job) {
    // Factory Design Pattern:
    WorkersFactory factory(path);
    Worker *newWorker;
    while (!factory.done()) {
        newWorker = factory.createWorker(job);
        newWorker->importData(factory.getFile());
        workers += newWorker;
    }
}

void School::importWorkers(const string &path) {
    importWorkers(path + "Tutors.txt", Tutors);
    importWorkers(path + "Manager.txt", Managers);
    importWorkers(path + "Teachers.txt", Teachers);
    importWorkers(path + "Secretariat.txt", Secretariat);
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
    cout << "\tTop Worker:" << endl;
    if (topWorker()) topWorker()->info();
    cout << "----------------------------------------" << endl;
    cout << "Number Of Students: " << studentsSize() << endl;
    cout << "Average Grade: " << meanGPA() << endl;
    cout << "Median Grade: " << medianGPA() << endl;
    cout << "\tTop Student:" << endl;
    if (topStudent()) topStudent()->info();
    cout << "****************************************" << endl;
}

vector<Student *> School::sortStudents(const function<int(Student *)> &func, int size) {
    // counting sort:
    vector<queue<Student *>> queues(size);
    vector<Student *> res;
    // push all the student into queues:
    for (const auto &[name, student]: students) {
        queues[func(student)].push(student);
    }

    for (int i = size - 1; i >= 0; i--) {
        while (!queues[i].empty()) {
            res.push_back(queues[i].front());
            queues[i].pop();
        }
    }
    return res;
}
