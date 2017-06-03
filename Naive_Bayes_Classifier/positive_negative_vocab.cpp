#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;
int main()
{

    ifstream fin;
    fin.open("cleaned_data.txt");
    ofstream fout1,fout2;
    fout1.open("positive_vocab.txt");
    fout2.open("negative_vocab.txt");
    string line;
    string word;
    map<string,int> freq1,freq2;

   if(fin.is_open())
    {
        while(getline(fin,line))
        {
          int j=0;
        if(int(line[j])==43)
        {

           for ( std::string::iterator it=line.begin(); it!=line.end(); ++it)
          {
        if(*it == ' ')
         {
         if(freq1.find(word) ==freq1.end()) //First time the word is seen
         {
             freq1[word] = 1;
         }
         else //The word has been seen before
         {
             freq1[word]++;
         }
         word = "";
         }
         else
             word.push_back(*it);

          }
           }
else if((int(line[j])==45)){

for ( std::string::iterator it=line.begin(); it!=line.end(); ++it)
{
    if(*it == ' ')
    {
         if(freq2.find(word) ==freq2.end()) //First time the word is seen
         {
             freq2[word] = 1;
         }
         else //The word has been seen before
         {
             freq2[word]++;
         }
         word = "";
    }
    else
    {
         word.push_back(*it);
    }
}
}
}
    fin.close();
    }

    ifstream fin1;
  string word1;
  fin1.open("stopwords.txt");
  while(!fin1.eof())
  {
   getline(fin1,word1);
      freq1.erase(word1);
      freq2.erase(word1);

  }

for (std::map<string,int>::iterator it=freq1.begin(); it!=freq1.end(); ++it)
    {
        fout1<< it->first << "  " << it->second << '\n';

    }
for (std::map<string,int>::iterator it=freq2.begin(); it!=freq2.end(); ++it)
    {
        fout2<< it->first << "  " << it->second << '\n';

    }



}

