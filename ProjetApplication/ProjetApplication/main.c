//
//  main.c
//  ProjetApplication
//
//  Created by Kylian on 23/11/2023.
//

// Un menu qui demande d'ajouter une tache
// Un menu qui Afficher les taches
// Un menu qui fais terminer une taches
// Un menu qui fait tout quitter
    
#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100

struct Task {
    int id;
    char description[100];
    int status; // 0: Non terminée, 1: Terminée
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

// Fonction pour ajouter une tâche
void addTask(char *description) {
    if (taskCount < MAX_TASKS) {
        tasks[taskCount].id = taskCount + 1;
        strcpy(tasks[taskCount].description, description);
        tasks[taskCount].status = 0; // La tâche est initialisée comme non terminée
        taskCount++;
        printf("Tâche ajoutée avec succès.\n");
    } else {
        printf("La limite de tâches a été atteinte.\n");
    }
}

// Fonction pour afficher toutes les tâches
void displayTasks(void) {
    printf("Liste des tâches :\n");
    printf("ID\tDescription\t\tStatut\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d\t%s\t\t%s\n", tasks[i].id, tasks[i].description, tasks[i].status ? "Terminée" : "Non terminée");
    }
}

// Fonction pour marquer une tâche comme terminée
void completeTask(int taskId) {
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].id == taskId) {
            tasks[i].status = 1;
            printf("Tâche marquée comme terminée avec succès.\n");
            return;
        }
    }
    printf("ID de tâche invalide.\n");
}

int main(void) {
    int choice;
    char description[100];

    do {
        printf("\nGestionnaire de tâches\n");
        printf("1. Ajouter une tâche\n");
        printf("2. Afficher les tâches\n");
        printf("3. Marquer une tâche comme terminée\n");
        printf("0. Quitter\n");

        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Description de la tâche : ");
                getchar(); // Pour consommer le caractère de nouvelle ligne laissé par scanf
                fgets(description, sizeof(description), stdin);
                description[strlen(description) - 1] = '\0'; // Supprimer le caractère de nouvelle ligne
                addTask(description);
                break;

            case 2:
                displayTasks();
                break;

            case 3:
                printf("ID de la tâche à marquer comme terminée : ");
                int taskId;
                scanf("%d", &taskId);
                completeTask(taskId);
                break;

            case 0:
                printf("Au revoir !\n");
                break;

            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choice != 0);

    return 0;
}
