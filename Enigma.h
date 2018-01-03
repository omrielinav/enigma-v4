#ifndef ENIGMA_H
#define ENIGMA_H
#include "scrambler.h"

class Enigma
{
    public:
        Enigma();
        Enigma(scrambler* s1, scrambler* s2, scrambler* s3)
        {
            this->s1= s1;
            this->s2= s2;
            this->s3=s3;
        }
        char Encrypt(char ch)
        {
            this->s1->input(ch);
            this->s2->input(this->s1->output());
            this->s3->input(this->s2->output());
            return this->s3->output();
        }
    protected:

    private:
        scrambler* s1;
        scrambler* s2;
        scrambler* s3;
};

#endif // ENIGMA_H
