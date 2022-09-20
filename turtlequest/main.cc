#include <iostream>
using namespace std;
#include <cstdlib>
#include <time.h>

#include "Control.h"


//main function calls launch in control to run code
int main()
{
  srand( (unsigned)time( NULL ) );
  Control control;
  control.launch();

  return 0;
}
