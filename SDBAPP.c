#include <stdio.h>
#include "SDB.h"
#include "STD.h"

//  to perform the chosen action
void SDB_action(uint8 choice) {
    uint32 id, year, course1_id, course1_grade, course2_id, course2_grade, course3_id, course3_grade;
    uint8 count;
    uint32 list[MAX_STUDENTS];

    if (choice == 1) {
        printf("Enter student ID: ");
        scanf("%u", &id);
        printf("----------------------------------------\n");
        printf("Enter student year: ");
        scanf("%u", &year);
        printf("----------------------------------------\n");
        printf("Enter course 1 ID : ");
        scanf("%u", &course1_id);
        printf("Enter grade 1 ID : ");
        scanf("%u", &course1_grade);
        printf("----------------------------------------\n");
        printf("Enter course 2 ID : ");
        scanf("%u", &course2_id);
        printf("Enter grade 2 ID : ");
        scanf("%u", &course2_grade);
        printf("----------------------------------------\n");
        printf("Enter course 3 ID : ");
        scanf("%u", &course3_id);
        printf("Enter grade 3 ID : ");
        scanf("%u", &course3_grade);
        if (SDB_AddEntry(id, year, course1_id, course1_grade, course2_id, course2_grade, course3_id, course3_grade)) {
            printf("********************* YOU ARE WELCOME IN BUTCHER SYSTEM *************** \n");
            printf("Student added successfully.\n");
        } else {
            printf("Failed to add student. ID might already exist or system is full.\n");
        }
    } else if (choice == 2) {
        printf("Used size: %u\n", SDB_GetUsedSize());
    } else if (choice == 3) {
        printf("Enter student ID to read: ");
        scanf("%u", &id);
        if (!SDB_ReadEntry(id)) {
            printf("Student ID not found.\n");
        }
    } else if (choice == 4) {
        SDB_GetList(&count, list);
        printf("Student IDs:\n");
        for (uint8 i = 0; i < count; i++) {
            printf("%u ", list[i]);
        }
        printf("\n");
    } else if (choice == 5) {
        printf("Enter student ID to check: ");
        scanf("%u", &id);
        if (SDB_IsIdExist(id)) {
            printf("Student ID exists.\n");
        } else {
            printf("Student ID not found.\n");
        }
    } else if (choice == 6) {
        printf("Enter student ID to delete: ");
        scanf("%u", &id);
        SDB_DeleteEntry(id);
        printf("Student deleted (if existed).\n");
    } else if (choice == 7) {
        if (SDB_IsFull()) {
            printf("Database is full.\n");
        } else {
            printf("Database is not full.\n");
        }
    } else if (choice == 0) {
        printf("Exiting application.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

// APPLICATION OF AMIT
void SDB_APP() {
    uint8 choice;

    while (1) {
        printf("--------------WELCOM TO BUTCHER SYSTEM---------------- ");
        printf("\nChoose an option:\n");
        printf("1. To add entry, enter 1\n");
        printf("2. To get used size in database, enter 2\n");
        printf("3. To read student data, enter 3\n");
        printf("4. To get the list of all student IDs, enter 4\n");
        printf("5. To check if ID exists, enter 5\n");
        printf("6. To delete student data, enter 6\n");
        printf("7. To check if database is full, enter 7\n");
        printf("0. To exit, enter 0\n");
        printf("Enter your choice: ");
        scanf("%u", &choice);

        SDB_action(choice);

        if (choice == 0) {
            break;
        }
    }
}

