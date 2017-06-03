#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
ifstream infile;
infile.open("cleaned_data.txt");
string arr[]={"test1.txt","test2.txt","test3.txt","test4.txt","test5.txt","test6.txt","test7.txt","test8.txt","test9.txt","test10.txt"};
//string arr2[]={"train1.txt","train2.txt","train3.txt","train4.txt","train5.txt","train6.txt","train7.txt","train8.txt","train9.txt","train10.txt"};
 int win_size=60;
    int row_counter = 0;
    int i=0;
    ofstream ofile;

 string val;
  string file=arr[i];
   ofile.open(file.c_str());

    while(!infile.eof())
    {
        getline(infile,val);
        ofile <<val<<endl;
        row_counter++;

            if (row_counter == win_size)
            {
                i++;
               row_counter = 0;
               ofile.close();
               // generate new ofile_name
               file=arr[i];
               ofile.open(file.c_str()); // you might change the nMode parameter if necessary
            }
    }

infile.close();
    ofile.close();



return 0;
}

