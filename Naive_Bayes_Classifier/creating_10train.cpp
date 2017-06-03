#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
ifstream infile;
//infile.open("cleaned_data.txt");
string arr[]={"file1.txt","file2.txt","file3.txt","file4.txt","file5.txt","file6.txt","file7.txt","file8.txt","file9.txt","file10.txt"};
string arr2[]={"train1.txt","train2.txt","train3.txt","train4.txt","train5.txt","train6.txt","train7.txt","train8.txt","train9.txt","train10.txt"};
 int i=0;
ifstream fin1,fin2,fin;
ofstream fout;
//int aveg_pos=0;
//int aveg_neg=0;
while(i<10)
{
    //int pos_words=0;
    //int neg_words=0;
    int j=0;
 string word,file,file1;
    //string test_data=arr[i];
    file1=arr2[i];
    fout.open(file1.c_str());
    while(j<10)
    {
      if(j!=i)
     {
        file=arr[j];
        fin.open(file.c_str());
        while(!fin.eof())
        {
            getline(fin,word);
            fout<<word<<endl;

        }
        fin.close();
     }
     j++;
    }
    fout.close();
    i++;
}

}

