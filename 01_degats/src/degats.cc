#include "degats.h"

#include <algorithm>

namespace rde03 {

// Etape 1 — a ecrire.
//
// 1.1  Les bornes seules : kDegatsMax sous kDistanceMin, 0 a partir de
//      kDistanceMax, et la moitie entre les deux. C'est faux au milieu, et
//      c'est normal a ce stade.
// 1.2  La proportionnalite : normaliser, borner entre 0 et 1, descendre.
//      Les deux if de 1.1 disparaissent alors d'eux-memes.
float DegatsProportionnels(float distance) {
  // Variable temps normalisé
  float t = (distance - 0.25f)/(5- 0.25f);
  // le rendre bel et bien entre 0 et 1
  t = std::clamp(t, 0.0f, 1.0f);

  // en fait une pente descendante (via "1 - t") et la fait commencer a 25
  // (elle rend 0 lorsque le distance est egal a 5 en raison de la normalisation)
  float degats = 25 * (1 - t);

  return degats;
}

// Etape 2 — a ecrire.
//
// Memes bornes exactes, mais la courbe tient plus longtemps avant de
// s'effondrer. La moitie des degats tombe a 3,8 m, pas au milieu.
// Une seule operation de plus qu'en 1.2, et elle porte sur (1 - t).
float DegatsAmortis(float distance) {
  // Je pense qu'ici nous la faisons passer par une autre fonction
  // il sagirait d'une du type racine de x
  // Variable temps normalisé
  float t = (distance - 0.25f)/(5- 0.25f);
  // le rendre bel et bien entre 0 et 1
  t = std::clamp(t, 0.0f, 1.0f);

  // Pareil que DegatsProportionnelles sauf qu'on
  // utilise le sqrt pour le rendre amortie!
  float degats = 25 * sqrt(1 - t);

  return degats;

  return 0.f;
}

void TableauDegsAmortis() {
}


}  // namespace rde03
