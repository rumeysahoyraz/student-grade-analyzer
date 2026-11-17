#include <iostream>

using namespace std;

double calculateAverage(int[], int);
int findHighest(int[], int, int&);
int findLowest(int[],int,int&);
void countPassedAndFailed(int[],double,int,int&,int&);

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

    double average = calculateAverage(grades, students);
    cout << "\n\naverage: " << average;

    int a=0;
    int b=0;
    int maxGrade = findHighest(grades, students, a);
    int minGrade = findLowest(grades, students, b);
    
    cout << "\n\nhighest grade: " << names[a] << " (" << maxGrade << ")";
    cout << "\nlowest grade: " << names[b] << " (" << minGrade << ")";

    int pass = 0; 
    int fail = 0;

    countPassedAndFailed(grades, average, students, pass, fail);

    cout << "\n\npassed: " << pass;
    cout << "\nfailed: " << fail;

    cout << "\n\npassed students: ";

    for(int i = 0; i < students; i++){
        if(grades[i] >= average)
            cout << "\n" << names[i];
    }

    return 0;
}

double calculateAverage(int grades[], int students){
    int sum = 0;

    for(int i = 0; i < students; i++){
        sum += grades[i];
    }

    return (float)sum / students;
}

int findHighest(int grades[], int students, int &a){
    int maxGrade = grades[0];

    for(int i = 0; i < students-1; i++){
        if(maxGrade < grades[i+1]){
            maxGrade = grades[i+1];
            a = i+1;
        }
    }

    return maxGrade;
}

int findLowest(int grades[], int students, int &b){
    int minGrade = grades[0];

    for(int i = 0; i < students-1; i++){
        if(minGrade > grades[i+1]){
            minGrade = grades[i+1];
            b = i+1;
        }
    }

    return minGrade;
}

void countPassedAndFailed(int grades[], double average, int students, int &pass, int &fail){
    for(int i = 0; i < students; i++){
        if(grades[i] >= average)
            pass++;
        else   
            fail++;
    }
}