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
    String();
    String(const char *text);
    String(const String & string);

    ~String();

    void setText(const char * text);

    unsigned int getSize() const;
    const char *getText() const;

    String &operator=(const String &other);
    String &operator+(const String &other);

    friend std::istream & operator >> (std::istream & in, String & readable);
    friend std::ostream & operator << (std::ostream & out, String & readable);

};

String::String() {
    this->text = new char [1];
    this->size = 0;
    this->text[0] = '\0';
}

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

String &String::operator+(const String &other) {
    String temp = *this;
    deallocateMemory();
    this->text = new char [this->size + other.getSize() + 1];
    strcpy(this->text, temp.getText());
    strcat(this->text,other.getText());

    return *this;
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


#endif //PERSONAL_CALENDAR_OOP_STRING_H
