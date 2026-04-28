#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

static long maxDepth = -1;

void tree(const char path[], long depth) {
    if (depth > maxDepth && maxDepth != -1) {
        return;
    }
    struct dirent *ent;
    DIR *dir = opendir(path);
    struct stat buf;
    char newPath[1024];

    while ((ent = readdir(dir)) != NULL) {

        for (int i = 0; i < depth; i++) {
            if (i == depth-1) {
                printf(" |- ");
                continue;
            }
            printf(" | ");

        }
        printf("%s\n", ent->d_name);

        snprintf(newPath, 1024, "%s/%s", path, ent->d_name);

        lstat(newPath, &buf);


        if (!S_ISDIR(buf.st_mode) || strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        tree(newPath, depth + 1);
    }

    closedir(dir);
}

int argParse(const char *firstArg, const char *secondArg) {

    if (firstArg == NULL) {
        return 0;
    }

    if (strcmp(firstArg, "--help") == 0 || strcmp(firstArg, "-h") == 0) {
        return 1;
    }

    if (secondArg == NULL) {
        return 0;
    }
    if (strcmp(firstArg, "--depth") == 0 || strcmp(firstArg, "-d") == 0) {
        char *endptr;

        long _ = strtol(secondArg, &endptr, 10);

        if (strcmp(endptr, "") != 0) {
            return -2;
        }

        return 2;
    }

    return 0;
}

void printHelp() {
    printf("OPTIONS:\n -h, --help: Displays this message \n -d, --depth [long maxDepth]: Max depth for the recursion \n");
}

int main(const int argc, char *argv[]) {
    char *firstArg = argc > 1 ? argv[1] : NULL;
    char *secondArg = argc > 2 ? argv[2] : NULL;
    char *thirdArg = argc > 3 ? argv[3] : NULL;
    char *path;
    long depth = -1;

    switch (argParse(firstArg, secondArg)) {
        case 1:
            printHelp();
            return 0;
        case 2:
            maxDepth = strtol(secondArg, NULL, 10);
            path = thirdArg == NULL ? "." : thirdArg;
            break;
        case -2:
            printf("%s\n", "Enter a valid number for depth");
            return 0;
        default:
            path = firstArg == NULL ? "." : firstArg;

    }

    printf("%s\n", path);
    tree(path, 1);
}
