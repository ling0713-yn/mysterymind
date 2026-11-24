#include "main.hpp"

void searchLocation() {
int choice;
cout << "\n========== SEARCH LOCATIONS ==========\n";

for (int i = 0; i < EVIDENCE_COUNT; i++) {
cout << i + 1 << ". " << evidence[i].location;

if (evidence[i].collected) {
cout << " [Searched]";}
cout << endl;
}

cout << "0. Return\n";
cout << "\nSelect location: ";
choice = getChoice();

if (choice == 0) {
return; }

if (choice >= 1 && choice <= EVIDENCE_COUNT) {
int index = choice - 1;

if (evidence[index].collected) {
cout << "\nEvidence already collected.\n";
cout << "Evidence ID: "<< evidence[index].id << endl;
cout << "Description: " << evidence[index].description << endl;
}

else {
evidence[index].collected = true;
cout << "\nEvidence discovered!\n";
cout << "Evidence ID: " << evidence[index].id << endl;
cout << "Location: " << evidence[index].location << endl;
cout << "Description: " << evidence[index].description << endl;
cout << "\nAdded to evidence inventory.\n";
}
}

else {
cout << "\nInvalid location selection.\n"; }
}



void viewEvidence() {
int total = 0;
cout << "\n========== EVIDENCE INVENTORY ==========\n";

for (int i = 0; i < EVIDENCE_COUNT; i++) {
if (evidence[i].collected) {
cout << "\nEvidence ID: " << evidence[i].id << endl;
cout << "Location: " << evidence[i].location << endl;
cout << "Description: " << evidence[i].description << endl;
cout << "----------------------------------------\n";
total++;
}
}

if (total == 0) {
cout << "\nNo evidence collected yet.\n";}
cout << "\nEvidence collected: " << total << "/" << EVIDENCE_COUNT << endl;
}