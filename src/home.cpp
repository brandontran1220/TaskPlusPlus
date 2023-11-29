#include "../headers/home.h"
#include "../headers/taskList.h"
#include "../headers/task.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void Home::createNewTask(const vector<string>& inputs) {
    Task* newTask = new Task;

    newTask->setName(inputs[0]);
    newTask->setPriority(inputs[1]);
    newTask->setFullDueDate(inputs[2]);
    newTask->setFullAssignedDate(inputs[3]);
    newTask->setDescription(inputs[4]);
    setClassification(newTask);
    setList(newTask, inputs[5]);
}

void Home::createNewList(const vector<string>& inputs) {
    TaskList* newList = new TaskList;

    newList->editListName(inputs[0]);
    newList->editListDescription(inputs[1]);

    overallLists.insert(newList);
}

void Home::viewLists() const {

}

void Home::editLists() const {

}

void Home::setList(Task* newTask, const string& selectedList) {
    if (selectedList == "") {
        soloTasks->addTask(newTask);
    } else {
        for (auto taskLists : overallLists) {
            if (taskLists->getListName() == selectedList) {
                taskLists->addTask(newTask);
            }
        }
    }
}

void Home::setClassification(Task* newTask) { 
    if (newTask->getFullDueDate() != "") {
        classificationTaskStorage["Dated"]->addTask(newTask);
    } else if (newTask->getFullDueDate() == "") {
        classificationTaskStorage["Undated"]->addTask(newTask);
    }
}

Task* Home::findSoloTask(const string& taskName) const {
    return soloTasks->findTask(taskName);
}

TaskList* Home::findTaskList(const string& listName) const {
    for (auto taskLists : overallLists) {
        if (taskLists->getListName() == listName) {
            return taskLists;
        }
    }
    return nullptr;
}

