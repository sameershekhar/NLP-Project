#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>


using namespace std;
int main()
{
    string word;
    map<string,int> freq;
    ifstream myfile;
    string line;
    myfile.open("cleaned_data.txt");
   if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {

for ( std::string::iterator it=line.begin(); it!=line.end(); ++it)
{
   // if((*it == ' '&& *it!='-')||(*it == ' '&& *it!='+'))
   if(*it == ' ')
    {
         if(freq.find(word) ==freq.end())
         {
             freq[word] = 1;
         }
         else 
         {
             freq[word]++;
         }
         word = "";
    }
    else
    {
         word.push_back(*it);
    }
}



     // cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  ofstream fout1,fout2,fout3;
  fout1.open("frequency.txt");
  fout2.open("freq_without1.txt");
  //fout3.open("data_without_stopword.txt");
  ifstream fin1;
  string word1;
  fin1.open("stopwords.txt");
  while(!fin1.eof())
  {
   getline(fin1,word1);
      freq.erase(word1);

  }
 // for (std::map<string,int>::iterator it=freq.begin(); it!=freq.end(); ++it)

  freq.erase("-");
  freq.erase("+");
  freq.erase("");

  for (std::map<string,int>::iterator it=freq.begin(); it!=freq.end(); ++it)
    {

        fout1<< it->first << "  " << it->second << '\n';
        if(it->second!=1)
        {
            fout2<< it->first << "  " << it->second << '\n';
        }
    }
    //std::cout << it->first << "  " << it->second << '\n';


  return 0;
}


