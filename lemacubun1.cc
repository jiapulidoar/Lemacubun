/*************************************************************************\
*                  Copyright (C) Jimmy Pulido, 2016.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU Lesser General Public License as published   *
* by the Free Software Foundation, either version 3 or (at your option)   *
* any later version. This program is distributed without any warranty.    *
* See the files COPYING.lgpl-v3 and COPYING.gpl-v3 for details.           *
\*************************************************************************/


/* lemacubun1.cc
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
  ifstream input1(argv[1]);
  ifstream input2(argv[2]);
  string line;
  string final;

  while(getline(input1,line)){
    getEnter(line);
    {
      if(globQ.back().first != "$"){
        pair<string,string> p;
        p.first = "$"; // space between word
        cout<<"$"<<endl;
        globQ.push(p);
      }
    }
//////////////////////////////////////////////////////
  }

  while(getline(input2,line)){
    final = "";
    if(line == "")
        continue;

       if(isupper(line[0]))
         final.append("\n# ");
      if(!globQ.empty() || !tmpQ.empty()){
        final.append(match(line,0,""));
        //final.append("\n");
        cout<<final;
    }
    else{

        final.append(line);
        final.append("\n");
        cout<<final;
      }


    }


  return 0;
}
