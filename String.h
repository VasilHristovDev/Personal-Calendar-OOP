#ifndef PERSONAL_CALENDAR_OOP_STRING_H
#define PERSONAL_CALENDAR_OOP_STRING_H
#include <cstring>
const int MAX_BUFFER = 4096;
class String {
private:
    char *text;
    unsigned int size;
    void deallocateMemory();
public:
    String(const char * text = "\0");
    String(const String & string);

    ~String();

    void setText(const char * text);
    bool contains(const String & other);

    unsigned int getSize() const;
    const char *getText() const;

    String &operator=(const String &other);
    String operator+(const String &other);
    char operator[](int index);
    friend std::istream & operator >> (std::istream & in, String & readable);
    friend std::ostream & operator << (std::ostream & out, String & readable);

};


String::String(const char *text) {
    this->size = strlen(text);
    this->text = new char [this->size + 1];
    strcpy(this->text,text);
}

void String::setText(const char * _text) {
    if(this->text)
        deallocateMemory();
    this->size = strlen(_text);
    this->text = new char [this->size + 1];
    strcpy(this->text, _text);
}

unsigned int String::getSize() const {
    return this->size;
}

const char *String::getText() const {
    return this->text;
}

String &String::operator=(const String &other) {
    if(this != &other)
    {
        this->setText(other.getText());
    }
    return *this;
}
String String::operator+(const String &other) {
    char * returnable = new char[this->size + other.getSize() + 1];
    strcpy(returnable, this->text);
    strcat(returnable,other.getText());
    return (String)returnable;
}

void String::deallocateMemory() {
    delete [] this->text;
}

String::~String() {
    deallocateMemory();
}

std::istream &operator>>(std::istream &in, String &readable) {
    char input [MAX_BUFFER];
    in.getline(input, MAX_BUFFER - 1);
    readable = (String) input;
    return in;
}

std::ostream &operator<<(std::ostream &out, String &readable) {
    out<<readable.getText();
    return out;
}

String::String(const String &string) {
    this->setText(string.getText());
}

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

char String::operator[](int index) {
    return this->text[index];
}


#endif //PERSONAL_CALENDAR_OOP_STRING_H
