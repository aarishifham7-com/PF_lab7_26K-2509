#include <stdio.h>

int main() {
    int shifts[4][3];
    int target_idx;
    int new_row[3];

    printf("Enter production data for initial 3x3 matrix (Workstations x Shifts):\n");
    for (int i = 0; i < 3; i++) {
        printf("Workstation %d (3 shifts): ", i);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &shifts[i][j]);
        }
    }

    printf("\nEnter target row index for emergency insertion (0 to 3): ");
    scanf("%d", &target_idx);

    printf("Enter 3 production values for the new row: ");
    for (int j = 0; j < 3; j++) {
        scanf("%d", &new_row[j]);
    }

    for (int i = 3; i > target_idx; i--) {
        for (int j = 0; j < 3; j++) {
            shifts[i][j] = shifts[i - 1][j];
        }
    }

    for (int j = 0; j < 3; j++) {
        shifts[target_idx][j] = new_row[j];
    }

    printf("\n--- UPDATED 4x3 PRODUCTION MATRIX ---\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", shifts[i][j]);
        }
        printf("\n");
    }

    return 0;
}