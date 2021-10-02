// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
	int roll;
	string Name;
	string Dept;
	int Marks;
	Node* next;
};

// Stores the head of the Linked List
Node* head = new Node();

// Check Function to check that if
// Record Already Exist or Not
bool check(int x)
{
	// Base Case
	if (head == NULL)
		return false;

	Node* t = new Node;
	t = head;

	// Traverse the Linked List
	while (t != NULL) {
		if (t->roll == x)
			return true;
		t = t->next;
	}

	return false;
}

// Function to insert the record
void Insert_Record(int roll, string Name,
				string Dept, int Marks)
{
	// if Record Already Exist
	if (check(roll)) {
		cout << "Student with this "
			<< "record Already Exists\n";
		return;
	}

	// Create new Node to Insert Record
	Node* t = new Node();
	t->roll = roll;
	t->Name = Name;
	t->Dept = Dept;
	t->Marks = Marks;
	t->next = NULL;

	// Insert at Begin
	if (head == NULL
		|| (head->roll >= t->roll)) {
		t->next = head;
		head = t;
	}

	// Insert at middle or End
	else {
		Node* c = head;
		while (c->next != NULL
			&& c->next->roll < t->roll) {
			c = c->next;
		}
		t->next = c->next;
		c->next = t;
	}

	cout << "Record Inserted "
		<< "Successfully\n";
}

// Function to search record for any
// students Record with roll number
void Search_Record(int roll)
{
	// if head is NULL
	if (!head) {
		cout << "No such Record "
			<< "Avialable\n";
		return;
	}

	// Otherwise
	else {
		Node* p = head;
		while (p) {
			if (p->roll == roll) {
				cout << "Roll Nmuber\t"
					<< p->roll << endl;
				cout << "Name\t\t"
					<< p->Name << endl;
				cout << "Department\t"
					<< p->Dept << endl;
				cout << "Marks\t\t"
					<< p->Marks << endl;
				return;
			}
			p = p->next;
		}

		if (p == NULL)
			cout << "No such Record "
				<< "Avialable\n";
	}
}

// Function to delete record students
// record with given roll number
// if it exist
int Delete_Record(int roll)
{
	Node* t = head;
	Node* p = NULL;

	// Deletion at Begin
	if (t != NULL
		&& t->roll == roll) {
		head = t->next;
		delete t;

		cout << "Record Deleted "
			<< "Successfully\n";
		return 0;
	}

	// Deletion Other than Begin
	while (t != NULL && t->roll != roll) {
		p = t;
		t = t->next;
	}
	if (t == NULL) {
		cout << "Record does not Exist\n";
		return -1;
		p->next = t->next;

		delete t;
		cout << "Record Deleted "
			<< "Successfully\n";

		return 0;
	}
}

// Function to display the Student's
// Record
void Show_Record()
{
	Node* p = head;
	if (p == NULL) {
		cout << "No Record "
			<< "Available\n";
	}
	else {
		cout << "Index\tName\tCourse"
			<< "\tMarks\n";

		// Until p is not NULL
		while (p != NULL) {
			cout << p->roll << " \t"
				<< p->Name << "\t"
				<< p->Dept << "\t"
				<< p->Marks << endl;
			p = p->next;
		}
	}
}

// Driver code
int main()
{
	head = NULL;
	string Name, Course;
	int Roll, Marks;

	// Menu-driven program
	while (true) {
		cout << "\n\t\tWelcome to Student Record "
				"Management System\n\n\tPress\n\t1 to "
				"create a new Record\n\t2 to delete a "
				"student record\n\t3 to Search a Student "
				"Record\n\t4 to view all students "
				"record\n\t5 to Exit\n";
		cout << "\nEnter your Choice\n";
		int Choice;

		// Enter Choice
		cin >> Choice;
		if (Choice == 1) {
			cout << "Enter Name of Student\n";
			cin >> Name;
			cout << "Enter Roll Number of Student\n";
			cin >> Roll;
			cout << "Enter Course of Student \n";
			cin >> Course;
			cout << "Enter Total Marks of Student\n";
			cin >> Marks;
			Insert_Record(Roll, Name, Course, Marks);
		}
		else if (Choice == 2) {
			cout << "Enter Roll Number of Student whose "
					"record is to be deleted\n";
			cin >> Roll;
			Delete_Record(Roll);
		}
		else if (Choice == 3) {
			cout << "Enter Roll Number of Student whose "
					"record you want to Search\n";
			cin >> Roll;
			Search_Record(Roll);
		}
		else if (Choice == 4) {
			Show_Record();
		}
		else if (Choice == 5) {
			exit(0);
		}
		else {
			cout << "Invalid Choice "
				<< "Try Again\n";
		}
	}
	return 0;
}
