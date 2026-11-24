#include "main.hpp"

void viewSuspects() {

cout << "\n========== SUSPECT LIST ==========\n";
cout << left << setw(6) << "ID" << setw(15) << "Name" << setw(25) << "Occupation" << "Status" << endl;
cout << string(65, '-') << endl;

for (int i = 0; i < SUSPECT_COUNT; i++) {

cout << left << setw(6) << suspects[i].id << setw(15) << suspects[i].name << setw(25) << suspects[i].occupation;

if (interviewed[i]) {
cout << "Interviewed"; }

else {
cout << "Pending"; }
cout << endl; }

}




void interviewSuspect() {

int choice;

cout << "\n========== INTERVIEW SUSPECT ==========\n";

for (int i = 0; i < SUSPECT_COUNT; i++) {

cout << i + 1 << ". " << suspects[i].name;

if (interviewed[i]) {
cout << " [Interviewed]"; }

cout << endl;
}

cout << "0. Return\n";
cout << "\nSelect suspect: ";
choice = getChoice();

if (choice == 0) {
return; }

if (choice >= 1 && choice <= SUSPECT_COUNT) {
int index = choice - 1;
cout << "\n----------------------------------------\n";
cout << "Suspect ID: " << suspects[index].id << endl;
cout << "Name: " << suspects[index].name << endl;
cout << "Occupation: " << suspects[index].occupation << endl;
cout << "\nDetective: Where were you during " << "the incident?\n";
cout << suspects[index].name << ": \""<< suspects[index].statement << "\"\n";

if (interviewed[index]) {
cout << "\nStatement previously recorded.\n"; }

else {
interviewed[index] = true;
cout << "\nStatement successfully recorded!\n"; }


}

else {
cout << "\nInvalid suspect selection.\n"; }

}