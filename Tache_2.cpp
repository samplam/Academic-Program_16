/* This C++ program creates a list of 1000 odd integers. The list is then displayed in a table format with 10 elements per line. */

#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <algorithm>
#include <iterator>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    // Start performance measurement of the processing.
    auto debut = high_resolution_clock::now();

    // Create the list.
    auto vue = views::iota(0, 2000) | views::filter([](int i){ return i % 2 != 0; });
    vector<int> liste;
    ranges::copy(vue, back_inserter(liste));

    // Display the list.
    string ligne = "";
    string separateur(72, '-');
    string espacement = "";
    cout << separateur << endl;
    for (int i=0; i < liste.size(); i++)
    {
        if (liste[i] < 10)
        {
            espacement = "    |";
        }
        else if ((liste[i] >= 10) && (liste[i] < 100))
        {
            espacement = "   |";
        }
        else if ((liste[i] >= 100) && (liste[i] < 1000))
        {
            espacement = "  |";
        }
        else
        {
            espacement = " |";
        }
        ligne += " " + to_string(liste[i]) + espacement;
        if ((i+1)%10 == 0)
        {
            cout << "| " << ligne << endl;
            ligne = "";
            cout << separateur << endl;
        }
    }

    // End performance measurement and display the result.
    auto fin = high_resolution_clock::now();
    auto duree = duration_cast<duration<double>>(fin - debut);
    cout << "Temps de traitement : " << duree.count() << " secondes" << endl;

    return 0;
}