//#include <iostream>
//#include <omp.h>
//
//#define MAX_EMPLOYEE    10000000
//
//enum class Co {
//    Company1, Company2
//};
//
//int fetchTheSalary(const int employee,
//    const Co company) {
//    if (company == Co::Company1) {
//        return (employee < 100) ? 99340 : 54300;
//    }
//    else {
//        return (employee < 1000) ? 88770 : 57330;
//    }
//}
//
//void P5Q1() {
//    int salaries1 = 0;
//    int salaries2 = 0;
//    double runtime;
//    runtime = omp_get_wtime();
//
//    for (int employee = 0; employee < MAX_EMPLOYEE; employee++) {
//        salaries1 += fetchTheSalary(employee, Co::Company1);
//    }
//    std::cout << "Salaries1: " << salaries1 << std::endl;
//
//    for (int employee = 0; employee < MAX_EMPLOYEE; employee++) {
//        salaries2 += fetchTheSalary(employee, Co::Company2);
//    }
//    std::cout << "Salaries2: " << salaries2 << std::endl;
//
//    runtime = omp_get_wtime() - runtime;
//    std::cout << "Ori execute in " << runtime << "seconds\n\n";
//}
//
//
//void P5Q1a() {
//    int salaries1 = 0;
//    int salaries2 = 0;
//    double runtime;
//    runtime = omp_get_wtime();
//
//#pragma omp parallel shared(salaries1, salaries2)
//    {
//#pragma omp for reduction(+:salaries1)
//        for (int employee = 0; employee < MAX_EMPLOYEE; employee++) {
//            salaries1 += fetchTheSalary(employee, Co::Company1);
//        }
//#pragma omp critical
//        std::cout << "Salaries1: " << salaries1 << std::endl;
//#pragma omp for reduction(+:salaries2)
//        for (int employee = 0; employee < MAX_EMPLOYEE; employee++) {
//            salaries2 += fetchTheSalary(employee, Co::Company2);
//        }
//#pragma omp critical
//        std::cout << "Salaries2: " << salaries2 << std::endl;
//    }
//
//    
//
//    runtime = omp_get_wtime() - runtime;
//    std::cout << "Modified execute in " << runtime << "seconds\n\n";
//}
//
//void P5Q2() {
//    int salaries1 = 0;
//    int salaries2 = 0;
//    double runtime;
//    runtime = omp_get_wtime();
//
//#pragma omp parallel shared(salaries1, salaries2)
//    {
//#pragma omp for reduction(+:salaries1, salaries2)
//        for (int employee = 0; employee < MAX_EMPLOYEE; employee++) {
//            salaries1 += fetchTheSalary(employee, Co::Company1);
//            salaries2 += fetchTheSalary(employee, Co::Company2);
//        }
//    }
//    std::cout << "Salaries1: " << salaries1 << std::endl;
//    std::cout << "Salaries2: " << salaries2 << std::endl;
//
//
//
//    runtime = omp_get_wtime() - runtime;
//    std::cout << "Modified execute in " << runtime << "seconds\n\n";
//}
//
//void P5Q3() {
//    int salaries1 = 0;
//    int salaries2 = 0;
//    double runtime;
//    runtime = omp_get_wtime();
//
//#pragma omp parallel shared(salaries1, salaries2)
//    {
//#pragma omp for reduction(+:salaries1)
//        for (int employee = 0; employee < MAX_EMPLOYEE; employee++) {
//            salaries1 += fetchTheSalary(employee, Co::Company1);
//        }
//#pragma omp single
//        std::cout << "Salaries1: " << salaries1 << std::endl;
//#pragma omp for reduction(+:salaries2)
//        for (int employee = 0; employee < MAX_EMPLOYEE; employee++) {
//            salaries2 += fetchTheSalary(employee, Co::Company2);
//        }
//#pragma omp single
//        std::cout << "Salaries2: " << salaries2 << std::endl;
//    }
//
//    runtime = omp_get_wtime() - runtime;
//    std::cout << "Modified execute in " << runtime << "seconds\n\n";
//}
//
//int check_OMP_support() {
//    bool error = false;
//#pragma omp parallel
//    {
//#pragma omp single
//        {
//            int nthreads = omp_get_num_threads();
//            std::cout << "The total num of threads is " << nthreads << std::endl;
//            if (nthreads < 2) {
//                std::cout << "Warning: OMP support seems to be disabled. " << "Terminating the program." << std::endl;
//                error = true;
//            }
//        }
//    }
//    if (error == true)
//        exit(-1);
//}
//
//int main() {
//
//    check_OMP_support();
//    //P5Q1();
//    //P5Q1a();
//
//    //for (int i = 0; i < 1; i++) {
//    //    P5Q1();
//    //}
//
//    //for (int i = 0; i < 1; i++) {
//    //    P5Q1a();
//    //}
//
//    //for (int i = 0; i < 1; i++) {
//    //    P5Q2();
//    //}
//
//    for (int i = 0; i < 1; i++) {
//        P5Q3();
//    }
//
//    return 0;
//}