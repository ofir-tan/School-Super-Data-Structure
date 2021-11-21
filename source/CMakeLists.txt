cmake_minimum_required(VERSION 3.20)
project(Project)

set(CMAKE_CXX_STANDARD 17)
# SPECIFY YOUR PROJECT NAME
PROJECT(Project_Name)

add_executable(Project main.cpp Worker.h Person.h Student.h Secretary.h AdministrativeMan.h
       Teacher.h Teacher.cpp Tutor.cpp Tutor.h Class.cpp Class.h Manager.cpp Manager.h treeAnalyser.cpp
        Layer.h Layer.cpp Worker.cpp Student.cpp Secretary.cpp AdministrativeMan.cpp School.h School.cpp
        treeAnalyser.h Enums.h AuxiliaryFunctions.h AuxiliaryFunctions.cpp Comparators.h PriorityQueue.cpp
        PriorityQueue.h MedianFinder.cpp MedianFinder.h Trie.cpp Trie.h TrieNode.cpp TrieNode.h WorkersFactory.h)
