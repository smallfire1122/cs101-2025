#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int age;
    float salary;
    char name[20];
} employee_t;

void emp_info(employee_t emp) {
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %02f\n\n", emp.salary);
}

int emp_average_age(employee_t emp[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return sum / n;
}

void emp_writefile(employee_t emp[], int n) {
    FILE *fp = fopen("employee.bin", "wb");
    for (int i = 0; i < n; i++) {
        fwrite(emp + i, sizeof(employee_t), 1, fp);
    }
    fclose(fp);
}

void emp_readfile(employee_t emp[], int n) {
    FILE *fp = fopen("employee.bin", "rb");
    int i = 0;
    employee_t tmp;
    
    while (i < n && fread(&tmp, sizeof(employee_t), 1, fp)) {
        emp[i].id = tmp.id;
        emp[i].age = tmp.age;
        emp[i].salary = tmp.salary;
        strcpy(emp[i].name, tmp.name);
        i++;
    }

    fclose(fp);
}

int main() {
    employee_t emp[4];

    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "小火");

    emp[1].id = 2;
    emp[1].age = 46;
    emp[1].salary = 36000.0;
    strcpy(emp[1].name, "小水");

    emp[2].id = 3;
    emp[2].age = 33;
    emp[2].salary = 90000.0;
    strcpy(emp[2].name, "小土");

    emp[3].id = 4;
    emp[3].age = 29;
    emp[3].salary = 55000.0;
    strcpy(emp[3].name, "小金");

    emp_writefile(emp, 4);

    employee_t read_emp[4];
    emp_readfile(read_emp, 4);

    for (int i = 0; i < 4; i++) {
        emp_info(read_emp[i]);
    }

    printf("Employee average age: %d\n", emp_average_age(read_emp, 4));

    return 0;
}

