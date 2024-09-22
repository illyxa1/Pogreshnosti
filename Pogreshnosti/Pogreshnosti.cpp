// Pogreshnosti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define _USE_MATH_DEFINES // for C
#include <math.h>

//-------------------------------------------------------------------------------------------
double Student[10] = {0, 0, 12.7, 4.3, 2.8, 2.6, 2.5, 2.4, 2.3, 2.3};
double Betta[14] = {0, 0, 0, 1.3, 0.72, 0.51, 0.4, 0.33, 0.29, 0.25, 0.23, 0.21, 0.19};
double Upn[11] = {0, 0, 0, 0.94, 0.76, 0.64, 0, 0.51, 0, 0, 0.41};
double Vpn[13] = {0, 0, 0, 1.15, 1.46, 1.67, 1.94, 2.03, 2.11, 2.18, 2.23, 2.29};
//-------------------------------------------------------------------------------------------
void print(std::string to_print)
{
    std::cout << ">> " << to_print;

}
//-------------------------------------------------------------------------------------------
void input(std::string to_input_frase, int& save_to)
{
    print(to_input_frase);
    std::cin >> save_to;
}
//-------------------------------------------------------------------------------------------
void input(std::string to_input_frase, double &save_to)
{
    print(to_input_frase);
    std::cin >> save_to;
}
//-------------------------------------------------------------------------------------------
void get_max(double a, double b, double &max)
{
    max = a;
    if (a > b)
        return;
    max = b;
}
//-------------------------------------------------------------------------------------------
int main()
{
    // std::cout << "Привет, Мир!\n";
    int count_of_results;
    double *array_of_results;
    int i;
    double r;
    double min, max;
    double midle = 0.0;
    double sko = 0.0;
    double sko_mid;
    double rp_by_r;
    double rp_by_sko;
    double instr_mis = 1;
    double full_misstake; 
    double ch_miss;

    input("input instumental mistake (tetta): ", instr_mis);
    input("input count of results: ", count_of_results);
    std::cout << "\ncount of results: " << count_of_results << ";";

    array_of_results = new double[count_of_results];
    //array_of_results = new double[5];
    for (i=0; i < count_of_results; i++)
    {
        std::cout << "\n" << i + 1 << " ";
        input("input result: ", array_of_results[i]);
    }
    /*array_of_results[0] = 99.0;
    array_of_results[1] = 99.0;
    array_of_results[2] = 100.0;
    array_of_results[3] = 101.0;
    array_of_results[4] = 102.0;*/

    print("results: \n");

    for (i = 0; i < count_of_results; i++)
        std::cout << "\n" << "result " << i + 1 << ": " << array_of_results[i] << ";";

    // searching for minimum and maximum
    min = array_of_results[0];
    for (i=1; i < count_of_results; i++)
        if(array_of_results[i] < min)
            min = array_of_results[i];

    max = array_of_results[0];
    for (i=1; i < count_of_results; i++)
        if(array_of_results[i] > max)
            max = array_of_results[i];

    // counting razmah
    r = max - min;

    std::cout << "\n";
    print ("razmah (R): ");
    std::cout << r << "\n";

    // count midle count
    for (i=0; i < count_of_results; i++)
        midle += array_of_results[i];

    midle /= count_of_results;
    print ("midle (nadcherknutoye value): ");
    std::cout << midle << "\n";

    // count sko;
    for (i=0; i < count_of_results; i++)
        sko += (array_of_results[i] - midle)*(array_of_results[i] - midle);
    sko = sqrt(sko / (count_of_results - 1));

    print ("sko (S): ");
    std::cout << sko << "\n";

    // checking on misses
    print("searching for misstakes: \n");

    for (i=1; i < count_of_results; i++)
    {
        std::cout << "checking " << array_of_results[i - 1] << ": ";
        if ((fabs(array_of_results[i - 1] - array_of_results[i]) < Upn[count_of_results] * r))
            std::cout << "|" << array_of_results[i - 1] << " - " << array_of_results[i] << "|" << " < " << Upn[count_of_results] << " * " << r << ": ok;\n";

        else
            std::cout << "MISSTAKE\n";
    }
    
    print("searching for misstakes by sko: \n");
    for (i=0; i < count_of_results; i++)
    {
        std::cout << "checking " << array_of_results[i] << ": ";
        if ((fabs(array_of_results[i] - midle) < Vpn[count_of_results] * sko))
            std::cout << "|" << array_of_results[i] << "-" <<  midle << "|" << " < " << Vpn[count_of_results] << " * " << sko << ": ok;\n";

        else
            std::cout << "MISSTAKE\n";
    }

    // midle sko
    sko_mid = sko / sqrt(count_of_results);
    std::cout << ">> sko mid(S and litle nadcherknutoye value(Sv)): " << sko_mid << "\n";

    // counting random pogreshnost
    rp_by_r = r * Betta[count_of_results];
    rp_by_sko = Student[count_of_results] * sko_mid;
    get_max(rp_by_r, rp_by_sko, ch_miss);
    std::cout << ">> random mistake by razmah (delta value = Bpn*R): " << rp_by_r << "\n";
    std::cout << ">> random mistake by SKO (delta value = tpn * Sv): " << rp_by_sko << "\n";

    // counting full misstake
    full_misstake = sqrt(ch_miss*ch_miss + instr_mis*instr_mis);

    std::cout << ">> full mistake(like russian b): " << full_misstake << "\n";
    std::cout << "\n===================-ANSVER-======================================";
    std::cout << "\n" << midle << " +- " << full_misstake << ", " << full_misstake/midle * 100 << "%";

    delete [] array_of_results;
}
//-------------------------------------------------------------------------------------------