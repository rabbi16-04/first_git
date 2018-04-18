#include<bits/stdc++.h>
using namespace std;

struct todo
{
	char time[100], task[100];
}; 

void addTask()
{
    ofstream fileWrite("tasks.txt", ios::app | ios::binary);
	struct todo myTask;
	cout << "Insert task: ";
	cin >> myTask.task;
	cout << "Insert time: ";
	cin >> myTask.time;

	fileWrite.write((char *) &myTask, sizeof(myTask));
	cout << "Added!\n";
	fileWrite.close();
}

void showTasks()
{
    
}