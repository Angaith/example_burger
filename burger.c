#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

// Function prototypes
void printBurger(int d, int t, int f);
void printSalad(int d);
void printDelivery(char *address);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("  ____  _    _ _____   _____ ______ _____  \n");
        printf(" |  _ \\| |  | |  __ \\ / ____|  ____|  __ \\ \n");
        printf(" | |_) | |  | | |__) | |  __| |__  | |__) |\n");
        printf(" |  _ <| |  | |  _  /| | |_ |  __| |  _  / \n");
        printf(" | |_) | |__| | | \\ \\| |__| | |____| | \\ \\ \n");
        printf(" |____/ \\____/|_|  \\_\\______|______|_|  \\_\\\n");
        printf("                                           \n");
        printf("Usage: mcd [burger|salad|delivery]\n");     
        return 1;
    }

    char *command = argv[1];
    int d_flag = 0, t_flag = 0, f_flag = 0;
    char *address = "your home";
    
    // Move optind past the command
    optind = 2;

    // Parse options based on the command
    if (strcmp(command, "burger") == 0 || strcmp(command, "salad") == 0) {
        int opt;
        while ((opt = getopt(argc, argv, "fdt")) != -1) {
            switch (opt) {
                case 'f':
                    f_flag = 1;
                    break;
                case 'd':
                    d_flag = 1;
                    break;
                case 't':
                    t_flag = 1;
                    break;
                default:
                    printf("Invalid option\n");
                    return 1;
            }
        }
        if (strcmp(command, "burger") == 0) {
            printBurger(d_flag, t_flag, f_flag);
        } else {
            printSalad(d_flag);
        }
    } else if (strcmp(command, "delivery") == 0) {
        static struct option long_options[] = {
            {"address", required_argument, 0, 'a'},
            {0, 0, 0, 0}
        };
        int long_index = 0;
        int opt;
        while ((opt = getopt_long(argc, argv, "", long_options, &long_index)) != -1) {
            if (opt == 'a') {
                address = optarg;
            }
        }
        printDelivery(address);
    } else {
        printf("Invalid command\n");
        return 1;
    }

    return 0;
}


void printBurger(int d, int t, int f) {
    printf("  ________  \n");
    printf(" /        \\ \n");
    printf("/----------\\ \n");
    printf("|   BURGER  |\n");
    printf("\\----------/ \n");
    printf(" \\________/  \n");

    if (d) {
        printf("    ||   \n");
        printf("  /----\\ \n");
        printf("  |COLA|\n");
        printf("  |    |\n");
        printf("  \\____/ \n");
    }
    
    if (f) {
        printf(" FRIES \n");
        printf(" ||||  \n");
        printf(" |  |  \n");
        printf(" |__|  \n");
    }

    if (t) {
        printf("  ________  \n");
        printf(" /        \\ \n");
        printf("/----------\\ \n");
        printf("|   BURGER  |\n");
        printf("\\----------/ \n");
        printf(" \\________/  \n");
    }
}

void printSalad(int d) {
    printf("  ^#^#^#^  \n");
    printf(" /------\\ \n");
    printf("| SALAD  |\n");
    printf(" \\______/ \n");

    if (d) {
        printf("    ||   \n");
        printf("  /----\\ \n");
        printf("  |COLA|\n");
        printf("  |    |\n");
        printf("  \\____/ \n");
    }
}

void printDelivery(char *address) {
    printf("    __o       \n");  
    printf(" _ \\\\<_        \n");  
    printf("(_)>(_)   ...............................................................(!)    \n");
    printf("The courier is on their way to %s.\n", address);
}
