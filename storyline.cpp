#include "main.hpp"
// Programmer: Pee Zhi Ling
Suspect suspects[SUSPECT_COUNT];
Evidence evidence[EVIDENCE_COUNT];

bool interviewed[SUSPECT_COUNT] = {};
bool contradiction[CONTRADICTION_COUNT] = {};

int currentCase = 0;
int correctSuspect = 0;
int score = 0;

string caseTitle;
string caseLocation;
string caseTime;
string caseBriefing;


void resetGame() {

    score = 0;

    for (int i = 0; i < SUSPECT_COUNT; i++) {
        interviewed[i] = false; 
    }

    for (int i = 0; i < EVIDENCE_COUNT; i++) {
        evidence[i].collected = false;
    }

    for (int i = 0; i < CONTRADICTION_COUNT; i++) {
        contradiction[i] = false;
    }
}


void initializeCase(int caseNumber) {

    currentCase = caseNumber;

    switch (caseNumber) {

        // CASE 002

        case 2:

            caseTitle =
                "CASE 002: THE STOLEN DIAMOND";

            caseLocation =
                "Grand City Museum - Royal Vault";

            caseTime = "11:30 PM";

            caseBriefing =
                "The priceless Star of Malaya diamond\n"
                "has vanished during a private charity gala.\n\n"
                "Four individuals are under investigation.\n"
                "Identify the responsible person.";

            suspects[0] = {
                "S01", "Victoria", "Museum Curator",
                "I was hosting the keynote speech "
                "from 10:30 PM until midnight."
            };

            suspects[1] = {
                "S02", "Marcus", "Head of Security",
                "I was monitoring the CCTV feeds "
                "without leaving the Control Room."
            };

            suspects[2] = {
                "S03", "Elena", "VIP Art Collector",
                "I stayed at the Rooftop Terrace "
                "after 11:00 PM."
            };

            suspects[3] = {
                "S04", "Julian", "Catering Manager",
                "I stayed in the Kitchen from "
                "10:45 PM until 11:45 PM."
            };

            evidence[0] = {
                "E01", "Royal Vault",
                "A damaged display and torn black silk "
                "were discovered near the pedestal.",
                false
            };

            evidence[1] = {
                "E02", "Security Control Room",
                "An access record conflicts with "
                "Marcus's statement.",
                false
            };

            evidence[2] = {
                "E03", "Main Hall",
                "Livestream confirms Victoria was "
                "on stage throughout the incident.",
                false
            };

            evidence[3] = {
                "E04", "Rooftop Terrace",
                "Records support Elena's statement "
                "about visiting the terrace.",
                false
            };

            evidence[4] = {
                "E05", "Staff Locker Room",
                "An unidentified stain and missing "
                "personal item were reported.",
                false
            };

            evidence[5] = {
                "E06", "Kitchen",
                "Camera footage contradicts Julian's "
                "statement about remaining in the Kitchen.",
                false
            };

            correctSuspect = 4;

            break;

        // CASE 003

        case 3:

            caseTitle =
                "CASE 003: THE VANISHING EXAMINATION PAPER";

            caseLocation =
                "Faculty Exam Secretariat - Printing Room";

            caseTime = "04:30 PM";

            caseBriefing =
                "The master copy of an upcoming university\n"
                "examination paper has disappeared.\n\n"
                "Four individuals are under investigation.\n"
                "Identify the responsible person.";
            
            suspects[0] = {       
                "S01", "Dr. Lim", "Senior Lecturer",
                "I stayed in my office marking quiz "
                "scripts from 03:15 PM until 05:00 PM."
            };
           

            suspects[1] = {
                "S02", "Hafiz", "Printing Room Clerk",
                "I was calibrating the printer from "
                "03:30 PM until 04:15 PM."
            };

            suspects[2] = {
                "S03", "Nadia", "Department Secretary",
                "I was filing student forms at the "
                "front counter from 03:45 PM to 04:45 PM."
            };

            suspects[3] = {
                "S04", "Rakesh", "Lab and Exam Assistant",
                "I was delivering laboratory manuals "
                "around the faculty."
            };

            evidence[0] = {
                "E01", "Printing Room",
                "A printer record conflicts with "
                "Hafiz's statement.",
                false
            };

            evidence[1] = {"E02", "Clerk Tea Kiosk",
                "A receipt and CCTV snapshot show "
                "Hafiz at the kiosk at 03:55 PM.",
                false
            };

            evidence[2] = {
                "E03", "Lecturer Office",
                "Office records support Dr. Lim's "
                "statement.",
                false
            };

            evidence[3] = {
                "E04", "Front Counter",
                "Counter records support Nadia's "
                "statement.",
                false
            };

            evidence[4] = {
                "E05", "Corridor CCTV Terminal","Footage shows Rakesh carrying "
                "laboratory manuals.",
                false
            };

            evidence[5] = {
                "E06", "Print Spooler Log",
                "A printing record contradicts "
                "Hafiz's reported departure time.",
                false
            };

            correctSuspect = 2;

            break;

        default:

            cout << "Invalid case number.\n";
            return;
    }

    resetGame();
}


void showBriefing() {

    cout << "\n========================================\n";
    cout << caseTitle << endl;
    cout << "========================================\n";

    cout << "Location: " << caseLocation << endl;
    cout << "Time: " << caseTime << endl;
    cout << "Difficulty: Medium\n\n";

    cout << caseBriefing << endl;
}


void selectCase() {

    int choice;

    cout << "\n========== SELECT CASE ==========\n";

    cout << "2. The Stolen Diamond\n";
    cout << "3. The Vanishing Examination Paper\n";
    cout << "0. Return to Main Menu\n";

    cout << "\nSelect case: ";
    choice = getChoice();

    switch (choice) {

        case 2:
        case 3:initializeCase(choice);

            showBriefing();

            pauseScreen();

            investigationMenu();

            break;

        case 0:

            return;

        default:

            cout << "\nInvalid case selection.\n";
    }
}