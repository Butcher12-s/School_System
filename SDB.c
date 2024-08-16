
#include <stdio.h>
#include "SDB.h"
#include "STD.h"
// Array OF students
student students[MAX_STUDENTS];
uint8 Number_oF_Students = 0;
// to check the system full or not
bool SDB_IsFull()
{
    if (Number_oF_Students >= MAX_STUDENTS)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// To display the number of Students in system
uint8 SDB_GetUsedSize()
{
    return Number_oF_Students;
}
// Check if a student ID exists
bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < Number_oF_Students; i++) {
        if (students[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}

// to add New student to system
bool SDB_AddEntry(uint32 id, uint32 year, uint32 course1_id, uint32 course1_grade, uint32 course2_id, uint32 course2_grade, uint32 course3_id, uint32 course3_grade)
{
    // first check the system is full or not to add
    if (SDB_IsFull())
    {printf("SORRY...... the system is full.. your id not saved \n");
        return false; // the system is full
    }// second check if id is already enterd
    if(SDB_IsIdExist( id)){printf("SORRY...... this id is alerady saved your data not save in system (CHANGE ID) \n");
        return false;

    }
    // After check the user enter his info.
    students[Number_oF_Students].Student_ID = id;
    students[Number_oF_Students].Student_year = year;
    students[Number_oF_Students].Course1_ID = course1_id;
    students[Number_oF_Students].Course1_grade = course1_grade;
    students[Number_oF_Students].Course2_ID = course2_id;
    students[Number_oF_Students].Course2_grade = course2_grade;
    students[Number_oF_Students].Course3_ID = course3_id;
    students[Number_oF_Students].Course3_grade = course3_grade;
    // then the number of students increse by one
    Number_oF_Students++;
    return true;
}
// if want to delete student

void SDB_DeleteEntry(uint32 id) {// check the number of students more or less min number{3}
    if(Number_oF_Students > MIN_STUDENTS){


    for (uint8 i = 0; i < Number_oF_Students; i++) {
        if (students[i].Student_ID == id) {
             // to rearrange the Arry of students After deleted
            for (uint8 j = i; j < Number_oF_Students - 1; j++) {
                students[j] = students[j + 1];
            }
            Number_oF_Students--;
            break;
        }
    }
    }else{
        return false;
    }
}
// to read info by enter id
bool SDB_ReadEntry(uint32 id) {
    for (uint8 i = 0; i < Number_oF_Students; i++) {
        if (students[i].Student_ID == id) {
            printf("Student ID: %u\n", students[i].Student_ID);
            printf("Student Year: %u\n", students[i].Student_year);
            printf("Course 1 ID: %u \n", students[i].Course1_ID);
            printf("Grade 1 ID: %u \n", students[i].Course1_grade);
            printf("Course 2 ID: %u\n", students[i].Course2_ID);
            printf("Grade 2 ID: %u\n", students[i].Course2_grade);
            printf("Course 3 ID: %u\n", students[i].Course3_ID);
            printf("Grade 3 ID: %u\n", students[i].Course3_grade);
            return true;
        }
    }
    return false;
} // Get the list of student IDs
void SDB_GetList(uint8 *count, uint32 *list) {
    *count = Number_oF_Students;
    for (uint8 i = 0; i < Number_oF_Students; i++) {
        list[i] = students[i].Student_ID;
    }
}


