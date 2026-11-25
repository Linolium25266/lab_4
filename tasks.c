#define _CRT_SECURE_NO_WARNINGS

#include "tasks.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define ZERO_TOLERANCE 1e-9
#define PI 3.14159265358979
#define MAX_STEPS 10

static void clearInput(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

static bool readInt(const char *prompt, int *value) {
  printf("%s", prompt);
  bool ok = scanf("%d", value) == 1;
  clearInput();
  return ok;
}

static bool readDouble(const char *prompt, double *value) {
  printf("%s", prompt);
  bool ok = scanf("%lf", value) == 1;
  clearInput();
  return ok;
}

static void printDomainError(void) {
  puts("the argument is outside the domain of the function's permissible "
       "values.");
}

void task2(void) {
  int number = 0;

  if (!readInt("enter number:", &number) || number <= 0) {
    printDomainError();
    return;
  }

  puts("the divisors:");

  for (int i = 1; i <= number; i++) {
    if (number % i == 0) {
      printf("%d\n", i);
    }
  }
}

void task51(void) {
  int n = 0;
  long long sum = 0;

  if (!readInt("enter n:", &n) || n < 1) {
    printDomainError();
    return;
  }

  for (long long i = n; i <= 2LL * n; i++) {
    sum += i * i;
  }

  printf("the sum: %lld\n", sum);
}

void task58(void) {
  double x = 2;
  printf("x:%g\n", x);

  double sum = 0;
  double power = x;

  for (int i = 1; i <= 11; i += 2) {
    sum += power / i;
    power *= x * x;
  }

  printf("the sum: %g\n", sum);
}

void task77(void) {
  double length = 4.5, distance = 3, step = 0.2;
  printf("length:%g\n", length);
  printf("distance:%g\n", distance);
  printf("step:%g\n", step);

  puts("distance from the wall | angle with the floor");

  for (int i = 0; distance + step * i <= length + ZERO_TOLERANCE; i++) {
    double x = distance + step * i;
    double angle = acos(x / length) * 180 / PI;

    printf("%.1f m | %.2f degrees\n", x, angle);
  }

  puts("then the ladder falls.");
}

void task113(void) {
  int k = 0;

  if (!readInt("enter k:", &k) || k <= 0) {
    printDomainError();
    return;
  }

  int rows = 0;

  printf("%5s%5s%7s%7s%7s\n", "m", "n", "a", "b", "c");

  for (int m = 2; m < k; m++) {
    for (int n = 2; n < m; n++) {
      int a = m * m - n * n;
      int b = 2 * m * n;
      int c = m * m + n * n;

      printf("%5d%5d%7d%7d%7d\n", m, n, a, b, c);
      rows++;
    }
  }

  if (rows == 0) {
    puts("there are no numbers for this k.");
  }
}

void task114(void) {
  int coupons[] = {10000, 1000, 500, 100, 50, 10, 5, 1};
  int size = sizeof(coupons) / sizeof(coupons[0]);
  int amount = 0;

  if (!readInt("enter C:", &amount) || amount <= 0) {
    printDomainError();
    return;
  }

  int kinds = 0;

  for (int i = 0; i < size; i++) {
    int count = amount / coupons[i];

    if (count > 0) {
      printf("coupon %d: %d pcs.\n", coupons[i], count);
      kinds++;
      amount %= coupons[i];
    }
  }

  printf("the number of different coupons: %d\n", kinds);
}

void task175(void) {
  int number = 0;
  long long product = 1;

  puts("enter positive integers, 0 ends the sequence.");

  if (!readInt("enter number:", &number) || number <= 0) {
    printDomainError();
    return;
  }

  puts("the result:");

  while (number != 0) {
    product *= number;
    printf("%lld\n", product);

    if (!readInt("enter number:", &number) || number < 0) {
      puts("the numbers must be positive.");
      return;
    }
  }

  puts("0");
}

void task210(void) {
  double epsilon = 0;

  if (!readDouble("enter epsilon:", &epsilon) || epsilon <= 0) {
    printDomainError();
    return;
  }

  double previous = 0, current = 0;
  int n = 1;

  printf("a%d = %.10f\n", n, current);

  do {
    previous = current;
    current = atan(previous) + 1;
    n++;
    printf("a%d = %.10f\n", n, current);
  } while (fabs(current - previous) >= epsilon);

  printf("the smallest n: %d\n", n);
}

void task219(void) {
  double x = 0, epsilon = 0;

  if (!readDouble("enter x:", &x) || !readDouble("enter epsilon:", &epsilon) ||
      fabs(x) < ZERO_TOLERANCE || epsilon <= 0) {
    printDomainError();
    return;
  }

  double previous = x, current = x;
  int n = 1;

  printf("a%d = %g\n", n, current);

  do {
    previous = current;
    current = x / (2 * previous * previous);
    n++;
    printf("a%d = %g\n", n, current);
  } while (fabs(current - previous) >= epsilon && n < MAX_STEPS);

  if (fabs(current - previous) < epsilon) {
    printf("the smallest n: %d\n", n);
  } else {
    puts("the required accuracy isn't reached.");
  }
}

void task266(void) {
  int number = 0;

  if (!readInt("enter number:", &number) || number <= 0) {
    printDomainError();
    return;
  }

  int leading = number;

  while (leading >= 10) {
    leading /= 10;
  }

  int count = 0;
  int rest = number;

  while (rest > 0) {
    if (rest % 10 == leading) {
      count++;
    }
    rest /= 10;
  }

  printf("the leading digit is %d, it occurs %d time(s).\n", leading, count);
}
