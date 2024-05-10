#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Patient {
 string name;
 int priority;
 bool operator<(const Patient& other) const {
 return priority > other.priority; // Higher priority patients are served first
 }
};
int main() {
 priority_queue<Patient> hospitalQueue;
 int numPatients;
 cout << "Enter the number of patients: ";
 cin >> numPatients;
 cin.ignore(); // Clear the newline character from the input buffer
 for (int i = 0; i < numPatients; ++i) {
 Patient patient;
 cout << "Enter patient's name: ";
 getline(cin, patient.name);
 cout << "Enter patient's priority (1: Serious, 2: Non-serious, 3: General Checkup): ";
 cin >> patient.priority;
 cin.ignore(); // Add this line to clear the newline character after reading the priority
 hospitalQueue.push(patient);
 }
 cout << "\nPatients being served:\n";
 while (!hospitalQueue.empty()) {
 Patient servedPatient = hospitalQueue.top();
 hospitalQueue.pop();
 cout << "Serving patient: " << servedPatient.name << endl;
 }
 return 0;
}