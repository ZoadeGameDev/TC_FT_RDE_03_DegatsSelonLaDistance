#include <iostream>

#include "degats.h"
#include "print"

// On entre une distance par ligne, le programme affiche les degats.
// Pour passer d'un mode a l'autre : commenter une ligne, decommenter l'autre.
int main() {
  std::cout << "Distance en metres, une par ligne.\n"
            << "Ctrl+Z puis Entree pour terminer.\n\n";

  float distance = 0.f;
  while (std::cin >> distance) {
    //const float degats = rde03::DegatsProportionnels(distance);
    const float degats = rde03::DegatsAmortis(distance);

    float array[] = {0.25f, 1.40f, 2.60f, 3.80f, 5.00f};
    float answer[] = {25.0f, 21.8f, 17.8f, 12.6f, 0.0f};
    float tolerance = 0.5f;

    std::println("- Valeur rentree -");
    std::cout << distance << " m  ->  " << degats << " degats\n";
    std::println("---");
    std::println("- Tableau Degats Amortis-");
    for (float chiffre : array) {
      std::println("distance {} --> degats {}", chiffre, rde03::DegatsAmortis(chiffre));

      for (float reponse : answer) {
        if (reponse - tolerance <= rde03::DegatsAmortis(chiffre) && rde03::DegatsAmortis(chiffre) <= reponse + tolerance) {
          std::println("=> Juste");
        }
        }
      }

    }

  }
