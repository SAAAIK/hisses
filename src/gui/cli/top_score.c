
#include "cli.h"

void printTopScores() {
  FILE *file = fopen("top.txt", "r");
  if (file == NULL) {
    mvprintw(12, BOARD_WIDTH * 2 + 4, "Unable to open the score file.\n");
    return;
  }

  ScoreEntry scores[100];
  int count = readScores(file, scores, 100);
  // fclose(file);

  qsort(scores, count, sizeof(ScoreEntry), compareScores);

  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK); // Определение цветовой пары №1:
                                        // красный текст на черном фоне

  attron(COLOR_PAIR(1)); // Включение цветовой пары №1
  mvprintw(11, BOARD_WIDTH * 2 + 4, "Top scores:\n");
  attroff(COLOR_PAIR(1)); // Выключение цветовой пары
  if (file != NULL) {
    for (int i = 0; i < 3 && i < count; i++) {
      mvprintw(13 + i, BOARD_WIDTH * 2 + 4, "%s %d", scores[i].name,
               scores[i].score);
    }

    fclose(file);
  }
}

int readScores(FILE *file, ScoreEntry scores[], int maxScores) {
  int count = 0;
  while (count < maxScores && fscanf(file, "%49s %d", scores[count].name,
                                     &scores[count].score) == 2) {
    count++;
  }
  return count; // Возвращает количество успешно прочитанных записей
}

int compareScores(const void *a, const void *b) {
  const ScoreEntry *entryA = (const ScoreEntry *)a;
  const ScoreEntry *entryB = (const ScoreEntry *)b;
  return entryB->score - entryA->score; // Сортировка по убыванию
}

void initPlayerScore(char *name) {
  FILE *file = fopen("top.txt", "a"); // Открытие файла для добавления
  if (file != NULL) {
    printf("%s", name);
    fprintf(file, "\n%s %d", name, 0); // Запись имени и 0 очков
    fclose(file);
  }
}

void updateLastLine(char *playerName, int score) {
  char lines[MAX_LINE_LENGTH]
            [LINE_LENGTH]; // Предположим, что в файле не более 1000 строк
  int lineCount = 0;

  // Открываем файл для чтения
  FILE *file = fopen("top.txt", "r");
  if (file == NULL) {
    // Не удалось открыть файл
    perror("Unable to open the score file");
    return;
  }

  // Читаем строки из файла в массив
  while (fgets(lines[lineCount], LINE_LENGTH, file) != NULL &&
         lineCount < MAX_LINE_LENGTH) {
    lineCount++;
  }
  fclose(file); // Закрываем файл после чтения

  // Открываем файл заново для записи, чтобы перезаписать его
  file = fopen("top.txt", "w");
  if (file == NULL) {
    // Не удалось открыть файл
    perror("Unable to open the score file for writing");
    return;
  }

  // Если в файле были строки, перезаписываем их все, кроме последней
  for (int i = 0; i < lineCount - 1; i++) {
    fprintf(file, "%s",
            lines[i]); // В lines[i] уже содержится символ новой строки
  }

  // Добавляем новую последнюю строку
  fprintf(file, "%s %d", playerName, score);

  fclose(file); // Закрываем файл после записи
}
