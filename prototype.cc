#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <ctype.h>
using namespace std;
queue< pair<string,string> > globQ;

void getEnter(string str) //  separar por raices, $ conserva la palabra.// Quitar cout<<%%%%
{
  int bottom = 0;
  int top = 0;
  bool d = false; // particular case
  int origbottom = 0; // particular case, exp:  [[-s|s]] origbottom = 2, bottom =5;

  for(int i=1; i < str.length(); i++, d = false)
  {

    if(!globQ.empty() && str[i] == ' ' && globQ.back().first != "$"){
      pair<string,string> p;
      p.first = "$"; // space between words.
      cout<<p.first<<endl; //#######################3######COMMENT
      globQ.push(p);
    }
    if(str[i] != '[' && str[i] != ']' && str[i] != ' ' && str[i-1] == '[')
    {
      origbottom = i;
      bottom = i;
      top = i;
      while(top < str.length() && str[top] != ']')
      {
        if(str[top] == '|'){
          bottom = top + 1;
          d = true;
        }
        top++;
      }
      string str2 = str.substr(bottom, top - bottom);
      pair<string,string> p ;
      p.first = str2;
      if(d)
      {
        str2 = str.substr(origbottom -2 , (top - origbottom) +4 );
        p.second = str2;
      }
      else
      {
        str2 = str.substr(bottom -2 , (top -bottom) +4 );
        p.second = str2;
      }
      cout<<p.first<<" "<<p.second<<endl; //////######################3### COMMENT
      globQ.push(p);
      i = top;

    }
  }
}


queue< pair<string,string> > tmpQ;


string match(string str, int bottom, string final)
{
  string tmp = "";
  if(globQ.empty() && tmpQ.empty()){
    if(bottom < str.length())
    final.append(str.substr(bottom, str.length() - bottom)); /////////////////
    return final;
  }
  if(globQ.front().first == "$")
    globQ.pop();

  if(globQ.empty() && tmpQ.empty() ){
      if(bottom < str.length())
    final.append(str.substr(bottom, str.length() - bottom)); ///////////////// queue
      return final;
    }

  if(tmpQ.empty()){
    //cout<<"start enque"<<endl;
    //cout<<globQ.front().first<<endl;
    while( globQ.front().first != "$")
    {
      tmpQ.push(globQ.front());
      tmp.append(globQ.front().first);
      globQ.pop();
      if(globQ.empty())
        break;
    }
  }else{      /////// tmp queda vacio entonces hay que append de nuevo
    queue< pair<string,string> > tmp2Q;
    tmp2Q = tmpQ;
    while( !tmp2Q.empty()){
        tmp.append(tmp2Q.front().first);
        tmp2Q.pop();
      }
  }
  tmp[0] = tolower(tmp[0]); // Problem with upper, check it! .
  int pos = str.find(tmp);

  //cout<<"position "<<tmp<<": "<<pos<<endl;
  if(pos >= 0)
  {
    //cout<<tmp<<endl;
    //<<'"'<<pos<<" "<<bottom<<" "<<str[bottom]<<'"'<<
    final.append(str.substr(bottom, pos - bottom));     //////////////////
    while(!tmpQ.empty()){
      final.append(tmpQ.front().second);  ///////////////////
      tmpQ.pop();
    }
    final.append((match(str, pos + tmp.length(),"")) );
  }
  else{ // completar la cadena en el salto de linea
      if(bottom < str.length())
        final.append(str.substr(bottom, str.length() - bottom));  ///////////////
      return final;
    }

    return final;
}

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
