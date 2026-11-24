#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

const int SUSPECT_COUNT = 4;
const int EVIDENCE_COUNT = 6;
const int CONTRADICTION_COUNT = 2;

struct Suspect {
    string id;
    string name;
    string occupation;
    string statement;
};

struct Evidence {
    string id;
    string location;
    string description;
    bool collected;
};

// Shared variables
extern Suspect suspects[SUSPECT_COUNT];
extern Evidence evidence[EVIDENCE_COUNT];

extern bool interviewed[SUSPECT_COUNT];
extern bool contradiction[CONTRADICTION_COUNT];

extern int currentCase;
extern int correctSuspect;
extern int score;

extern string caseTitle;
extern string caseLocation;
extern string caseTime;
extern string caseBriefing;

// Main system
int getChoice();
void pauseScreen();
void mainMenu();
void investigationMenu();

// Storyline management
void selectCase();
void initializeCase(int caseNumber);
void resetGame();
void showBriefing();

// Suspect and evidence
void interviewSuspect();
void viewSuspects();
void searchLocation();
void viewEvidence();

//  Analysis
void analyzeStatement();
void showTimeline();

// Scoring and file handling
void submitAccusation();
void calculateScore(bool suspectCorrect,bool evidenceCorrect);

void saveGame();
bool loadGame();

#endif