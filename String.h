#ifndef PERSONAL_CALENDAR_OOP_STRING_H
#define PERSONAL_CALENDAR_OOP_STRING_H
#include <cstring>
///Max buffer constant that helps me when reading strings from the console
const int MAX_BUFFER = 4096;

///My own implementation of string consisting of two private properties : text and size
class String {
private:
    char *text;
    unsigned int size;
    ///Method that deletes the allocated memory for text
    void deallocateMemory();
public:
    ///Constructor with default param ( can be interpreted as both Default and Constructor with params)
    String(const char * text = "\0");
    ///Copy Constructor
    String(const String & string);

    ///Setter
    void setText(const char * text);

    ///A boolean method that checks whether a given string is contained inside a string
    bool contains(const String & other);

    ///Getters
    unsigned int getSize() const;
    const char *getText() const;

    ///Operator for assignment
    String &operator=(const String &other);

    ///Operator for string concatenation
    String operator+(const String &other);

    ///Operator for comparison between two strings
    bool operator == (const String & other);

    ///Indexing operator returning char standing on a given index
    char operator[](int index);

    ///Operators for input and output
    friend std::istream & operator >> (std::istream & in, String & readable);
    friend std::ostream & operator << (std::ostream & out, String & readable);

    ///Destructor
    ~String();
};

//constructor with single param
String::String(const char *text) {
    this->size = strlen(text);
    this->text = new char [this->size + 1];
    strcpy(this->text,text);
}
//setter for the text
void String::setText(const char * _text) {
    if(this->text)
        deallocateMemory();
    this->size = strlen(_text);
    this->text = new char [this->size + 1];
    strcpy(this->text, _text);
}
//getter for the size of the string
unsigned int String::getSize() const {
    return this->size;
}
//getter for the text
const char *String::getText() const {
    return this->text;
}

//operator for assignment ( good practise when using dynamic memory )
String &String::operator=(const String &other) {
    if(this != &other)
    {
        this->setText(other.getText());
    }
    return *this;
}
//operator for string concatenation
String String::operator+(const String &other) {
    char * returnable = new char[this->size + other.getSize() + 1];
    strcpy(returnable, this->text);
    strcat(returnable,other.getText());
    return (String)returnable;
}
//method that deletes the memory of the text
void String::deallocateMemory() {
    delete [] this->text;
}
//destructor
String::~String() {
    deallocateMemory();
}
//operator for input
std::istream &operator>>(std::istream &in, String &readable) {
    //used cin.getline() with max buffer const
    char input [MAX_BUFFER];
    in.getline(input, MAX_BUFFER - 1);
    readable = (String) input;
    return in;
}
//output operator
std::ostream &operator<<(std::ostream &out, String &readable) {
    out<<readable.getText();
    return out;
}
//copy constructor
String::String(const String &string) {
    this->setText(string.getText());
}
//procedural way to check if a string is contained inside another string
bool String::contains(const String &other) {
    unsigned int otherSize  = other.getSize();
    if(otherSize > this->size)
        return false;
    const char * otherText = other.getText();
    for (int i = 0; i < this->size; i++){
        int j = 0;
        // If the first characters match
        if(this->text[i] == otherText[j]){
            int k = i;
            while (this->text[i] == otherText[j] && j < otherSize)
            {
                j++;
                i++;
            }
            if (j == otherSize)
            {
                return true;
            }
            else
            {
                i = k;
            }
        }
    }
    return false;
}
//operator for indexation
char String::operator[](int index) {
    return this->text[index];
}
//an operator that checks whether two strings are the same
bool String::operator==(const String &other) {
    if(this->size != other.getSize())
        return false;
    int counter = 0;
    for (int i = 0; i < this->size ; ++i) {
        if(this->text[i] == other.getText()[i])
            counter++;
    }
    return counter == this->size;
}


#endif //PERSONAL_CALENDAR_OOP_STRING_H
