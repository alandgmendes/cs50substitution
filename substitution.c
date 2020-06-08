//This program cyphers a text. You serve him an cypher key, a sequence of 26 different letters
//This must be done as you launch the program, via command line.
//If key is valid, the program asks for your cyphering text. It will preserve it's letter-case.
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
//Necessary libs

string inp;
string validated;
int returner = 0;

string upstring(string dstr)//makes a string go upper case.
{
    char strlow[strlen(dstr)];
    for (int i = 0; i < strlen(dstr); i++)
    {
        strlow[i] = toupper(dstr[i]);
    }
    dstr = strlow;
    return dstr;
}

string dstring(string upstr)// makes a string go lower case.
{
    char strup[strlen(upstr)];
    for (int i = 0; i < strlen(upstr); i++)
    {
        strup[i] = tolower(upstr[i]);
    }
    upstr = strup;
    return upstr;
}

int check(string test)//tests argv[1] for it size. if it's different from 26, main returns 1
{                     //and program ends
    if (strlen(test) != 26)
    {
        returner = 1;
    }

    return returner;
}

string confcyph(char cyph[])//checks if the string is valid due to non-repeating chars
{
    int aux = 0;
    for (int i = 0; i < 26; i++)
    {
        for (int j = i+1; j < 27; j++)
        {
            if (cyph[i] == cyph[j])
            {
                printf("Invalid key, it has not 26 exactly different letters.\n");
                return "invalid";
            }
            //printf("%i\n", (int)cyph[i]);
            if ((int)(cyph[i] < 65) || (((int)(cyph[i]) > 90) && ((int)cyph[i] < 97)) || cyph[i] > 122)
            {
                printf("Invalid key, it has not 26 exactly different letters.\n");
                return "invalid";
            }
        }
    }
    return "valid";
}

string translate(string cyph, string test)
{
    string finaltrans = NULL;
    string minalph = "abcdefghijklmnopqrstuvwxyz";
    string maxalph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int len = strlen(test);
    //printf("%i\n", len);
    char transl[len];
    for (int i = 0; i < (int)(strlen(test)); i++)
    {
        transl[i] = test[i];
        for (int j = 0; j < (int)(strlen(cyph)); j++)
        {
            if (test[i] == minalph[j])
            {
                transl[i] = tolower(cyph[j]);
            }
            if (test[i] == maxalph[j])
            {
                transl[i] = toupper(cyph[j]);
            }
        }
    }
    finaltrans = transl;
    //printf("%i\n", (int)strlen(transl));
    return finaltrans;
}

int main(int argc, string argv[])
{
    int sizecyph = strlen(argv[1]);
    char cypher[26];
    if (argc == 2)//checks command-line number of arguments
    {
        if (check(argv[1]) == 1)
        {
            printf("Wrong size of cypher. \n");
            return 1;
        } else {
        validated = confcyph(argv[1]);
        if (strcmp(validated, "invalid") == 0){
            return 1;
        }
        string plaintext = get_string("text to translate: ");
        string finaltest = translate(argv[1], plaintext);
        //printf("%i\n", (int)(strlen(finaltest)));
        printf("cipher text: %s", finaltest);
        //printf("%s\n", plaintext);
        }
    }
    else
    {
        printf("Wrong number of arguments. This function requires exactly one string,\n");
        printf("with 26 different letters\n");//error message related to wrong number of args
        return 1;
    }
    //printf("returner is %i\n", returner);
    return returner;
}
