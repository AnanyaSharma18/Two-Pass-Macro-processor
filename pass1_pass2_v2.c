#include<stdio.h>
#include<string.h>
#define MAX_INSTRUCTIONS 50
#define MAX_BODY_LENGTH 20
#define MAX_MACRO_LENGTH 50
char input[50];
// Macro definition table (MDT) entry structure
struct MDT {
    int index;
    char body[MAX_BODY_LENGTH];
} mdt[MAX_MACRO_LENGTH];

// Global variables to track MDT count
int mdtc = 1;
int mntc = 1;

void pass1() {
	int i;
    printf("MACRO definition:\n");
    // Loop until "MEND" is encountered
    while (strcmp(input, "MEND") != 0 && mdtc < MAX_MACRO_LENGTH)
	{
        // Copy instruction to MDT body
        strcpy(mdt[mdtc].body, input);
        mdt[mdtc].index = mdtc + 1; // Set the index
        // Increment MDT count
        mdtc++;
        // Read next input
        scanf("%s", input);
    }
    // Display the MDT
    printf("Macro Definition Table (MDT):\n");
    for (i = 0; i < mdtc; i++) 
	{
        printf("MDT: %d %s\n", mdt[i].index, mdt[i].body);
    }
}

int main() {
    int n,i;
    printf("Enter the number of instructions: ");
    scanf("%d", &n);

    // Clear input buffer
    while ((getchar()) != '\n');

    printf("Enter the instructions: \n");
    for ( i = 0; i < n; i++) {
        scanf("%s", input);
        pass1(); // Invoke pass1() function for processing macros
    }

    return 0;
}

