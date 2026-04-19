#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_USERS 50
#define MAX_TASKS 50


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define WHITE "\033[37m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"


struct User {
    char username[50];
    char password[50];
};


struct Task {
    char name[100];
    char description[200];
    char deadline[50];
    char completionDate[50];
    int assignedUser;
    int status; 
};


struct User users[MAX_USERS];
int userCount = 0;

struct Task tasks[MAX_TASKS];
int taskCount = 0;


int sessionTaskStartIndex = 0;


void saveTasksToCSV() {
    FILE *file = fopen("tasks.csv", "w");
    if (!file) { printf(RED "Error saving tasks!\n" RESET); return; }

    fprintf(file, "Name,Description,Deadline,CompletionDate,AssignedUser,Status\n");
    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%s,%s,%s,%s,%d,%d\n",
            tasks[i].name,
            tasks[i].description,
            tasks[i].deadline,
            tasks[i].completionDate,
            tasks[i].assignedUser,
            tasks[i].status
        );
    }
    fclose(file);
}

void loadTasksFromCSV() {
    FILE *file = fopen("tasks.csv", "r");
    if (!file) return;

    taskCount = 0;
    char header[300];
    fgets(header, sizeof(header), file);

    while (fscanf(file, "%99[^,],%199[^,],%49[^,],%49[^,],%d,%d\n",
                  tasks[taskCount].name,
                  tasks[taskCount].description,
                  tasks[taskCount].deadline,
                  tasks[taskCount].completionDate,
                  &tasks[taskCount].assignedUser,
                  &tasks[taskCount].status) == 6) {
        taskCount++;
        if (taskCount >= MAX_TASKS) break;
    }

    fclose(file);
}


void saveUsersToCSV() {
    FILE *file = fopen("users.csv", "w");
    if (!file) { printf(RED "Error saving users!\n" RESET); return; }

    fprintf(file, "Username,Password\n");
    for (int i = 0; i < userCount; i++)
        fprintf(file, "%s,%s\n", users[i].username, users[i].password);

    fclose(file);
}

void loadUsersFromCSV() {
    FILE *file = fopen("users.csv", "r");

    if (!file) {
        strcpy(users[0].username, "john"); strcpy(users[0].password, "123");
        strcpy(users[1].username, "emma"); strcpy(users[1].password, "456");
        strcpy(users[2].username, "raj");  strcpy(users[2].password, "789");
        userCount = 3;
        saveUsersToCSV();
        return;
    }

    char header[100];
    fgets(header, sizeof(header), file);

    while (fscanf(file, "%49[^,],%49[^\n]\n",
                  users[userCount].username,
                  users[userCount].password) == 2) {
        userCount++;
        if (userCount >= MAX_USERS) break;
    }

    fclose(file);
}



void clearInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int validateRealDate(int d, int m, int y) {
    if (y < 1900 || y > 2100) return 0;
    if (m < 1 || m > 12) return 0;
    if (d < 1) return 0;

    int daysInMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && isLeapYear(y)) return d <= 29;
    return d <= daysInMonth[m];
}

void showUsers() {
    printf("\nAvailable Users:\n");
    for (int i = 0; i < userCount; i++)
        printf("%d. %s\n", i + 1, users[i].username);
}



void addTask() {
    if (taskCount >= MAX_TASKS) { printf(RED "\nTask limit reached!\n" RESET); return; }

    clearInput();
    printf("\nEnter Task Name: ");
    fgets(tasks[taskCount].name, sizeof(tasks[taskCount].name), stdin);
    tasks[taskCount].name[strcspn(tasks[taskCount].name, "\n")] = 0;

    printf("Enter Description: ");
    fgets(tasks[taskCount].description, sizeof(tasks[taskCount].description), stdin);
    tasks[taskCount].description[strcspn(tasks[taskCount].description, "\n")] = 0;

    int d, m, y;
    while (1) {
        printf("Enter Deadline (YYYY-MM-DD): ");
        if (scanf("%d-%d-%d", &y, &m, &d) != 3) {
            printf(RED "Invalid format! Try again.\n" RESET);
            clearInput();
            continue;
        }
        if (validateRealDate(d, m, y)) {
            sprintf(tasks[taskCount].deadline, "%04d-%02d-%02d", y, m, d);
            break;
        } else printf(RED "Invalid date! Enter a real calendar date.\n" RESET);
    }

    showUsers();
    int userChoice;
    printf("Select user number: ");
    scanf("%d", &userChoice);

    if (userChoice < 1 || userChoice > userCount) { 
        printf(RED "Invalid user!\n" RESET); 
        return; 
    }

    tasks[taskCount].assignedUser = userChoice - 1;
    strcpy(tasks[taskCount].completionDate, "N/A");
    tasks[taskCount].status = 0;
    taskCount++;

    saveTasksToCSV();
    printf(GREEN "\nTask added successfully!\n" RESET);
}

void showTasks() {
    printf(BOLD WHITE "\n=== TASKS FROM CURRENT SESSION ===\n" RESET);

    if (sessionTaskStartIndex == taskCount) {
        printf(YELLOW "\nNo tasks created during this session.\n" RESET);
        return;
    }

    int displayNum = 1;
    for (int i = sessionTaskStartIndex; i < taskCount; i++) {
        printf("\nTask %d\n", displayNum++);
        printf("Name: %s\n", tasks[i].name);
        printf("Description: %s\n", tasks[i].description);
        printf("Deadline: %s\n", tasks[i].deadline);
        printf("Assigned to: %s\n", users[tasks[i].assignedUser].username);
    }
}

int loginUser() {
    char uname[50], pass[50];

    clearInput();
    printf("\nUsername: ");
    fgets(uname, sizeof(uname), stdin);
    uname[strcspn(uname, "\n")] = 0;

    printf("Password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = 0;

    for (int i = 0; i < userCount; i++)
        if (strcmp(uname, users[i].username) == 0 && strcmp(pass, users[i].password) == 0)
            return i;

    return -1;
}

void showMyTasks(int uid) {
    printf(BOLD WHITE "\n=== MY CURRENT SESSION TASKS ===\n" RESET);

    int displayNum = 1, found = 0;
    for (int i = sessionTaskStartIndex; i < taskCount; i++) {
        if (tasks[i].assignedUser == uid) {
            found = 1;
            printf("\nTask %d\n", displayNum++);
            printf("Name: %s\n", tasks[i].name);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
        }
    }
    if (!found) printf(YELLOW "No session tasks assigned.\n" RESET);
}

void updateTask(int uid) {
    int list[MAX_TASKS], count = 0;

    printf(BOLD WHITE "\n=== UPDATE YOUR SESSION TASKS ===\n" RESET);
    for (int i = sessionTaskStartIndex; i < taskCount; i++) {
        if (tasks[i].assignedUser == uid) {
            printf("%d. %s (Deadline: %s)\n", count + 1, tasks[i].name, tasks[i].deadline);
            list[count++] = i;
        }
    }

    if (count == 0) { printf(YELLOW "No session tasks to update.\n" RESET); return; }

    int choice;
    printf("\nSelect task: ");
    scanf("%d", &choice);
    if (choice < 1 || choice > count) { printf(RED "Invalid choice.\n" RESET); return; }

    int index = list[choice - 1];
    int statusChoice;

    printf("\n1. Completed\n2. Not Completed\n3. Pending\nChoice: ");
    scanf("%d", &statusChoice);

    if (statusChoice == 1) {
        int d, m, y;
        clearInput();
        while (1) {
            printf("Completion date (YYYY-MM-DD): ");
            if (scanf("%d-%d-%d", &y, &m, &d) != 3) {
                printf(RED "Invalid format! Try again.\n" RESET);
                clearInput();
                continue;
            }
            if (validateRealDate(d, m, y)) {
                sprintf(tasks[index].completionDate, "%04d-%02d-%02d", y, m, d);
                break;
            } else printf(RED "Invalid date! Enter a real calendar date.\n" RESET);
        }
        if (strcmp(tasks[index].completionDate, tasks[index].deadline) > 0)
            printf(RED "\n⚠ Task completed LATE!\n" RESET);
        else
            printf(GREEN "\n✔ Task completed ON TIME!\n" RESET);

        tasks[index].status = 1;
    }
    else if (statusChoice == 2) tasks[index].status = 2;
    else if (statusChoice == 3) tasks[index].status = 0;
    else printf(RED "Wrong choice entered!\n" RESET);

    saveTasksToCSV();
}

void finalReport() {
    printf(BOLD WHITE "\n=== FINAL REPORT (Current Session Tasks Only) ===\n" RESET);

    if (sessionTaskStartIndex == taskCount) {
        printf(YELLOW "\nNo tasks created in this session.\n" RESET);
        return;
    }

    int displayNum = 1;
    for (int i = sessionTaskStartIndex; i < taskCount; i++) {
        printf("\nTask %d\n", displayNum++);
        printf("Name: %s\n", tasks[i].name);
        printf("Description: %s\n", tasks[i].description);
        printf("Deadline: %s\n", tasks[i].deadline);
        printf("Assigned to: %s\n", users[tasks[i].assignedUser].username);
        printf("Completion Date: %s\n", tasks[i].completionDate);

        printf("Status: ");
        if (tasks[i].status == 0) printf("Pending\n");
        else if (tasks[i].status == 1) printf("Completed\n");
        else printf("Not Completed\n");

        printf("----------------------------------\n");
    }
}

void userMenu(int uid) {
    int choice;
    do {
        printf(BOLD WHITE "\n--- USER MENU ---\n" RESET);
        printf(CYAN "1." RESET " View My Session Tasks\n");
        printf(CYAN "2." RESET " Update Session Task\n");
        printf(CYAN "3." RESET " Logout\n");
        printf(YELLOW "Choice: " RESET);
        
        scanf("%d", &choice);

        if (choice == 1) showMyTasks(uid);
        else if (choice == 2) updateTask(uid);
        else if (choice != 3) printf(RED "Wrong choice entered!\n" RESET);

    } while (choice != 3);
}

void createNewUser() {
    if (userCount >= MAX_USERS) { printf(RED "User limit reached!\n" RESET); return; }

    clearInput();

    printf("\nEnter New Username: ");
    fgets(users[userCount].username, 50, stdin);
    users[userCount].username[strcspn(users[userCount].username, "\n")] = 0;

    printf("Enter Password: ");
    fgets(users[userCount].password, 50, stdin);
    users[userCount].password[strcspn(users[userCount].password, "\n")] = 0;

    userCount++;
    saveUsersToCSV();
    printf(GREEN "User created successfully!\n" RESET);
}


void getTimestamp(char *buffer, int size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d_%H-%M-%S", t);
}

void createSessionFolder(char *folderPath, int size) {
    char *home = getenv("HOME");
    snprintf(folderPath, size, "%s/Documents/TaskManagerSessions", home);
    mkdir(folderPath);
}

void archiveSession() {
    char folderPath[300]; createSessionFolder(folderPath, sizeof(folderPath));
    char timestamp[100]; getTimestamp(timestamp, sizeof(timestamp));
    char archiveFile[400];
    snprintf(archiveFile, sizeof(archiveFile), "%s/session_%s.csv", folderPath, timestamp);

    FILE *src = fopen("tasks.csv", "r");
    if (!src) { printf(RED "No tasks.csv to archive.\n" RESET); return; }

    FILE *dest = fopen(archiveFile, "w");
    if (!dest) { 
        printf(RED "Cannot create archive.\n" RESET); 
        fclose(src);
        return;
    }

    char ch;
    while ((ch = fgetc(src)) != EOF) fputc(ch, dest);
    fclose(src); fclose(dest);

    printf(GREEN "\nSession archived:\n%s\n" RESET, archiveFile);
}


void roleMenu() {
    int choice;
    do {
        printf(BOLD WHITE "\n==== SELECT ROLE ====\n" RESET);
        printf(CYAN "1." RESET " Manager\n");
        printf(CYAN "2." RESET " Employee\n");
        printf(CYAN "3." RESET " Back\n");
        printf(YELLOW "Choice: " RESET);
        
        scanf("%d", &choice);

        if (choice == 1) {
            int mChoice;
            do {
                printf(BOLD WHITE "\n--- MANAGER MENU ---\n" RESET);
                printf(CYAN "1." RESET " Add Task\n");
                printf(CYAN "2." RESET " View Session Tasks\n");
                printf(CYAN "3." RESET " Back\n");
                printf(YELLOW "Choice: " RESET);
                
                scanf("%d", &mChoice);

                if (mChoice == 1) addTask();
                else if (mChoice == 2) showTasks();
                else if (mChoice != 3) printf(RED "Wrong choice entered!\n" RESET);

            } while (mChoice != 3);
        }
        else if (choice == 2) {
            int eChoice;
            do {
                printf(BOLD WHITE "\n--- EMPLOYEE MENU ---\n" RESET);
                printf(CYAN "1." RESET " Login\n");
                printf(CYAN "2." RESET " Create New User\n");
                printf(CYAN "3." RESET " Back\n");
                printf(YELLOW "Choice: " RESET);

                scanf("%d", &eChoice);

                if (eChoice == 1) {
                    int uid = loginUser();
                    if (uid == -1) printf(RED "Invalid login!\n" RESET);
                    else userMenu(uid);
                }
                else if (eChoice == 2) createNewUser();
                else if (eChoice != 3) printf(RED "Wrong choice entered!\n" RESET);

            } while (eChoice != 3);
        }
        else if (choice != 3) printf(RED "Wrong choice entered!\n" RESET);

    } while (choice != 3);
}


int main() {
    loadUsersFromCSV();
    loadTasksFromCSV();
    sessionTaskStartIndex = taskCount;

    int choice;
    do {
        printf(BOLD WHITE "\n==== MAIN MENU ====\n" RESET);
        printf(CYAN "1." RESET " Role Menu\n");
        printf(CYAN "2." RESET " Final Report\n");
        printf(CYAN "3." RESET " Exit\n");
        printf(YELLOW "Choice: " RESET);

        scanf("%d", &choice);

        if (choice == 1) roleMenu();
        else if (choice == 2) finalReport();
        else if (choice != 3) printf(RED "Wrong choice entered!\n" RESET);

    } while (choice != 3);

    saveTasksToCSV();
    archiveSession();

    return 0;
}