#include <iostream>

using namespace std;

int main(){
    cout << "===== Student Grade Analyzer =====";
    int students;
    cout << "\n\nenter number of students: ";
    cin >> students;

    string names[100];
    int grades[100];

    for(int i = 0; i < students; i++){
        cout << "\nenter " << i+1 <<  " student name: ";
        cin >> names[i];
        cout << "enter grade: ";
        cin >> grades[i];
    }


    cout << "\n===== Results =====\n";

    for(int i = 0; i < students; i++){
        cout << "\n" << names[i] << ": " << grades[i];
    }

    int sum = 0;

    for(int i = 0; i < students; i++){
        sum += grades[i];
    }

    float average = (float)sum / students;

    cout << "\n\naverage: " << average;

    int maxGrade = grades[0];
    int minGrade = grades[0];
    int a=0;
    int b=0;

    for(int i = 0; i < students-1; i++){
        if(maxGrade < grades[i+1]){
            maxGrade = grades[i+1];
            a=i+1;
        }

        if(minGrade > grades[i+1]){
            minGrade = grades[i+1];
            b=i+1;
        }
    }

    cout << "\n\nhighest grade: " << names[a] << " (" << maxGrade << ")";
    cout << "\nlowest grade: " << names[b] << " (" << minGrade << ")";

    int pass = 0; 
    int fail = 0;

    for(int i = 0; i < students; i++){
        if(grades[i] >= average)
            pass++;
        else   
            fail++;
    }

    cout << "\n\npassed: " << pass;
    cout << "\nfailed: " << fail;

    cout << "\n\npassed students: ";

    for(int i = 0; i < students; i++){
        if(grades[i] >= average)
            cout << "\n" << names[i];
    }

}