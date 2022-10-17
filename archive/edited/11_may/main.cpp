#include <iostream>
using namespace std;
#include "similarity.h"  // contains declaration


int main (int argc, char *argv[]) {

  int score;
  try {
    score = checksimilarity(argv[1], argv[2]);
  }
  catch(exceptions e)
  {
    e.msg();
  }

     cout << score << endl;

}



