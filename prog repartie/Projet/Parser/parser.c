#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define IS_NUM(c) (c >= '0' && c <= '9')

void parse(FILE *file, int *vertices, int **edges) {
  char c;

  while ((c = fgetc(file)) != EOF) {
    printf("%c", c);
    if (c == 'c') {
      while (c != '\n') {
        c = fgetc(file);
        printf("%c", c);
      }
    }

    if (c == 'p') {

      while (!IS_NUM(c)) {
        c = fgetc(file);
        printf("%c here", c);
      }

      char num[20];
      int i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        printf("%c", c);
        ++i;
      }

      num[i] = '\0';

      edges = malloc(atoi(num) * sizeof(int *));
      c = fgetc(file);
      printf("%c", c);

      i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        printf("%c", c);
        ++i;
      }

      num[i] = '\0';

      vertices = malloc(atoi(num) * sizeof(int));

      while (c != '\n') {
        c = fgetc(file);
        printf("%c", c);
      }
    }
  }

  int e = 0;

  if (c == 'e') {
    while (!IS_NUM(c)) {
      c = fgetc(file);
      printf("%c", c);
    }

    char num[20];
    int i = 0;

    while (IS_NUM(c)) {
      num[i] = c;
      c = fgetc(file);
      printf("%c", c);
      ++i;
    }

    num[i] = '\0';

    edges[e] = (int *)malloc(2 * sizeof(int));
    edges[e][0] = atoi(num);
    c = fgetc(file);
    printf("%c", c);

    i = 0;

    while (IS_NUM(c)) {
      num[i] = c;
      c = fgetc(file);
      printf("%c", c);
      ++i;
    }

    num[i] = '\0';

    edges[e][1] = atoi(num);

    while (c != '\n') {
      c = fgetc(file);
      printf("%c", c);
    }
    ++e;
  }
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    fprintf(stderr, "USAGE: %s <input name>", argv[0]);
    return 1;
  }

  FILE *file = fopen(argv[1], "r");

  int *vertices, **edges;

  parse(file, vertices, edges);

  // printf("%d\n", vertices[0]);
  printf("%d\n", edges[1][0]);

  free(file);
  free(edges);
  free(vertices);

  return 0;
}
