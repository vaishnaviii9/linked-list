#include<stdio.h>
#include<stdlib.h>

struct student {
    int sroll;
    char sgen;
    struct student *nexts;
};

void main() {
    struct student *ns, *first, *temp;
    char ch;

    first = NULL;

    do {
        ns = (struct student *)malloc(sizeof(struct student));
        printf("\nEnter roll number: ");
        scanf("%d", &ns->sroll);

        // Consume newline character
        getchar();

        printf("Enter gender: ");
        scanf("%c", &ns->sgen);

        ns->nexts = NULL;

        if (first == NULL) {
            first = ns;
        } else {
            temp = first;
            while (temp->nexts != NULL) {
                temp = temp->nexts;
            }
            temp->nexts = ns;
        }

        printf("\nDo you want to add another student? (y/n): ");
        scanf(" %c", &ch); // Note the space before %c to skip any whitespace characters

    } while (ch == 'y' || ch == 'Y');

    printf("\nStudent Details");
    temp = first;
    while (temp != NULL) {
        printf("\n%d is %c", temp->sroll, temp->sgen);
        temp = temp->nexts;
    }
}

