#include "main.hpp"

// Programmer: Pee Zhi Ling

int getChoice() {
    int choice;

    while (!(cin >> choice)) {

        cin.clear();

        cin.ignore(
            numeric_limits<streamsize>::max(), '\n'
        );

        cout << "Invalid input. Enter a number: ";
    }

    cin.ignore(
        numeric_limits<streamsize>::max(), '\n'
    );

    return choice;
}


void pauseScreen() {
    cout << "\nPress ENTER to continue...";
    cin.get();
}


void investigationMenu() {

    int choice;

    do {

        cout << "\n========================================\n";
        cout << "         INVESTIGATION MENU\n";
        cout << "========================================\n";

        cout << caseTitle << endl;

        cout << "\n1. View Case Briefing\n";
        cout << "2. View Suspect List\n";
        cout << "3. Interview Suspect\n";
        cout << "4. Search Location\n";
        cout << "5. View Evidence Inventory\n";
        cout << "6. Analyze Statements\n";
        cout << "7. View Incident Timeline\n";
        cout << "8. Submit Accusation\n";
        cout << "9. Save Investigation\n";
        cout << "10. Return to Main Menu\n";

        cout << "\nEnter your choice: ";
        choice = getChoice();

        switch (choice) {

            case 1:
                showBriefing();
                break;

            case 2:
                viewSuspects();
                break;

            case 3:
                interviewSuspect();
                break;

            case 4:
                searchLocation();
                break;

            case 5:
                viewEvidence();
                break;

            case 6:
                analyzeStatement();
                break;

            case 7:
                showTimeline();
                break;

            case 8:
                submitAccusation();
                break;

            case 9:
                saveGame();
                break;

            case 10:
                cout << "\nReturning to main menu...\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

        if (choice != 10) {
            pauseScreen();
        }

    } while (choice != 10);
}


void mainMenu() {

    int choice;

    do {

        cout << "\n========================================\n";
        cout << "       MYSTERY INVESTIGATION GAME\n";
        cout << "========================================\n";

        cout << "1. Start New Investigation\n";
        cout << "2. Load Saved Investigation\n";
        cout << "3. Game Instructions\n";
        cout << "4. Exit Game\n";

        cout << "\nEnter your choice: ";
        choice = getChoice();

        switch (choice) {

            case 1:
                selectCase();
                break;

            case 2:
                if (loadGame()) {
                    investigationMenu();
                }
                break;

            case 3:

                cout << "\n==============INSTRUCTIONS===============\n";

                cout << "1. Select a mystery case.\n";
                cout << "2. Read the case briefing.\n";
                cout << "3. Interview suspects.\n";
                cout << "4. Search locations for evidence.\n";
                cout << "5. Review collected evidence.\n";
                cout << "6. Identify contradictions.\n";
                cout << "7. Examine the incident timeline.\n";
                cout << "8. Submit your accusation.\n";
                cout << "9. Receive your investigation score.\n";
                cout << "10. Save progress if necessary.\n";

                pauseScreen();
                break;

            case 4:

                cout << "\nThank you for playing, Detective!\n";
                break;

            default:cout << "\nInvalid choice.\n";
        }

    } while (choice != 4);
}
 
int main() {

    mainMenu();

    return 0;
}