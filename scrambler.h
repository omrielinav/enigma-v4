#ifndef SCRAMBLER_H
#define SCRAMBLER_H
#include <map>
using namespace std;

class scrambler
{
    private:
        char inputchar;
        char outputchar;
        /*pair<char, char> dict[26] =
        {make_pair('a','e'),
        make_pair('b','k'),
        make_pair('c','m'),
        make_pair('d','f'),
        make_pair('e','l'),
        make_pair('f','g'),
        make_pair('g','d'),
        make_pair('h','q'),
        make_pair('i','v'),
        make_pair('j','z'),
        make_pair('k','n'),
        make_pair('m','t'),
        make_pair('l','o'),
        make_pair('n','w'),
        make_pair('o','y'),
        make_pair('p','h'),
        make_pair('q','x'),
        make_pair('r','u'),
        make_pair('s','s'),
        make_pair('t','p'),
        make_pair('u','a'),
        make_pair('v','i'),
        make_pair('w','b'),
        make_pair('x','r'),
        make_pair('y','c'),
        make_pair('z','j'),
        };*/
        char arr1[26]= {'a','b','c','d','e','f','g','h','i','j','k','m','l','n','o','p','q','r','s','t','u','v','w','x','y','z'};

        /*keep in mind that the values in arr2 are applied to the opposite value in arr1 ie a corresponds with e and b does so with k arr1[i]=arr2[25-i]*/
        char arr2[26]= {'j','c','r','b','i','a','p','s','u','x','h','y','w','o','t','n','z','v','q','d','g','l','f','m','k','e'};
        int counterinput=0;
    public:
        input(char ch)
        {
            this->inputchar=ch;
        }
        char output()
        {
            encrypt();
            return this->outputchar;
        }
        encrypt()
        {
            int value= int(this->inputchar);
            bool isletter=false;
          if(value>=97&&value<=122)
                isletter=true;
          else if(value>=65&&value<=90)
           {
               value+=32;
               isletter=true;
           }
           if(isletter)
           {
               value-=97;
               this->outputchar=this->arr2[25-value];
               char temp=arr2[25];
               char arrtemp[26];
               for(int i=0; i<25; i++)
               {
                   arrtemp[i+1]=arr2[i];
               }
               arrtemp[0]=temp;
               this->counterinput++;
               for(int i=0; i<26; i++)
               {
                   arr2[i]=arrtemp[i];
               }
           }



        }


};

#endif // SCRAMBLER_H
