#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void printCandidates(Candidate candidates[], int numCandidates) {
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}

int isDuplicateCandidate(Candidate candidates[], int numCandidates, char *name) {
    char lowerName[MAX_NAME_LENGTH];
    strcpy(lowerName, name);
    toLowerCase(lowerName);

    for (int i = 0; i < numCandidates; i++) {
        char lowerExistingName[MAX_NAME_LENGTH];
        strcpy(lowerExistingName, candidates[i].name);
        toLowerCase(lowerExistingName);
        if (strcmp(lowerExistingName, lowerName) == 0) {
            return 1;
        }
    }
    return 0;
}

void castVote(Candidate candidates[], int numCandidates, char *vote) {
    char lowerVote[MAX_NAME_LENGTH];
    strcpy(lowerVote, vote);
    toLowerCase(lowerVote);

    for (int i = 0; i < numCandidates; i++) {
        char lowerName[MAX_NAME_LENGTH];
        strcpy(lowerName, candidates[i].name);
        toLowerCase(lowerName);

        if (strcmp(lowerName, lowerVote) == 0) {
            candidates[i].votes++;
            return;
        }
    }
    printf("Invalid vote. Please try again.\n");
}

int compareCandidates(const void *a, const void *b) {
    const Candidate *candidateA = a;
    const Candidate *candidateB = b;

    char nameA[MAX_NAME_LENGTH];
    char nameB[MAX_NAME_LENGTH];
    strcpy(nameA, candidateA->name);
    strcpy(nameB, candidateB->name);
    toLowerCase(nameA);
    toLowerCase(nameB);

    return strcmp(nameA, nameB);
}

void storeVotes(Candidate candidates[], int numCandidates, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    qsort(candidates, numCandidates, sizeof(Candidate), compareCandidates);

    for (int i = 0; i < numCandidates; i++) {
        fprintf(file, "%s %d\n", candidates[i].name, candidates[i].votes);
    }
    fclose(file);
}

void findWinner(Candidate candidates[], int numCandidates) {
    int maxVotes = candidates[0].votes;
    int winnerIndex = 0;
    int tie = 0;

    for (int i = 1; i < numCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
            tie = 0;
        } else if (candidates[i].votes == maxVotes) {
            tie = 1;
        }
    }

    if (tie) {
        printf("It's a tie! The winners are:\n");
        for (int i = 0; i < numCandidates; i++) {
            if (candidates[i].votes == maxVotes) {
                printf("%s with %d votes\n", candidates[i].name, maxVotes);
            }
        }
    } else {
        printf("The winner is: %s with %d votes\n", candidates[winnerIndex].name, maxVotes);
    }
}

int hasVoted(char voters[][MAX_NAME_LENGTH], int numVoters, char *voterName) {
    char lowerVoterName[MAX_NAME_LENGTH];
    strcpy(lowerVoterName, voterName);
    toLowerCase(lowerVoterName);
    
    for (int i = 0; i < numVoters; i++) {
        char lowerRecordedName[MAX_NAME_LENGTH];
        strcpy(lowerRecordedName, voters[i]);
        toLowerCase(lowerRecordedName);
        if (strcmp(lowerRecordedName, lowerVoterName) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    char voters[MAX_VOTES][MAX_NAME_LENGTH];
    int numCandidates, numVoters = 0;

    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    for (int i = 0; i < numCandidates; i++) {
        char candidateName[MAX_NAME_LENGTH];
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidateName);

        while (isDuplicateCandidate(candidates, i, candidateName)) {
            printf("Candidate name already exists. Please enter a different name: ");
            scanf("%s", candidateName);
        }

        strcpy(candidates[i].name, candidateName);
        toLowerCase(candidates[i].name);  // Store the name in lowercase to maintain consistency
        candidates[i].votes = 0;
    }

    printf("The candidates are:\n");
    printCandidates(candidates, numCandidates);

    char voterName[MAX_NAME_LENGTH];
    char vote[MAX_NAME_LENGTH];
    for (int i = 0; i < MAX_VOTES; i++) {
        printf("Enter your name (or 'quit' to finish voting): ");
        scanf("%s", voterName);
        if (strcmp(voterName, "quit") == 0) {
            break;
        }
        if (hasVoted(voters, numVoters, voterName)) {
            printf("You have already voted. You cannot vote again.\n");
        } else {
            strcpy(voters[numVoters], voterName);
            numVoters++;
            printf("Enter your vote: ");
            scanf("%s", vote);
            castVote(candidates, numCandidates, vote);
        }
    }

    storeVotes(candidates, numCandidates, "votes.txt");

    findWinner(candidates, numCandidates);

    printf("Voting complete. Results are stored in votes.txt.\n");

    return 0;
}
