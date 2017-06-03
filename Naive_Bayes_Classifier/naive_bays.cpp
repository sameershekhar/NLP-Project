#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include<math.h>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

int main()
{
string arr1[]={"test1.txt","test2.txt","test3.txt","test4.txt","test5.txt","test6.txt","test7.txt","test8.txt","test9.txt","test10.txt"};
string arr2[]={"train1.txt","train2.txt","train3.txt","train4.txt","train5.txt","train6.txt","train7.txt","train8.txt","train9.txt","train10.txt"};
double total_uniq_words;
int i=0;
ifstream fin1,fin;
ofstream fout5("Final_Result.txt");
double aveg_pos=0;
double aveg_neg=0;
int pos_words;
int neg_words;
string word,file;
while(i<10)
{
    total_uniq_words=0;
     pos_words=0;
     neg_words=0;

 file=arr2[i];

fin.open(file.c_str());

string line;
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
         if(freq1.find(word) ==freq1.end())
         {
             freq1[word] = 1;
         }
         else
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



for (map<string,int>::iterator it=freq1.begin(); it!=freq1.end(); ++it)
    {

        if(it->first==""||it->first=="+")
            pos_words=pos_words-it->second;
       if(it->second!=1)
       {
        //fout1<< it->first << "  " << it->second << '\n';
        total_uniq_words++;
        pos_words=pos_words+it->second;
       }
       //cout<<it->first<<" "<<it->second<<endl;


    }
for (map<string,int>::iterator it=freq2.begin(); it!=freq2.end(); ++it)

    {
        if(it->first==""||it->first=="-")
          neg_words=neg_words-it->second;
         //freq2.erase(it->first);
        if(it->second!=1)
        {
        total_uniq_words++;
        neg_words=neg_words+it->second;
    }


    }

ifstream fin2;
//cout<<"i="<<i;
string file1;
file1=arr1[i];
fin2.open(file1.c_str());

string word2;
double count_1=0;
double count_0=0;
while(!fin2.eof())
{
    double p=0;
    double n=0;
    getline(fin2,word2);
    int pr_nr=int(word2[0]);
  char str[1024];
strncpy(str, word2.c_str(), sizeof(str));
str[sizeof(str)-1] = 0;



     char * pch;
 // printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ");
  map<string,int>::iterator itr1,itr2;
  while (pch != NULL)
  {

    pch = strtok (NULL, " ");

    if(pch!=NULL)
      {
          itr1=freq1.find(pch);
          itr2=freq2.find(pch);

       if(itr1!=freq1.end())
        {
            double x1=(itr1->second + 1);
            double x2=(pos_words+total_uniq_words);
            //cout<<x1<<" "<<x2<<endl;
            double x3=log(x1/x2);
            p=p+x3;
            //cout<<setprecision(10)<<p;

        }
        else
        {
            double x1=(0 + 1);
            double x2=(pos_words+total_uniq_words);
            //cout<<x1<<" "<<x2<<endl;
            double x3=log2(x1/x2);
            p=p+x3;

        }

        if(itr2!=freq2.end())
        {
        double y1=(itr2->second+1);
        double y2=(neg_words+total_uniq_words);
        double y3=log(y1/y2);
         n=n+y3;
        }
        else
        {
            double y1=(0+1);
        double y2=(neg_words+total_uniq_words);
        double y3=log(y1/y2);
         n=n+y3;

        }
}

}
   //cout<<endl;


    p=p+log(0.5);
    n=n+log(0.5);

    if(p>n&&pr_nr==43)
        {
            count_1++;
           fout5<<"1"<<endl;
        }
    else if(n>p&&pr_nr==45)
       {
           count_1++;
           fout5<<"1"<<endl;
       }
        else
            {
                count_0++;
                fout5<<"0"<<endl;
            }



}
double s1=(count_1/60);
aveg_pos=aveg_pos+s1;
double s2=(count_0/60);
//aveg_neg=aveg_neg+s2;
fout5<<"Correct Prediction"<<"="<<count_1<<" "<<"Wrong Prediction"<<"="<<count_0<<endl;
fout5<<"Accuracy "<<s1<<endl;

//cout<<count_1<<" "<<count_0<<endl;
fout5<<"****************************************"<<endl;
fin2.close();
  i++;

}


aveg_pos=aveg_pos/10;
//aveg_neg=aveg_neg/10;

fout5<<"Overall Accuracy "<<"="<<aveg_pos<<endl;
fout5.close();
cout<<aveg_pos<<" "<<aveg_neg;

}






