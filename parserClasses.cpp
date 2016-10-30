//Use only the following libraries:
#include "parserClasses.h"
#include <string>
#include <iostream> //REMOVE



//****TokenList class function definitions******
//           function implementations for append have been provided and do not need to be modified


//Creates a new token for the string input, str
//Appends this new token to the TokenList
//On return from the function, it will be the last token in the list
void TokenList::append(const string &str) {
	Token *token = new Token(str);
	append(token);
}

//Appends the token to the TokenList if not null
//On return from the function, it will be the last token in the list
void TokenList::append(Token *token) {
	if (!head) {
		head = token;
		tail = token;
	}
	else {
		tail->setNext(token);
		token->setPrev(tail);
		tail = token;
	}
}


//Complete the implementation of the following member functions:
//****Tokenizer class function definitions******

//Computes a new tokenLength for the next token
//Modifies: size_t tokenLength, and bool complete
//(Optionally): may modify offset
//Does NOT modify any other member variable of Tokenizer
void Tokenizer::prepareNextToken()
{
    if (str->at(tokenLength) == ';')
    {
        offset = tokenLength;
        tokenLength++;
        complete = true;
    }
    else if (!complete)
    {
        int found[28], lowestFound = 4294967294;

        offset = tokenLength;

        found[0] = str->substr(offset, (str->length() - offset)).find_first_of(" ");
        found[1] = str->substr(offset, (str->length() - offset)).find_first_of("\t");
        found[2] = str->substr(offset, (str->length() - offset)).find_first_of(";");
        found[3] = str->substr(offset, (str->length() - offset)).find_first_of('**');
        found[4] = str->substr(offset, (str->length() - offset)).find_first_of('abs');
        found[5] = str->substr(offset, (str->length() - offset)).find_first_of('*');
        found[6] = str->substr(offset, (str->length() - offset)).find_first_of('/');
        found[7] = str->substr(offset, (str->length() - offset)).find_first_of('mod');
        found[8] = str->substr(offset, (str->length() - offset)).find_first_of('rem');
        found[9] = str->substr(offset, (str->length() - offset)).find_first_of('&');
        found[10] = str->substr(offset, (str->length() - offset)).find_first_of('sll');
        found[11] = str->substr(offset, (str->length() - offset)).find_first_of('srl');
        found[12] = str->substr(offset, (str->length() - offset)).find_first_of('sla');
        found[13] = str->substr(offset, (str->length() - offset)).find_first_of('sra');
        found[14] = str->substr(offset, (str->length() - offset)).find_first_of('rol');
        found[15] = str->substr(offset, (str->length() - offset)).find_first_of('ror');
        found[16] = str->substr(offset, (str->length() - offset)).find_first_of('=');
        found[17] = str->substr(offset, (str->length() - offset)).find_first_of('/=');
        found[18] = str->substr(offset, (str->length() - offset)).find_first_of('<');
        found[19] = str->substr(offset, (str->length() - offset)).find_first_of('<=');
        found[20] = str->substr(offset, (str->length() - offset)).find_first_of('>');
        found[21] = str->substr(offset, (str->length() - offset)).find_first_of('>=');
        found[22] = str->substr(offset, (str->length() - offset)).find_first_of('and');
        found[23] = str->substr(offset, (str->length() - offset)).find_first_of('or');
        found[24] = str->substr(offset, (str->length() - offset)).find_first_of('nand');
        found[25] = str->substr(offset, (str->length() - offset)).find_first_of('nor');
        found[26] = str->substr(offset, (str->length() - offset)).find_first_of('xor');
        found[27] = str->substr(offset, (str->length() - offset)).find_first_of('xnor');
        for (int i = 0; i <= 27; i++) if ((found[i] <= lowestFound)&&(found[i] >= 0)&&(found[i] != 4294967295)) found[i] == lowestFound;

        cout << offset << " " << lowestFound;

        //while (str->substr(offset,1) == " " || str->substr(offset,1) == "\t") offset++;  //Trims white spaces or tabs
        tokenLength = lowestFound;
/*
        if (   str->substr(offset, (tokenLength - offset)).find_first_of("():") != 4294967295)
        {
            tokenLength = str->find_first_of("():", offset+1);
            if ((tokenLength == 4294967295) || (str->find_first_of("():", offset) == offset)) tokenLength = offset + 1;
        }




        if (str->substr(offset, (tokenLength - offset)).find_first_of("(") != 4294967295)
        {
            tokenLength = str->find_first_of("(", offset+1);
            if (tokenLength == 4294967295) tokenLength = offset + 1;
        }

        else if ((str->substr(offset, (tokenLength - offset)).find_first_of(")") != 4294967295)
                && str->substr(offset, (tokenLength - offset)).length() != 1) tokenLength = str->find_first_of(")", offset);

        if ((str->substr(offset, (tokenLength - offset)).find_first_of(":") != 4294967295)
            && (str->substr(offset, (tokenLength - offset)).length() != 1))
        {
            tokenLength = str->find_first_of(":", offset) + 1;
        }
        */


    }
    cout << tokenLength;

    //Check for end of string
    if (tokenLength == 4294967295)
    {
        tokenLength = str->find(str->at(str->length() - 1),0);
        complete = true;
    }





}

//Sets the current string to be tokenized
//Resets all Tokenizer state variables
//Calls Tokenizer::prepareNextToken() as the last statement before returning.
void Tokenizer::setString(string *line)
{
    str = line;
    offset = 0;
    tokenLength = 0;
    complete = false;
    trimWhiteSpace();

    /*
    if (!(str->find_first_not_of(" ") == 4294967295))
    {

        while (!complete)
        {
            prepareNextToken();
            if (complete) cout << "[" << str->substr(offset, (tokenLength - offset + 1)) << "]";
            else cout << "[" << str->substr(offset, (tokenLength - offset)) << "] ";


        }
        if (str->substr(tokenLength,1) == ";") cout << "END";
        cout << endl;
    }
    */
}

void Tokenizer::trimWhiteSpace ()
{
    int trimStart = 0, trimEnd = 0;
    trimStart = str->find(" ");
    str->replace(trimStart," ");

}

//Returns the next token. Hint: consider the substr function
//Updates the tokenizer state
//Updates offset, resets tokenLength, updates processingABC member variables
//Calls Tokenizer::prepareNextToken() as the last statement before returning.
string Tokenizer::getNextToken()
{/*Fill in implementation */ }

bool Tokenizer::isComplete() const
{
    return complete;
}

//****Challenge Task Functions******

//Removes the token from the linked list if it is not null
//Deletes the token
//On return from function, head, tail and the prev and next Tokens (in relation to the provided token) may be modified.
void TokenList::deleteToken(Token *token) {/*Fill in implementation */}

//Removes all comments from the tokenList including the -- marker
//Returns the number of comments removed
int removeComments(TokenList &tokenList) {/*Fill in implementation */ }


