#include <stdio.h>

int main() {
  int numStudents;
  printf("Enter the number of students: ");
  scanf("%d", &numStudents);

  float grades[numStudents]; // Array to store grades
  float sum = 0.0, average, highest, lowest;

  // Reading grades from the user
  for (int i = 0; i < numStudents; i++) {
    printf("Enter grade for student %d: ", i + 1);
    scanf("%f", &grades[i]);
    if(grades[i] > 100){
        printf("Invalid input! Grade must be between 0 and 100.\n");
        i--; // Skip invalid input
        continue; // Move to the next iteration
    }
    sum += grades[i]; // Accumulating sum for average calculation
  }

  // Initializing highest and lowest with the first grade
  highest = grades[0];
  lowest = grades[0];

  // Finding highest and lowest grades
  for (int i = 1; i < numStudents; i++) {
    if (grades[i] > highest) {
      highest = grades[i];
    }
    if (grades[i] < lowest) {
      lowest = grades[i];
    }
  }

  // Calculating average
  average = sum / numStudents;

  // Displaying the results
  printf("Average grade: %.2f\n", average);
  printf("Highest grade: %.2f\n", highest);
  printf("Lowest grade: %.2f\n", lowest);

  return 0;
}
