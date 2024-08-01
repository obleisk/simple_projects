#include <stdio.h>
#include <string.h>
int main() {
    int ns, nfs, nis, cur=0;
    int flag = 0;
    printf("Enter the no. of states: ");
    scanf("%d", &ns);
    printf("Enter the no. of final states: ");
    scanf("%d", &nfs);
    printf("Enter the no. of input symbols: ");
    scanf("%d", &nis);
    int finstates[nfs];
    char symbols[nis + 1];
    printf("Enter the final states: ");
    for (int i = 0; i < nfs; i++) {
        scanf("%d", &finstates[i]);
    }
    printf("Enter the input symbols as a string (e.g., ab, abc, 01, 012): ");
    scanf("%s", symbols);
    int trns[ns][nis];
    for (int i = 0; i < ns; i++) {
        for (int j = 0; j < nis; j++) {
            printf("Enter the trans. state from state Q%d and input %c: ", i, symbols[j]);
            scanf("%d", &trns[i][j]);
        }
    }
    printf("TRANSITION TABLE:\nSt.\t");
    for (int i = 0; i < nis; i++) {
        printf("%c\t", symbols[i]);
    }
    printf("\n");
    for (int i = 0; i < ns; i++) {
        printf("Q%d\t", i);
        for (int j = 0; j < nis; j++) {
            printf("%d\t", trns[i][j]);
        }
        printf("\n");
    }
    char inp[100];
    printf("Enter string to check: ");
    scanf("%s", inp);
    int l = strlen(inp);
    for (int i = 0; i < l; i++) {
        int found = 0;
        for (int j = 0; j < nis; j++) {
            if (inp[i] == symbols[j]) {
                printf("Q%d -> ", cur);
                cur = trns[cur][j];
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\nInvalid input character '%c' found. The input string isn't accepted by the DFA.\n", inp[i]);
            return 0;
        }
    }
    printf("Q%d\n", cur);
    for (int i = 0; i < nfs; i++) {
        if (cur == finstates[i]) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("The input string is accepted by the DFA.\n");
    } else {
        printf("The input string isn't accepted by the DFA.\n");
    }
    return 0;
}
