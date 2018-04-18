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
    ifstream fileRead("tasks.txt", ios::in | ios::binary);
	if(!fileRead)
	{
		cout << "Cannot open file\n";
		exit(EXIT_FAILURE);
	}
	struct todo myTask;
	int i = 1;
	while((fileRead.read((char *) &myTask, sizeof(struct todo))) != NULL)
	{
		cout << i++ << ": ";
		cout << myTask.task << endl; 
		cout << "Time: " << myTask.time << endl;
		cout << endl;
	}
	cout << endl;
	fileRead.close();
}

void deleteTask()
{
    
}

int main()
{
	while(true)
	{
		cout << "a) Add Tasks\n";
		cout << "c) Show Tasks\n";
		cout << "b) Delete Tasks\n";
		cout << "d) Exit\n";

		char option;
		cin >> option;

		switch(option)
		{
			case('d'):
				exit(EXIT_SUCCESS);
			case('c'):
				showTasks();
				break;
			case('b'):
				deleteTask();
				break;
			case('a'):
				addTask();
				break;
			default:
				cout << "Invalid option!\n";
		}
	}
	return 0;
}