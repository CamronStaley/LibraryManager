#include "youth.h"
//----------------------------------------------------------------------------
//print
//displays the ammount instock, author, title, and then year. Will truncate
//title and author if they are too long
void Youth::print() const {
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(AVAILABILITY_OUTPUT_WIDTH) << instock
        << setw(AUTHOR_OUTPUT_WIDTH) << author.substr(0, AUTHOR_MAX_LENGTH)
        << setw(TITLE_OUTPUT_WIDTH) << title.substr(0, TITLE_MAX_WIDTH)
        << year << endl;
}

//----------------------------------------------------------------------------
//setData
//reads author, title, and year from istr and sets them accordingly. Also
//sets the type to Y and stock to 5, but could be set from file also.
void Youth::setData(istream& istr) {
    bookType = 'Y';
    instock = 5;

    istr.get();
    getline(istr, author, ',');

    istr.get();
    getline(istr, title, ',');

    istr >> year;
}
//----------------------------------------------------------------------------
//partialSetData
//reads book presentation author and title from istr and 
//sets data accordingly (called by transaction class)
void Youth::partialSetData(istream& istr) {
    bookType = 'Y';

    istr.get();
    getline(istr, title, ',');

    istr.get();
    getline(istr, author, ',');
}

//----------------------------------------------------------------------------
//operator==
//returns true only if the author, and title are the same for both books
bool Youth::operator==(const Book& other) const {
    const Youth& temp = static_cast<const Youth&>(other);//cast
    if (author != temp.author) { //check authors
        return false;
    }
    else if (title != temp.title) { //check titles
        return false;
    }
    else {
        return true;
    }
}

//----------------------------------------------------------------------------
//operator< 
//sorts by title and then author. If this title alphabetically comes before
//the other title then returns true. If titles are equal and this author
//alphabetically comes before the other author return true. Otherwise return
//false
bool Youth::operator<(const Book& other) const {
    const Youth& temp = static_cast<const Youth&>(other); //cast
    if (title < temp.title) { //check title
        return true;
    }
    else if (title == temp.title && author < temp.author) { //check author
        return true;
    }
    else {
        return false;
    }
}
//----------------------------------------------------------------------------
//printHeader
//displays the header for printing in library system
void Youth::printHeader() const {
    cout.setf(ios::left, ios::adjustfield);

    cout << "YOUTH BOOKS " << endl;
    cout << setw(AVAILABILITY_OUTPUT_WIDTH) << "AVAIL"
        << setw(AUTHOR_OUTPUT_WIDTH) << "AUTHOR"
        << setw(TITLE_OUTPUT_WIDTH) << "TITLE"
        << "YEAR" << endl;
}

//----------------------------------------------------------------------------
//printPartial
//prints the partial data that is set in the transaction class.
//only prints the title and author using setw
void Youth::printPartial() const {
    cout.setf(ios::left, ios::adjustfield);

    cout << setw(PTITLE_OUTPUT_WIDTH) << title.substr(0, PTITLE_MAX_WIDTH)
        << setw(PAUTHOR_OUTPUT_WIDTH) << author.substr(0, PAUTHOR_MAX_LENGTH)
        << year << endl;

}