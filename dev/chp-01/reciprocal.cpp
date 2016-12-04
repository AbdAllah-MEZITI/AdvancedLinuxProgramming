#include <cassert>
#include "reciprocal.hpp"

double reciprocal (int i) {
  // i doit etre différent de zéro
  assert (i != 0);
  return 1.0/i;
}
