#include <bits/stdc++.h>

using namespace std; 

unsigned int n_tests{}; 

int main(){
    cin >> n_tests; 

    for(int i=0; i<n_tests; i++){
        unsigned int n_students{}; 
        cin >> n_students;  

        vector<int> students_skills_count(n_students+1);

        for(int j=0; j<n_students; j++){
            int student_skill = 0; 
            cin >> student_skill; 
            students_skills_count[student_skill]++; 
        }
    }

    return 0; 
}
