/*************************************************************************\
*                  Copyright (C) Jimmy Pulido, 2016.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU Lesser General Public License as published   *
* by the Free Software Foundation, either version 3 or (at your option)   *
* any later version. This program is distributed without any warranty.    *
* See the files COPYING.lgpl-v3 and COPYING.gpl-v3 for details.           *
\*************************************************************************/


/* sup.cc
*/

#include "libraries.h" //## local library
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <ctype.h>

using namespace std;

int main(int argc, char const *argv[]) {
  string line;
  getline(cin,line);

  cout<<sup(line)<<endl;


  return 0;
}
