
#include <stdio.h>

#define TOTAL_MISSIONS 5

struct Mission {
    char name[50];
    int xp;
    int completed;
};

int main(void)
{
    struct Mission missions[TOTAL_MISSIONS] = {
        {"Study for 30 minutes", 20, 0},
        {"Practice C programming", 30, 0},
        {"Read 10 pages", 15, 0},
        {"Exercise for 15 minutes", 20, 0},
        {"Plan tomorrow's tasks", 15, 0}
    };

    int choice, i, totalXP, completed;
    int running = 1;

    while (running) {
        totalXP = 0;
        completed = 0;

        printf("\n===== SYSTEM ZERO =====\n");
        printf("1. View Missions\n");
        printf("2. Complete Mission\n");
        printf("3. View Progress\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
        case 1:
            for (i = 0; i < TOTAL_MISSIONS; i++) {
                printf("%d. %s - %d XP [%s]\n",
                    i + 1,
                    missions[i].name,
                    missions[i].xp,
                    missions[i].completed
                        ? "DONE" : "PENDING");
            }
            break;

        case 2:
            printf("Enter mission number (1-5): ");

            if (scanf("%d", &choice) != 1) {
                printf("Invalid input!\n");
                return 1;
            }

            if (choice < 1 || choice > TOTAL_MISSIONS) {
                printf("Invalid mission number!\n");
            } else if (missions[choice - 1].completed) {
                printf("Mission already completed!\n");
            } else {
                missions[choice - 1].completed = 1;
                printf("Mission completed! +%d XP\n",
                    missions[choice - 1].xp);
            }
            break;

        case 3:
            for (i = 0; i < TOTAL_MISSIONS; i++) {
                if (missions[i].completed) {
                    totalXP += missions[i].xp;
                    completed++;
                }
            }

            printf("Completed: %d/%d\n",
                completed, TOTAL_MISSIONS);
            printf("Progress: %.0f%%\n",
                completed * 100.0 / TOTAL_MISSIONS);
            printf("Total XP: %d\n", totalXP);
            break;

        case 4:
            running = 0;
            printf("SYSTEM ZERO shutting down...\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
