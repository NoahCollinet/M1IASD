#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define IS_NUM(c) (c >= '0' && c <= '9')

void parse(FILE *file, int *vertices, int **edges) {
  char c;

  while ((c = fgetc(file)) != EOF) {
    if (c == 'c') {
      while (c != '\n') {
        c = fgetc(file);
      }
    }

    if (c == 'p') {

      while (!IS_NUM(c)) {
        c = fgetc(file);
      }

      char num[20];
      int i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        ++i;
      }

      num[i] = '\0';

      printf("%s\n", num);
      edges = malloc(atoi(num) * sizeof(int *));
      c = fgetc(file);

      i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        ++i;
      }

      num[i] = '\0';
      printf("%s\n", num);

      vertices = malloc(atoi(num) * sizeof(int));

      while (c != '\n') {
        c = fgetc(file);
      }
    }
    int e = 0;

    if (c == 'e') {
      while (!IS_NUM(c)) {
        c = fgetc(file);
      }

      char num[20];
      int i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        ++i;
      }

      num[i] = '\0';
      printf("%s ", num);

      edges[e] = (int *)malloc(2 * sizeof(int));
      edges[e][0] = atoi(num);
      c = fgetc(file);

      i = 0;

      while (IS_NUM(c)) {
        num[i] = c;
        c = fgetc(file);
        ++i;
      }

      num[i] = '\0';
      printf("%s\n", num);

      edges[e][1] = atoi(num);

      while (c != '\n') {
        c = fgetc(file);
      }
      ++e;
    }
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
  // printf("%d\n", edges[1][0]);

  free(file);
  free(edges);
  free(vertices);

  return 0;
}
