#include <stdio.h>
#include <string.h>

#define MAX_MACRO_LENGTH 50
#define MAX_BODY_LENGTH 20
#define MAX_INSTRUCTIONS 50

// Macro definition table (MDT) entry structure
struct MDT {
    int index;
    char body[MAX_BODY_LENGTH];
} mdt[MAX_MACRO_LENGTH];

// Macro Name Table (MNT) entry structure
struct MNT {
    char name[MAX_BODY_LENGTH];
    int index;
} mnt[MAX_MACRO_LENGTH];

// Global variables to track MDT and MNT count
int mdtc = 0;
int mntc = 0;

// Function prototypes
void pass1();
void pass2();

int main() {
    // Pass 1: Process macro definitions
    pass1();

    // Pass 2: Process instructions and expand macros
    pass2();

    return 0;
}

// Pass 1: Macro definition and expansion
void pass1() {
    char input[MAX_BODY_LENGTH];
    int i;
    printf("Enter the macro definitions (MEND to end):\n");

    // Loop until "MEND" is encountered or MDT is full
    while (mdtc < MAX_MACRO_LENGTH) {
        printf("Enter macro name: ");
        scanf("%s", mnt[mntc].name);

        // Check for "MEND" to end macro definition
        if (strcmp(mnt[mntc].name, "MEND") == 0) {
            break;
        }

        // Store macro definition in MDT
        printf("Enter macro definition: ");
        scanf("%s", mdt[mdtc].body);
        mdt[mdtc].index = mdtc + 1;

        // Update MNT entry
        mnt[mntc].index = mdtc;
        
        // Increment MDT and MNT count
        mdtc++;
        mntc++;
    }

    printf("Macro Definition Table (MDT):\n");
    for ( i = 0; i < mdtc; i++) {
        printf("MDT: %d %s\n", mdt[i].index, mdt[i].body);
    }

    printf("Macro Name Table (MNT):\n");
    for ( i = 0; i < mntc; i++) {
        printf("MNT: %s %d\n", mnt[i].name, mnt[i].index);
    }
}

// Pass 2: Process instructions and expand macros
void pass2() {
    char input[MAX_BODY_LENGTH];
	int i,j;
    printf("Enter the instructions to process (END to end):\n");

    // Loop until "END" is encountered or maximum instructions
    for ( i = 0; i < MAX_INSTRUCTIONS; i++) {
        printf("Enter instruction %d: ", i + 1);
        scanf("%s", input);

        // Check for "END" to end instruction input
        if (strcmp(input, "END") == 0) {
            break;
        }

        // Check if the instruction is a macro
        for (j = 0; j < mntc; j++) {
            if (strcmp(input, mnt[j].name) == 0) {
                // Expand macro if found
                printf("Macro expanded: %s\n", mdt[mnt[j].index].body);
                break;
            }
        }
    }
}
