#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char name[50];
    int score;
    struct student *next;
};

struct student *head = NULL;

void add(const char *name, int score) {
    struct student *newNode = (struct student *)malloc(sizeof(struct student));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct student *cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = newNode;
    }
}

void delete(const char *name) {
    struct student *cur = head, *prev = NULL;
    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) head = cur->next;
            else prev->next = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

void print_list() {
    struct student *cur = head;
    while (cur != NULL) {
        printf("%s %d\n", cur->name, cur->score);
        cur = cur->next;
    }
}

void quit() {
    struct student *cur = head;
    while (cur != NULL) {
        struct student *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    head = NULL;
}

int main() {
    char command[20], name[50];
    int score;

    while (1) {
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } else if (strcmp(command, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        } else if (strcmp(command, "print") == 0) {
            print_list();
        } else if (strcmp(command, "quit") == 0) {
            quit();
            break;
        }
    }

    return 0;
}
